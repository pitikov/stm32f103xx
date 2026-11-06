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
CMSIS_CORE_DIR				:= ./CMSIS/Core/
CMSIS_CORE_INC_DIR			:= $(CMSIS_DIR)/Include
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

# формирование файлов зависимостей для объектников
C_FLAGS						+= -MD
# Вывод всх предупреждений
C_FLAGS						+= -Wall
# Педантичный режим компилятора для исключения неоднозначности кода
C_FLAGS						+= -Wpedantic
# Выбор используемого стандарта языка Си
C_FLAGS						+= -std=c17

# Поределяем уровень оптимизации и хранения отладочных данных исходя из типа сборки Debug/Release
ifeq ($(DEBUG_BUILD),true)
C_FLAGS						+= -g -ggdb -Og -gdwarf-4
else
C_FLAGS						+= -O2
endif

# -------------------- Флаги компоновщика -------------------------------
LD_FLAGS					+= -Wl,-Map=$(TARGET_MAP)
LD_FLAGS					+= -Wl,--print-memory-usage

# -------------------- Каталоги поиска заголовочных файлов --------------
INC							+= $(SRC_DIR)
INC							+= $(CMSIS_CORE_INC_DIR)
INC							+= $(DEVICE_INC_DIR)

# Собираем каталоги поиска файлов декларации в вормат GCC
INCLUDES					+= $(foreach i,$(INC),-I$i)

#-------------------- Библиотеки --------------------------------------
LIBS						+= --specs=nano.specs
ifeq ($(DEBUG_BUILD),true)
# Для отладки будем использовать semihosting из библиотеки rdimon
LIBS						+= --specs=rdimon.specs
else
# Для релиз сборки используем заглушки потокового ввода вывода библиотеки nosys
LIBS						+= --specs=nosys.specs
endif

# библиотека базовых функций языка Си. По сути линкуется всегда, но лучше указать явно
LIBLIST						+= c
LIBLIST						+= g
LIBLIST						+= gcc
# Библиотека математических операций
LIBLIST						+= m

# Собираем библиотеки в формат строки компановки
LIBS						+= -Wl,--start-group
LIBS						+= $(foreach l,$(LIBLIST),-l$l)
LIBS						+= -Wl,--end-group

# -------------------- Правила сборки ----------------------------------

# Правило сборки default встречается первым, соответстенно оно будет собираться по умолчанию,
# если иное парвило сборки не указанно в команде make
default: $(TARGET_ELF) $(TARGET_BIN)

clean:
	$(ECHO) Очистка проекта $(PROJECT_NAME)
	$(RM) $(BUILD_DIR)

# Правила динамического создания каталогов сборки
$(OBJ_DIR):
	$(MKDIR) $@

$(DEST_DIR):
	$(MKDIR) $@

$(MAP_DIR):
	$(MKDIR) $@

# Создание бинарного образа прошивки
$(TARGET_BIN): $(TARGET_ELF)
	$(ECHO) Копирование бинарного образа $@ из ELF файла $<
	$(OBJCOPY) $< $@ -Obinary

# Компановка ELF32 образа прошивки (помимо исполняемого кода содержит отладочную и прочую информацию)
$(TARGET_ELF): $(OBJECTS) $(DEST_DIR) $(MAP_DIR)
	$(ECHO) Компановка ELF файла $@ из объектников $(OBJECTS)
	$(LD) -o $@ $(OBJECTS) $(ARCH_FLAGS) $(LD_FLAGS) $(LIBS) $(LD_DEFS)

# Правило для компиляции объкетных файлов из пользовательких исходных кодов
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(ECHO) Компиляция объектного файла $@ из $<
	$(CC) -c $< -o $@ $(ARCH_FLAGS) $(C_FLAGS) $(INCLUDES) $(C_DEFS)

# Правило для компиляции объкетных файлов из исходных кодов платформо-зависимого кода шаблона CMSIS
$(OBJ_DIR)/%.o: $(DEVICE_SRC_DIR)/%.c $(OBJ_DIR)
	$(ECHO) Компиляция объектного файла $@ из $<
	$(CC) -c $< -o $@ $(ARCH_FLAGS) $(C_FLAGS) $(INCLUDES) $(C_DEFS)

# Подключение файлов зависимостей
include $(wildcard $(OBJ_DIR)/*.d)

# Сокрытие вывод компиляции для целей
.SILENT: $(BUILD_DIR)
.SILENT: $(OBJ_DIR)
.SILENT: $(DEST_DIR)
.SILENT: $(MAP_DIR)
.SILENT: clean
.SILENT: $(TARGET_BIN)

# Экранирование (обязательное испольнение) целей сборки
.PHONY: clean
.PHONY: $(PROJECT_ELF)
.PHONY: $(PROJECT_BIN)