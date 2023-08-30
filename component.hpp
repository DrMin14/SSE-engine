#pragma once

#include "sdl_h.hpp"
#include <vector>



class component_t
{ 
public: 
	virtual void update();
	virtual void after();

public: 
	component_t();
	virtual ~component_t();
};