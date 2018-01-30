
#ifndef _DRIVERS_H_
#define _DRIVERS_H_

#include "app_types.h"


// include chip specific includes here

class drv {
public:
	drv();
	virtual ~drv();
	virtual int32_t read() = 0;
	virtual int32_t write() = 0;
};

class dummy_drv : public drv {
public:
	dummy_drv();
	~dummy_drv();
	// puts drv_val & drv_map into host_val
	int32_t read() override;
	// puts host_val & host_map into drv_val
	int32_t write() override;
	dummy* dum_ptr[32];
};

#endif

