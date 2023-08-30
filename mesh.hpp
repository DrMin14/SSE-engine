#pragma once

#include "algorithm.hpp"
#include "camera.hpp"
#include "component.hpp"
#include "transform.hpp"

class camera_t;


class mesh_t : public component_t
{
private:
	_p_texture_t	m_texture;
	transform_t*	m_transform;
	frect_t			m_dst_rect;

public:
	rect_t*		src_rect;
	fpoint_t	offset;
	fpoint_t	scale;

	void
	draw(camera_t& _cam);
	/**C++20*/
	inline auto
	operator <=>(const mesh_t& _other)
	{ return this->m_transform->z_depth <=> _other.m_transform->z_depth; }

public:
	mesh_t(
		  _p_texture_t	_texture
		, transform_t* _transform
		, rect_t* _src_rect = nullptr
		, fpoint_t		_offset = {}
		, fpoint_t		_scale = { 1.f, 1.f });
	~mesh_t();

	friend camera_t;
};