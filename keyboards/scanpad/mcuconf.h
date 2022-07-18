#pragma once

#include_next <mcuconf.h>

#undef STM32_PWM_USE_TIM2
#define STM32_PWM_USE_TIM2 TRUE

#undef STM32_SPI_USE_SPI2
#define STM32_SPI_USE_SPI2 FALSE


#undef STM32_I2C_USE
#define STM32_I2C_USEI2C2 FALSE

#undef STM32_I2C_USEI2C1
#define STM32_I2C_USEI2C1 TRUE
