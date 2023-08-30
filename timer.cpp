#include "timer.hpp"


const time_t
timer_t::tick()
{
	return SDL_GetTicks64();
}
void
timer_t::update()
{
	m_last = tick();
}
const time_t
timer_t::last()
{
	return m_last;
}
const time_t
timer_t::elapse()
{
	return tick() - m_last;
}
void
timer_t::sleep(time_t _for)
{
	SDL_Delay(_for);
}

timer_t::timer_t()
	: m_last()
{
	update();
}
timer_t::~timer_t()
{

}
