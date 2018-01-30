
#include "drivers.h"
#include "maps.h"
#include <bitset>
#include <iostream>

drv::drv() { }
drv::~drv() { }

dummy_drv::dummy_drv() { }
dummy_drv::~dummy_drv() { }
int32_t dummy_drv::read() {
	for(int i = 0; i < 32; i++) {
		dum_ptr[i]->drv_set(dum_ptr[i]->drv_val & ~(*dum_ptr[i]->drv_map));
		std::cout << "read: " << std::bitset<32>(dum_ptr[i]->host_val) << std::endl;
	}
	return 0;
}
int32_t dummy_drv::write() {
	for(int i = 0; i < 32; i++) {
		dum_ptr[i]->host_set(dum_ptr[i]->host_val & ~(*dum_ptr[i]->host_map));
		std::cout << "write: " << std::bitset<32>(dum_ptr[i]->drv_val) << std::endl;
	}
	return 0;
}
