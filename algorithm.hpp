#pragma once

#include "sdl_h.hpp"
#include <algorithm>



uint32_t
check_colision(const frect_t& _x, const frect_t& _y, fpoint_t* _overlap = nullptr);