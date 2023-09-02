#pragma once

#include "algorithm.hpp"
#include "component.hpp"
#include "rigidbody.hpp"



class collider_t : public component_t
{
public:
	static std::vector<collider_t*> colliders;
	static void 
	global_collision_test()
	{
		for (int i = 0; colliders.size() > i; ++i)
		{
			frect_t n = { 
				  colliders[i]->transform->position.x 
					+ colliders[i]->bounding_box.x 
					* colliders[i]->transform->scale.x
				, colliders[i]->transform->position.y 
					+ colliders[i]->bounding_box.y 
					* colliders[i]->transform->scale.y
				, colliders[i]->bounding_box.w * colliders[i]->transform->scale.x
				, colliders[i]->bounding_box.h * colliders[i]->transform->scale.y };
			for (int j = i + 1; colliders.size() > j; ++j)
			{
				frect_t m = { 
					  colliders[j]->transform->position.x 
						+ colliders[j]->bounding_box.x 
						* colliders[j]->transform->scale.x
					, colliders[j]->transform->position.y 
						+ colliders[j]->bounding_box.y 
						* colliders[j]->transform->scale.y
					, colliders[j]->bounding_box.w * colliders[j]->transform->scale.x
					, colliders[j]->bounding_box.h * colliders[j]->transform->scale.y };
				
				uint32_t dir = check_colision(n, m);
				if (dir)
				{
					/** 
					 * TODO: Remove the overlap, 
					 * and update the vector on the rigidbody 
					 * if it has a rigidbody.
					 */
				}
			}
		}
	}

private:
	transform_t*	transform;

public:
	frect_t			bounding_box;
	rigidbody_t*	rigidbody;

public:
	collider_t();
	~collider_t();
};
