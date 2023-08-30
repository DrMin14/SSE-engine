#include "event.hpp"

void
event_t::_input_pre_process()
{
	for (char& key : kb)
	{
		if		( 2 == key)	key = 1;
		else if (-1 == key)	key = 0;
	}
	for (char& button : ms)
	{
		if		( 2 == button) button = 1;
		else if (-1 == button) button = 0;
	}
	ms_wl = {};
}
void
event_t::_input_process()
{
	char* key;
	char* button;
	switch (m_event.type)
	{
	case SDL_KEYDOWN:
		key = &kb[SDL_GetScancodeFromKey(m_event.key.keysym.sym)];
		*key = input_state::down;
		break;
	case SDL_KEYUP:
		key = &kb[SDL_GetScancodeFromKey(m_event.key.keysym.sym)];
		*key = input_state::up;
		break;
	case SDL_MOUSEBUTTONDOWN:
		button = &ms[m_event.button.button];
		*button = input_state::down;
		break;
	case SDL_MOUSEBUTTONUP:
		button = &ms[m_event.button.button];
		*button = input_state::up;
		break;
	case SDL_MOUSEMOTION:
		ms_ps = {
			  m_event.motion.x
			, m_event.motion.y };
		break;
	case SDL_MOUSEWHEEL:
		if (   kb[SDL_SCANCODE_LSHIFT]
			|| kb[SDL_SCANCODE_RSHIFT])
			ms_wl = {
				  m_event.wheel.y
				, ms_wl.y };
		else
			ms_wl = {
				  ms_wl.x
				, m_event.wheel.y };
		break;
	default:
		break;
	}
}

void
event_t::poll()
{
	_input_pre_process();
	while (SDL_PollEvent(&m_event))
	{
		_input_process();
		if (nullptr != process)
			process(this);
	}
}

int 
event_t::poll_raw(_event_t& _ev)
{
	return SDL_PollEvent(&_ev);
}

bool
event_t::get_event(uint32_t _type)
{
	if (_type == m_event.type)
		return true;
	return false;
}

point_t
event_t::get_ms_pos()
{
	return ms_ps;
}
point_t
event_t::get_ms_wheel()
{
	return ms_wl;
}

input_state::input_state
event_t::input(mouse _input)
{
	return (input_state::input_state)ms[(uint32_t)_input];
}
input_state::input_state
event_t::input(key _input)
{
	return (input_state::input_state)kb[(uint32_t)_input];
}
