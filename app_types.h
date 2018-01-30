#ifndef _APP_TYPES_H_
#define _APP_TYPES_H_

#include "maps.h"

class control {
public:
	control();
	control(uint32_t);
	virtual ~control();
	virtual void drv_set(uint32_t val);
	uint32_t host_val;
};

class button : public control {
public:
	button();
	~button();
	void drv_set(uint32_t) override;
	shift_map* drv_map;
	uart_map* host_map;
	// TODO: implement hold feature
private:
	uint32_t last;
};

class encoder : public control {
public:
	encoder();
	~encoder();
	void drv_set(uint32_t) override;
	shift_map* drv_map;
	uart_map* host_map;
};

class indicator {
public:
	indicator();
	indicator(uint32_t);
	virtual ~indicator();
	virtual void host_set(uint32_t);
	uint32_t drv_val;
};

class led : public indicator {
public:
	led();
	~led();
	shift_map* drv_map;
	uart_map* host_map;
};

class fader : public control, public indicator {
public:
	fader();
	~fader();
	adc_map* drv_map;
	uart_map* host_map;
};

#ifdef TESTING

class dummy : public control, public indicator {
public:
	dummy();
	~dummy();
	const dummy_map* drv_map;
	const dummy_map* host_map;
};
#endif

#endif
