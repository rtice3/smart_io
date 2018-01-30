
#ifndef _MAPS_H_
#define _MAPS_H_

#include <cstdint>
#include <vector>
#include <memory>

struct uart_map {
	// TODO: create UART map structure
};

struct adc_map {
	// TODO: create ADC map structure
};

struct shift_map {
	uint8_t shift_reg_num;
	uint8_t index;
};

#ifdef TESTING
typedef uint32_t dummy_map;
#endif


#endif
