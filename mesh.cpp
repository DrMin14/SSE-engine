#include "mesh.hpp"



void 
mesh_t::draw(camera_t& _cam)
{
	frect_t fov = {
		  0
		, 0
		, _cam.FOV.x
		, _cam.FOV.y };

	m_dst_rect.x =    
		  m_transform->position.x 
		- _cam.position.x 
		+ offset.x 
		* m_transform->scale.x 
		* scale.x;
	m_dst_rect.y =    
		  m_transform->position.y 
		- _cam.position.y 
		+ offset.y 
		* m_transform->scale.y 
		* scale.y;

	if (nullptr == src_rect)
	{
		m_dst_rect.w = 
			  (float)get_texture_size(m_texture).x 
			* m_transform->scale.x 
			* scale.x;
		m_dst_rect.h = 
			  (float)get_texture_size(m_texture).y 
			* m_transform->scale.y 
			* scale.y;
	}
	else
	{
		m_dst_rect.w = (float)src_rect->w * m_transform->scale.x * scale.x;
		m_dst_rect.h = (float)src_rect->h * m_transform->scale.y * scale.y;
	}

	/**debug*/
	/*SDL_SetRenderDrawColor(_cam.m_renderer, 0xff, 0x00, 0x00, 0xff);
	SDL_RenderDrawRectF(_cam.m_renderer, &fov);
	SDL_RenderDrawRectF(_cam.m_renderer, &m_dst_rect);*/

	if (check_colision(fov, m_dst_rect))
		_cam.m_meshes.push_back(this);
}

mesh_t::mesh_t(
	  _p_texture_t	_texture
	, transform_t*	_transform
	, rect_t*		_src_rect
	, fpoint_t		_offset
	, fpoint_t		_scale)
	: m_texture		(_texture)
	, m_transform	(_transform)
	, src_rect		(_src_rect)
	, offset		(_offset)
	, scale			(_scale)
{

}

mesh_t::~mesh_t()
{
	unload_texture(m_texture);
	delete src_rect;
}