#include "speaker.hpp"



void
speaker_t::play(int _ch, sound_t& _sound, int _loops)
{
	if		(sound_type::chunk == _sound.m_type)
		Mix_PlayChannel(_ch, _sound.m_data.chunk, _loops);
	else if (sound_type::music == _sound.m_type)
		Mix_PlayMusic(_sound.m_data.music, _loops);
}

speaker_t::speaker_t()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048));
	// error_throw(error::fail, "Failed to open audio device");
}
speaker_t::~speaker_t()
{
	Mix_CloseAudio();
}