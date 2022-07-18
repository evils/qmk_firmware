//#include "wait.h"
#include "quantum.h"
#include "i2c_master.h"

/*
TCA8418 key matrix scanner IC on I²C
this peripheral handles the matrix scanning and debouncing
*/

#ifndef I2C_TIMEOUT
#define I2C_TIMEOUT 100
#endif

#define TCA8418_I2C_READ_ADDRESS 0b01101001
#define TCA8418_I2C_WRITE_ADDRESS 0b01101000
#define INT_STAT 0x02
#define KEY_LCK_EC 0x03
#define KEY_EVENT_A 0x04
#define KP_GPIO1 0x1D
#define KP_GPIO2 0x1E
#define KP_GPIO3 0x1F

uint8_t matrix[25] = {0};

void matrix_init(void) {

	i2c_init();
	wait_ms(I2C_TIMEOUT);

	// set cols 0..4 and rows 0..4 as part of the key matrix
	// on the TCA8418 those are pins 9..13 and 8..4 respectively
	// AKA COL{0..4} and ROW{0..4}
	// that's KP_GPIO1, KP_GPIO2, lowest 5 bits of each, set to 1
	// any of the remaining pins could be used as GPIO but by default don't go into the FIFO
	uint8_t low_5 = 0b00011111;
	i2c_writeReg(TCA8418_I2C_WRITE_ADDRESS, KP_GPIO1, &low_5, 1, I2C_TIMEOUT);
	i2c_writeReg(TCA8418_I2C_WRITE_ADDRESS, KP_GPIO2, &low_5, 1, I2C_TIMEOUT);

	// This *must* be called for correct keyboard behavior
	matrix_init_quantum();
}

matrix_row_t matrix_get_row(uint8_t row) {
	// TODO: return the requested row data

	return 0;
}

void matrix_print(void) {
	// TODO: use print() to dump the current matrix state to console
}

uint8_t matrix_scan(void) {
	bool matrix_has_changed = false;

	// read INT_STAT (0x02), if K_INT, matrix has changed
	// GPI_INT only needs to be handled if any GPIO pin is set to be added to the event FIFO?
	uint8_t reg = 0;
	i2c_readReg(TCA8418_I2C_READ_ADDRESS, INT_STAT, &reg, 1, I2C_TIMEOUT);
	bool K_INT = reg & 0b00000001;
	reg = 0;

	// if matrix has changed, read KEY_LCK_EC (0x03) bits 3:0 for number of events and handle each:
	if (K_INT) {

		i2c_readReg(TCA8418_I2C_READ_ADDRESS, KEY_LCK_EC, &reg, 1, I2C_TIMEOUT);
		uint8_t KLEC = reg & 0b00001111; // key event count
		reg = 0;

		// read KEY_EVENT_A (0x04), bit 7 indicates key-up/key-down (0/1), bits 6:0 identify the key
		bool UD = false; // key up or down
		uint8_t KEY = 0; // which key
		for (; KLEC; KLEC--) {

			i2c_readReg(TCA8418_I2C_READ_ADDRESS, KEY_EVENT_A, &reg, 1, I2C_TIMEOUT);

			// catch empty FIFO
			if (reg == 0) break;

			UD = reg >> 7;
			KEY = reg & 0b01111111;
			reg = 0;
			// presumably events 1..5, 11..15, 21..25, 31..35, 41..45 and 51..55 are of interest
			matrix[(KEY / 10) + (KEY % 10) - 1] = UD;
		};

		// reset K_INT by writing 0 to that bit
		i2c_writeReg(TCA8418_I2C_WRITE_ADDRESS, INT_STAT, 0b00000000, 1, I2C_TIMEOUT);
	};

	// assuming no overflow will occur
	// also not using the keypad lock feature
	// and not using the interrupt pin

	// This *must* be called for correct keyboard behavior
	matrix_scan_quantum();

	return matrix_has_changed;
}


__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }

__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}
