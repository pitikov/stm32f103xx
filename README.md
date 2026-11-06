Изучение ARC Cortex-M3 на базе микроконтроллеров STM32F103xx
===

# Общие сведения и подготовка машины разработчика

Разработка ведется на Debian -подобной ОС (Debina, Ubuntu, Kylix, AstraLinux,...)

Для участия в проекте необходимо установить требуеемое программное обеспечение:

    * IDE VSCode
    * GNU Make
    * gcc-arm-none-eabi
    * binutils-arm-none-eabi
    * pandoc
    * openocd
    * stm32flash 
    * stlink-gui
    * stlink-tools

Для установки выполните в терминале:

Команда `sudo -i` выполняет получение прав суперпользователя на текущую сессию терминала

```bash
sudo -i

apt update
apt install make openocd pandoc gcc-arm-none-eabi binutils-arm-none-eabi stm32flash stlink-gui stlink-tools --install-recommends

snap refresh
snap install code
```

PS: Установку VSCode можно выполнить через SoftwareManager

# Требуемая документация

Документация, требуемая для работы над проектом располагается в папке [doc](file:doc) проекта:

1. [PM0056 Programming manual STM32F10xxx_20xxx_21xxx_L1xxxx Cortex®-M3 programming manual](file:doc/PM0056_Programming_manual_STM32F10xxx_20xxx_21xxx_L1xxxx_Cortex®-M3_programming_manual.pdf)
1. [PM0075 Programming manual STM32F10xxx Flash memory microcontrollers](file:doc/PM0075_Programming_manual_STM32F10xxx_Flash_memory_microcontrollers.pdf)
1. [RM0008 Reference manual STM32F101xx, STM32F102xx, STM32F103xx, STM32F105xx and STM32F107xx advanced Arm®-based 32-bit MCUs](file:doc/RM0008_Reference_manual_STM32F101xx_STM32F102xx_STM32F103xx_STM32F105xx_and_STM32F107xx_advanced_Arm®-based_32-bit_MCUs.pdf)
1. [STM32F103x8 STM32F103xB Medium-density performance line ARM®-based 32-bit MCU with 64 or 128 KB Flash, USB, CAN, 7 timers, 2 ADCs, 9 com. interfaces](file:doc/STM32F103x8_STM32F103xB_Medium-density_performance_line_ARM®-based_32-bit_MCU_with_64_or_128_KB_Flash_USB_CAN_7_timers_2_ADCs_9_com_interfaces.pdf)

# Сборка проекта

Сборка проекта возможна как из терминала командой `make`, так и из среды разработки VSCode по нажатию **Ctrl+Shift+B**.