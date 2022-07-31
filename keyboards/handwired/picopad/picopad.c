#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
	// Key Matrix to LED Index
	{
		{ NO_LED,   9, 10, 11, NO_LED },
		{ 8,        12, 13, 14,     0 },
		{ 7,        17, 16, 15,     1 },
		{ 6,        18, 19, 20,     2 },
		{ NO_LED,   5, 4, 3,   NO_LED }
	}, // LED Index to Physical Position
	{
		          {56, 0}, {112, 0}, {168, 0},
		{0, 16}, {56, 16}, {112, 16}, {168, 16}, {224, 16},
		{0, 32}, {56, 32}, {112, 32}, {168, 32}, {224, 32},
		{0, 48}, {56, 48}, {112, 48}, {168, 48}, {224, 48},
		         {56, 64}, {112, 64}, {168, 64}


	}, // LED Index to Flag
	{
		   8, 8, 8,
		8, 4, 4, 4, 8,
		8, 4, 4, 4, 8,
		8, 4, 4, 1, 8,
		   8, 8, 8,
	}
};

#endif
