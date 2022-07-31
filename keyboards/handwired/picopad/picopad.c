#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
	// Key Matrix to LED Index
	{
		{ 0, 1, 2 },
		{ 5, 4, 3 },
		{ 8, 7, 6 }
	}, // LED Index to Physical Position
	{
		{0, 0}, {112, 0}, {224, 0},
		{0, 32}, {112, 32}, {224, 32},
		{0, 64}, {112, 64}, {224, 64}
	}, // LED Index to Flag
	{
		4, 4, 4,
		4, 4, 4,
		8, 8, 1
	}
};

#endif
