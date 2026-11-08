target extended-remote :3333
load
monitor reset halt
monitor arm semihosting enable
step
break HardFault_Handler
break main