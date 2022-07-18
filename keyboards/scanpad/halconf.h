#pragma once

#define HAL_USE_PWM TRUE

#include_next <halconf.h>


#ifndef HAL_USE_I2C
#define HAL_USE_I2C TRUE
#endif
