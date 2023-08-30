#pragma once

#include "component.hpp"
#include "transform.hpp"



class rigidbody_t : public component_t
{
private:
	transform_t* transform;

public:
	fpoint_t		vec;

	void
	after() override /**< can remove override(on ms, idk other ide)*/
	{
		// TODO: make a simple physics engine(func)
	}
};