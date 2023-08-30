#include "camera.hpp"



void
camera_t::present()
{
	if (!m_meshes.size())
		std::sort(m_meshes.begin(), m_meshes.end());
	for (auto& mesh : m_meshes)
	{
		SDL_RenderCopyF(m_renderer, mesh->m_texture, mesh->src_rect, &mesh->m_dst_rect);
	}
	m_meshes.clear();
	if (nullptr != post_process)
		post_process(m_renderer);
	SDL_RenderPresent(m_renderer);
}
void 
camera_t::clear(color_t _bg)
{
	SDL_SetRenderDrawColor(m_renderer, _bg.r, _bg.g, _bg.b, _bg.a);
	SDL_RenderClear(m_renderer);
}

camera_t::camera_t(_p_window_t _win, fpoint_t _pos, point_t _FOV, _post_process __post_process)
	: m_renderer(SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED))
	, m_meshes()
	, position(_pos)
	, FOV(_FOV)
	, post_process(__post_process)
{
	SDL_RenderSetLogicalSize(m_renderer, FOV.x, FOV.y);
}
camera_t::~camera_t()
{
	SDL_DestroyRenderer(m_renderer);
}
