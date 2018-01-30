

#include "rtos.h"
#include "drivers.h"
#include <unistd.h>		// usleep

rtos::rtos(const T& drv, const mappings* brd) : driver_list(drv), board_map(brd) { }
void rtos::loop() {
	while(1) {
		update_stack();
		usleep(1000000 / board_map->loop_hz);
	}
}

void rtos::update_stack() {
	int32_t ret;
/*	for(auto& d : list) {
		ret = (*d).read();
		if(ret < 0) {
			// TODO: throw error
		}
 		ret = (*d).write();
 		if(ret < 0) {
 			// TODO: throw error
 		}
 	}*/
}

control::control() { }
control::control(uint32_t a) : host_val(a) { }
control::~control() { }
void control::drv_set(uint32_t val) {
	host_val = val;
}

button::~button() { }
void button::drv_set(uint32_t val) {
	if(val ^ last) {
		host_val++;
		last = val;
	}
}

encoder::~encoder() { }
void encoder::drv_set(uint32_t val) {
	// TODO: translate 2 encoder bits into +/-
}

indicator::indicator() { }
indicator::indicator(uint32_t a) : drv_val(a) { }
indicator::~indicator() { }
void indicator::host_set(uint32_t val) {
	drv_val = val;
}

#ifdef TESTING
dummy::dummy() : control(0xFFFFFFFF), indicator(0xFFFFFFFF) { }
dummy::~dummy() { }
#endif
