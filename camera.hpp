#pragma once

#include "sdl_h.hpp"
#include "component.hpp"
#include "mesh.hpp"
#include <vector>
#include <algorithm>

class mesh_t;



class camera_t
{
private:
	typedef void(*_post_process)(_p_renderer_t _renderer);
	_p_renderer_t			m_renderer;
	std::vector<mesh_t*>	m_meshes;

public:
	fpoint_t		position; 
	point_t			FOV;
	_post_process	post_process;

	inline _p_renderer_t
	renderer()
	{ return m_renderer; }

	void
	present();
	void
	clear(color_t _bg = {  });

public:
	camera_t(
		  _p_window_t	_win
		, fpoint_t		_pos
		, point_t		_FOV
		, _post_process __post_process = nullptr);
	~camera_t();
	friend mesh_t;
};