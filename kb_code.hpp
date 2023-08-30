#pragma once

#include "sdl_h.hpp"



enum class key
{
	  Unknown = SDL_SCANCODE_UNKNOWN

	, A = SDL_SCANCODE_A
	, B = SDL_SCANCODE_B
	, C = SDL_SCANCODE_C
	, D = SDL_SCANCODE_D
	, E = SDL_SCANCODE_E
	, F = SDL_SCANCODE_F
	, G = SDL_SCANCODE_G
	, H = SDL_SCANCODE_H
	, I = SDL_SCANCODE_I
	, J = SDL_SCANCODE_J
	, K = SDL_SCANCODE_K
	, L = SDL_SCANCODE_L
	, M = SDL_SCANCODE_M
	, N = SDL_SCANCODE_N
	, O = SDL_SCANCODE_O
	, P = SDL_SCANCODE_P
	, Q = SDL_SCANCODE_Q
	, R = SDL_SCANCODE_R
	, S = SDL_SCANCODE_S
	, T = SDL_SCANCODE_T
	, U = SDL_SCANCODE_U
	, V = SDL_SCANCODE_V
	, W = SDL_SCANCODE_W
	, X = SDL_SCANCODE_X
	, Y = SDL_SCANCODE_Y
	, Z = SDL_SCANCODE_Z

	, Num_1 = SDL_SCANCODE_1
	, Num_2 = SDL_SCANCODE_2
	, Num_3 = SDL_SCANCODE_3
	, Num_4 = SDL_SCANCODE_4
	, Num_5 = SDL_SCANCODE_5
	, Num_6 = SDL_SCANCODE_6
	, Num_7 = SDL_SCANCODE_7
	, Num_8 = SDL_SCANCODE_8
	, Num_9 = SDL_SCANCODE_9
	, Num_0 = SDL_SCANCODE_0

	, Enter			= SDL_SCANCODE_RETURN
	, ESC			= SDL_SCANCODE_ESCAPE
	, BackSpace		= SDL_SCANCODE_BACKSPACE
	, Tap			= SDL_SCANCODE_TAB
	, Space			= SDL_SCANCODE_SPACE
	, CapSlock		= SDL_SCANCODE_CAPSLOCK

	, Minus			= SDL_SCANCODE_MINUS
	, Equals		= SDL_SCANCODE_EQUALS
	, LBracket		= SDL_SCANCODE_LEFTBRACKET
	, RBracket		= SDL_SCANCODE_RIGHTBRACKET
	, BackSlash		= SDL_SCANCODE_BACKSLASH
	, SemiColon		= SDL_SCANCODE_SEMICOLON
	, Apostrophe	= SDL_SCANCODE_APOSTROPHE
	, Grave			= SDL_SCANCODE_GRAVE
	, Comma			= SDL_SCANCODE_COMMA
	, Period		= SDL_SCANCODE_PERIOD
	, Slash			= SDL_SCANCODE_SLASH

	, PrintScreen	= SDL_SCANCODE_PRINTSCREEN
	, ScrolLock		= SDL_SCANCODE_SCROLLLOCK
	, Pause			= SDL_SCANCODE_PAUSE
	, Insert		= SDL_SCANCODE_INSERT
	, Home			= SDL_SCANCODE_HOME
	, PageUp		= SDL_SCANCODE_PAGEUP
	, Delete		= SDL_SCANCODE_DELETE
	, End			= SDL_SCANCODE_END
	, PageDown		= SDL_SCANCODE_PAGEDOWN

	, Right		= SDL_SCANCODE_RIGHT
	, Left		= SDL_SCANCODE_LEFT
	, Down		= SDL_SCANCODE_DOWN
	, Up		= SDL_SCANCODE_UP

	, NumLock_Clear = SDL_SCANCODE_NUMLOCKCLEAR

	, kp_Num_1 = SDL_SCANCODE_KP_1
	, kp_Num_2 = SDL_SCANCODE_KP_2
	, kp_Num_3 = SDL_SCANCODE_KP_3
	, kp_Num_4 = SDL_SCANCODE_KP_4
	, kp_Num_5 = SDL_SCANCODE_KP_5
	, kp_Num_6 = SDL_SCANCODE_KP_6
	, kp_Num_7 = SDL_SCANCODE_KP_7
	, kp_Num_8 = SDL_SCANCODE_KP_8
	, kp_Num_9 = SDL_SCANCODE_KP_9
	, kp_Num_0 = SDL_SCANCODE_KP_0

	, kp_Divide		= SDL_SCANCODE_KP_DIVIDE
	, kp_Multiply	= SDL_SCANCODE_KP_MULTIPLY
	, kp_Minus		= SDL_SCANCODE_KP_MINUS
	, kp_Plus		= SDL_SCANCODE_KP_PLUS
	, kp_Enter		= SDL_SCANCODE_KP_ENTER
	, kp_Period		= SDL_SCANCODE_KP_PERIOD

	, LCtrl		= SDL_SCANCODE_LCTRL
	, LShift	= SDL_SCANCODE_LSHIFT
	, LAlt		= SDL_SCANCODE_LALT
	, LGUI		= SDL_SCANCODE_LGUI
	, RCtrl		= SDL_SCANCODE_RCTRL
	, RShift	= SDL_SCANCODE_RSHIFT
	, RAlt		= SDL_SCANCODE_RALT
	, RGUI		= SDL_SCANCODE_RGUI

	, F1  = SDL_SCANCODE_F1
	, F2  = SDL_SCANCODE_F2
	, F3  = SDL_SCANCODE_F3
	, F4  = SDL_SCANCODE_F4
	, F5  = SDL_SCANCODE_F5
	, F6  = SDL_SCANCODE_F6
	, F7  = SDL_SCANCODE_F7
	, F8  = SDL_SCANCODE_F8
	, F9  = SDL_SCANCODE_F9
	, F10 = SDL_SCANCODE_F10
	, F11 = SDL_SCANCODE_F11
	, F12 = SDL_SCANCODE_F12
	, F13 = SDL_SCANCODE_F13
	, F14 = SDL_SCANCODE_F14
	, F15 = SDL_SCANCODE_F15
	, F16 = SDL_SCANCODE_F16
	, F17 = SDL_SCANCODE_F17
	, F18 = SDL_SCANCODE_F18
	, F19 = SDL_SCANCODE_F19
	, F20 = SDL_SCANCODE_F20
	, F21 = SDL_SCANCODE_F21
	, F22 = SDL_SCANCODE_F22
	, F23 = SDL_SCANCODE_F23
	, F24 = SDL_SCANCODE_F24

	, Size = SDL_NUM_SCANCODES
};