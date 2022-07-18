MCU = STM32F103

LTO_ENABLED = yes
CUSTOM_MATRIX = yes
SRC += matrix.c
QUANTUM_LIB_SRC += i2c_master.c
