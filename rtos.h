
#ifndef _RTOS_TYPES_H_
#define _RTOS_TYPES_H_

#include "drivers.h"

using fader_pair 	= std::pair<adc_map, uart_map>;
using button_pair 	= std::pair<shift_map, uart_map>;
using encoder_pair	= std::pair<shift_map, uart_map>;
using led_pair		= std::pair<shift_map, uart_map>;
using dummy_pair 	= std::pair<dummy_map, dummy_map>;

struct mappings {
/*	std::vector<fader_pair> fader_map;
	std::vector<button_pair> button_map;
	std::vector<encoder_pair> encoder_map;
	std::vector<led_pair> led_map;
*/
#ifdef TESTING
	// (drv, host)
	dummy_pair dummy_map[32];
#endif
	uint32_t loop_hz;
};

template<typename... T>
class tasks {
public:
	int32_t read();
	int32_t write();
};

template <typename T>
class rtos {
public:
	rtos(const T&, const mappings*);
	void loop();
#ifndef TESTING
private:
#endif
	const mappings* board_map;
	const T driver_list;
	void update_stack();
};


#endif




