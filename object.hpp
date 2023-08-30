#pragma once

#include "sdl_h.hpp"
#include "component.hpp"
#include <vector>



class object_t
{
public:
	transform_t*	transform;
	mesh_t*			mesh;
	std::vector<component_t*> component;

public:
	object_t()
		: transform	(nullptr)
		, mesh		(nullptr)
		, component	()
	{

	}
	~object_t()
	{
		for (auto& c : component)
			delete c;
		delete mesh;
		delete transform;
	}
};