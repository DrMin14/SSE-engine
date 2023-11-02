#pragma once

#include "sdl_h.hpp"
#include "kb_code.hpp"
#include "ms_code.hpp"



namespace input_state
{
	typedef enum input_state
	{
		  none	=  0
		, up	= -1
		, hold	=  1
		, down	=  2
	}input_state;
}

/** This class is created for demonstration purposes. 
 * To become a better programmer, it's recommended 
 * to research SDL event functions 
 * and the operating system's event queue processing. 
 * For example, you can explore functions 
 * like SDL_GetKeyboardState.
 */
class event_t
{
private:
	typedef void(*_process)(event_t* _ev);
	
	_event_t m_event;

	char kb[(uint32_t)key::Size]; /**<keyboard*/

	char ms[(uint32_t)mouse::Size];	/**<mouse*/
	point_t ms_wl; /**<mouse wheel vector*/
	point_t ms_ps; /**<mouse position*/

	void
	_input_pre_process();
	void
	_input_process();

public:
	/**
	 * process func pointer is for
	 * extra event process
	 *
	 * \param
	 * _ev is for to use this pointer in not-member func
	 */
	_process process;
	/**
	 * this func is only works in func of "process" ptr
	 *
	 * \param
	 * _type is type of event to check
	 *
	 * \return
	 * returns true if the event has _type.
	 * otherwise, returns false.
	 */
	bool
	get_event(uint32_t _type);

	void
	poll();

	int 
	poll_raw(_event_t& _ev);

	point_t
	get_ms_pos();
	point_t
	get_ms_wheel();

	input_state::input_state
	input(mouse _input);
	input_state::input_state
	input(key _input);

public:
	event_t()
		: m_event()
		, kb()
		, ms()
		, ms_wl()
		, ms_ps()
		, process(nullptr)
	{}
};
