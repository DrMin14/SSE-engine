#pragma once

#include "sdl_h.hpp"



class timer_t
{
private:
	uint64_t m_last;

public:
	const time_t
	tick();

	void
	update();

	const time_t
	last();

	const time_t
	elapse();

	void
	sleep(time_t _for);
	

public:
	timer_t();
	~timer_t();
};