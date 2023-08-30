#include "collider.hpp"



std::vector<collider_t*> collider_t::colliders = {};

collider_t::collider_t()
{
	colliders.push_back(this);
}
collider_t::~collider_t()
{
	colliders.erase(find(colliders.begin(), colliders.end(), this));
}
