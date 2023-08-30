#pragma once

#include "component.hpp"



class transform_t : public component_t
{
public:
	fpoint_t	position;
	float		z_depth; /**<aka. layer*/
	fpoint_t	scale;

public:
	transform_t(
		  fpoint_t	_position
		, float		_z_depth = 0.f
		, fpoint_t	_scale = { 1.f, 1.f })
		: position(_position)
		, z_depth(_z_depth)
		, scale(_scale)
	{

	}
};