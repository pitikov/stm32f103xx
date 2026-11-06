# -------------------- Определение используемого binutils ------------------------

BINUTILS					:= arm-none-eabi

CC							:= $(BINUTILS)-gcc
LD							:= $(BINUTILS)-gcc
OBJDUMP						:= $(BINUTILS)-objdump
OBJCOPY						:= $(BINUTILS)-objcopy

# ------------------- Используемые Linux комманды ------------------------

RM							:= rm -Rf
ECHO						:= @echo
MKDIR						:= mkdir -p -m 0764

# ------------------- Каталоги проекта ---------------------------------

SRC_DIR						:= ./src
CMSIS_DIR					:= ./CMSIS
CMSIS_INC_DIR				:= $(CMSIS_DIR)/Include
DEVICE_DIR					:= ./STM32F103xx
DEVICE_INC_DIR				:= $(DEVICE_DIR)/Include
DEVICE_SRC_DIR				:= $(DEVICE_INC_DIR:Include=Source)
DEVICE_CONF_DIR				:= $(DEVICE_INC_DIR:Include=Config)

# ------------------- Каталоги сборки ---------------------------------
BUILD_DIR					:= ./build
DEST_DIR					:= $(BUILD_DIR)/target
OBJ_DIR						:= $(BUILD_DIR)/.obj
MAP_DIR						:= $(BUILD_DIR)/map

# ------------------- Именование целей сборки -------------------------

TARGET_ELF					:= $(DEST_DIR)/$(PROJECT_NAME).elf
TARGET_BIN					:= $(TARGET_ELF:.elf=.bin)
OBJECTS						+= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c))
OBJECTS						+= $(patsubst $(DEVICE_SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(wildcard $(DEVICE_SRC_DIR)/*.c))

TARGET_MAP					:= $(MAP_DIR)/$(PROJECT_NAME).map

# -------------------- Флаги архитектуры -------------------------------
ARCH_FLAGS					+= -mcpu=cortex-m3
ARCH_FLAGS					+= -march=armv7-m
ARCH_FLAGS					+= -mthumb
ARCH_FLAGS					+= -mlittle-endian
ARCH_FLAGS					+= -msoft-float
ARCH_FLAGS					+= -mfp16-format=ieee
ARCH_FLAGS					+= -mfix-cortex-m3-ldrd
ARCH_FLAGS					+= -masm-syntax-unified

# -------------------- Флаги компилятора -------------------------------
C_FLAGS						+= -MD
C_FLAGS						+= -Wall
C_FLAGS						+= -Wpedantic
C_FLAGS						+= -std=c17

ifeq ($(DEBUG_BUILD),true)
C_FLAGS						+= -g -ggdb -Og -gdwarf-4
else
C_FLAGS						+= -O2
endif

# -------------------- Флаги компоновщика -------------------------------
LD_FLAGS					+= -Wl,-Map=$(TARGET_MAP)

# -------------------- Каталоги поиска заголовочных файлов --------------
INC							+= $(SRC_DIR)
INC							+= $(CMSIS_INC_DIR)
INC							+= $(DEVICE_INC_DIR)

INCLUDES					+= $(foreach i,$(INC),-I$i)

#-------------------- Библиотеки --------------------------------------
LD_FLAGS					+= --specs=nano.specs
ifeq ($(DEBUG_BUILD),true)
LD_FLAGS					+= --specs=rdimon.specs
else
LD_FLAGS					+= --specs=nosys.specs
endif

# -------------------- Правила сборки ----------------------------------
default: $(TARGET_ELF) $(TARGET_BIN)

clean:
	$(ECHO) Очистка проекта $(PROJECT_NAME)
	$(RM) $(BUILD_DIR)

$(OBJ_DIR):
	$(MKDIR) $@

$(DEST_DIR):
	$(MKDIR) $@

$(MAP_DIR):
	$(MKDIR) $@

$(TARGET_BIN): $(TARGET_ELF)
	$(OBJCOPY) $< $@ -Obinary

$(TARGET_ELF): $(OBJECTS) $(DEST_DIR) $(MAP_DIR)
	$(LD) -o $@ $(OBJECTS) $(ARCH_FLAGS) $(LD_FLAGS) $(LIBS) $(LD_DEFS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) -c $< -o $@ $(ARCH_FLAGS) $(C_FLAGS) $(INCLUDES) $(C_DEFS)

$(OBJ_DIR)/%.o: $(DEVICE_SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) -c $< -o $@ $(ARCH_FLAGS) $(C_FLAGS) $(INCLUDES) $(C_DEFS)

include $(wildcard $(OBJ_DIR)/*.d)