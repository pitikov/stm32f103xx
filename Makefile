PROJECT_NAME		:= stm32f103xx

FLASH_SIZE			:= 64K
RAM_SIZE			:= 20K

HEAP_SIZE			:= 1024
STACK_SIZE			:= 1024

DEBUG_BUILD			?= true

include project.mk