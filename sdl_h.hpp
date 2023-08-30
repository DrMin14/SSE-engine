#pragma once

#pragma comment(lib, "lib/SDL2.lib")
#pragma comment(lib, "lib/SDL2main.lib")
#pragma comment(lib, "lib/SDL2_image.lib")
#pragma comment(lib, "lib/SDL2_mixer.lib")

#include "include/SDL.h"
#include "include/SDL_image.h"
#include "include/SDL_mixer.h"

using _p_window_t	= SDL_Window*;
using _p_renderer_t = SDL_Renderer*;
using _event_t		= SDL_Event;

using _p_texture_t	= SDL_Texture*;

using color_t		= SDL_Color;
using surface_t		= SDL_Surface;
using _p_surface_t	= surface_t*;

using point_t	= SDL_Point;
using fpoint_t	= SDL_FPoint;

using rect_t	= SDL_Rect;
using frect_t	= SDL_FRect;

enum class sound_type
{
	chunk
	, music
};
class sound_t
{
public:
	sound_type	m_type;
	union _p_sound_data
	{
		Mix_Chunk* chunk;
		Mix_Music* music;
	}m_data;

public:
	sound_t(const char* _file, sound_type _type)
		: m_data({})
		, m_type(_type)
	{
		if		(sound_type::chunk	== m_type)
			m_data.chunk = Mix_LoadWAV(_file);
		else if (sound_type::music	== m_type)
			m_data.music = Mix_LoadMUS(_file);

		if (nullptr == m_data.chunk || nullptr == m_data.music);
			// warning_throw(error::fail, std::string("Failed to open file: ") + _file);
	}
	~sound_t()
	{
		if (sound_type::chunk == m_type)
			Mix_FreeChunk(m_data.chunk);
		else if (sound_type::music == m_type)
			Mix_FreeMusic(m_data.music);
	}
};



inline _p_texture_t 
load_texture(_p_renderer_t _renderer, const char* _file)
{
	_p_surface_t src = IMG_Load(_file);
	_p_texture_t tex = SDL_CreateTextureFromSurface(_renderer, src);
	SDL_FreeSurface(src);
	return tex;
}
inline void
unload_texture(_p_texture_t& _tex)
{
	SDL_DestroyTexture(_tex);
	_tex = nullptr;
}
inline point_t
get_texture_size(_p_texture_t _texture)
{
	point_t size;
	SDL_QueryTexture(_texture, NULL, NULL, &size.x, &size.y);
	return size;
}