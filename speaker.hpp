#pragma once

#include "sdl_h.hpp"
#include <cmath>



class speaker_t
{
public:
	void
	play(int _ch, sound_t& _sound, int _loops);
	
public:
	speaker_t();
	~speaker_t();
};