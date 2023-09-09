#include "base.hpp"

// #define _BUILD_WIN_SYS

#ifdef _BUILD_WIN_SYS							
#ifdef _WIN32									
#ifdef _MSC_VER								
#pragma comment(linker, "/subsystem:windows")
#endif										
#endif
#else
#include <iostream>
#endif



#include <string>

/**components*/
#include "collider.hpp"
#include "mesh.hpp"
#include "rigidbody.hpp"
#include "transform.hpp"



bool is_run = true;

class test_component_t : public component_t
{
private:
	event_t&		ev;
	transform_t*	trans;

public:
	void update() override
	{
		if (ev.input(key::W))
			trans->position.y -= 10.f;
		if (ev.input(key::S))
			trans->position.y += 10.f;
		if (ev.input(key::A))
			trans->position.x -= 10.f;
		if (ev.input(key::D))
			trans->position.x += 10.f;
	}

public:
	test_component_t(event_t& _ev, transform_t* _trans)
		: ev	(_ev)
		, trans	(_trans)
	{

	}
};

void 
process(event_t* _ev)
{
	if (_ev->get_event(SDL_QUIT))
		is_run = false;
}

int 
main(int argc, char* argv[]) 
{
	if (   SDL_Init(SDL_INIT_EVERYTHING)
		|| !IMG_Init(IMG_INIT_PNG)
		|| !Mix_Init(MIX_INIT_OGG))
		is_run = false;

	_p_window_t	window = SDL_CreateWindow(
		  "TEST"
		, SDL_WINDOWPOS_CENTERED
		, SDL_WINDOWPOS_CENTERED
		, 1600
		, 900
		, NULL);
	camera_t	cam(window, { 0, 0 }, { 1600, 900 }, nullptr);
	speaker_t	spc;
	event_t		ev;
	ev.process = process;
	timer_t t;

	std::vector<object_t*> objs;

	/**example: create obj*/
	object_t* test_obj	= new object_t();
	test_obj->transform	= new transform_t({ 0, 0 }, 0.0f, { 1.f, 1.f });
	test_obj->mesh		= new mesh_t(
		  load_texture(cam.renderer(), "img/cat.png")
		, test_obj->transform);
	test_obj->component.push_back(new test_component_t(ev, test_obj->transform));
	objs.push_back(test_obj);

	/**example: open audio file*/
	sound_t sound0("sud/get.wav", sound_type::chunk);
	sound_t sound1("sud/Beach_Parade.wav", sound_type::music);
	spc.play(0, sound0, 0);
	spc.play(0, sound1, 10);

	while (is_run)
	{
		t.update();
		ev.poll();


		for (auto& o : objs)
		{
			for (auto& c : o->component)
				c->update();
			for (auto& c : o->component)
				c->after();
		}
		
		collider_t::global_collision_test();
		
		for (auto& o : objs)
		{
			if (nullptr != o->mesh)
				o->mesh->draw(cam);
		}

		cam.present();
		cam.clear({ 0xaa, 0xaa, 0xaa, 0xaa });

		int delay = 1000 / 60 - t.elapse();
		if (0 < delay)
			t.sleep(delay);
		// std::cout << std::to_string(1000.f / t.elapse()) << std::endl;
	}

	for (auto& o : objs)
		delete o;

	SDL_DestroyWindow(window);

	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}
