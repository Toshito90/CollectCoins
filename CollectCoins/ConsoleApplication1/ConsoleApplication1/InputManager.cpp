#include "Application.h"
#include "InputManager.h"

bool InputManager::Init(Application* game) {
	this->game = game;

	keypressedstate = false;

	screen_width = game->GetWindow_Width();
	screen_height = game->GetWindow_Height();

	//This part is only a place holder, since there is no file to read the settings when loading the program
	ActionKeys[Action_PlayerMOVEUP] = keyb_UPARROW;
	ActionKeys[Action_PlayerMOVEDOWN] = keyb_DOWNARROW;
	ActionKeys[Action_PlayerMOVELEFT] = keyb_LEFTARROW;
	ActionKeys[Action_PlayerMOVERIGHT] = keyb_RIGHTARROW;
	ActionKeys[Action_PlayerINTERACTION] = keyb_C;
	ActionKeys[Action_START] = keyb_ENTER;
	ActionKeys[Action_PAUSE] = keyb_SPACE;
	ActionKeys[Action_BACK] = keyb_ESCAPE;
	ActionKeys[Action_CamZoomIn] = keyb_F9;
	ActionKeys[Action_CamZoomOut] = keyb_F10;

	return true;
}

void InputManager::TranslateKey(bool keystate) {
	switch (rawinput.key.keysym.sym) {
	case SDLK_0:
		keyID[keyb_0] = keystate;
		break;
	case SDLK_1:
		keyID[keyb_1] = keystate;
		break;
	case SDLK_2:
		keyID[keyb_2] = keystate;
		break;
	case SDLK_3:
		keyID[keyb_3] = keystate;
		break;
	case SDLK_4:
		keyID[keyb_4] = keystate;
		break;
	case SDLK_5:
		keyID[keyb_5] = keystate;
		break;
	case SDLK_6:
		keyID[keyb_6] = keystate;
		break;
	case SDLK_7:
		keyID[keyb_7] = keystate;
		break;
	case SDLK_8:
		keyID[keyb_8] = keystate;
		break;
	case SDLK_9:
		keyID[keyb_9] = keystate;
		break;
	case SDLK_a:
		keyID[keyb_A] = keystate;
		break;
	case SDLK_b:
		keyID[keyb_B] = keystate;
		break;
	case SDLK_c:
		keyID[keyb_C] = keystate;
		break;
	case SDLK_d:
		keyID[keyb_D] = keystate;
		break;
	case SDLK_e:
		keyID[keyb_E] = keystate;
		break;
	case SDLK_f:
		keyID[keyb_F] = keystate;
		break;
	case SDLK_g:
		keyID[keyb_G] = keystate;
		break;
	case SDLK_h:
		keyID[keyb_H] = keystate;
		break;
	case SDLK_i:
		keyID[keyb_I] = keystate;
		break;
	case SDLK_j:
		keyID[keyb_J] = keystate;
		break;
	case SDLK_k:
		keyID[keyb_K] = keystate;
		break;
	case SDLK_l:
		keyID[keyb_L] = keystate;
		break;
	case SDLK_m:
		keyID[keyb_M] = keystate;
		break;
	case SDLK_n:
		keyID[keyb_N] = keystate;
		break;
	case SDLK_o:
		keyID[keyb_O] = keystate;
		break;
	case SDLK_p:
		keyID[keyb_P] = keystate;
		break;
	case SDLK_q:
		keyID[keyb_Q] = keystate;
		break;
	case SDLK_r:
		keyID[keyb_R] = keystate;
		break;
	case SDLK_s:
		keyID[keyb_S] = keystate;
		break;
	case SDLK_t:
		keyID[keyb_T] = keystate;
		break;
	case SDLK_u:
		keyID[keyb_U] = keystate;
		break;
	case SDLK_v:
		keyID[keyb_V] = keystate;
		break;
	case SDLK_w:
		keyID[keyb_W] = keystate;
		break;
	case SDLK_x:
		keyID[keyb_X] = keystate;
		break;
	case SDLK_y:
		keyID[keyb_Y] = keystate;
		break;
	case SDLK_z:
		keyID[keyb_Z] = keystate;
		break;
	case SDLK_BACKSLASH:
		keyID[keyb_BackSlash] = keystate;
		break;
	case SDLK_UNDERSCORE:
		keyID[keyb_Score] = keystate;
		break;
	case SDLK_PLUS:
		keyID[keyb_PLUS] = keystate;
		break;
	case SDLK_QUESTION:
		keyID[keyb_Interrogation] = keystate;
		break;
	case SDLK_TAB:
		keyID[keyb_TAB] = keystate;
		break;
	case SDLK_CAPSLOCK:
		keyID[keyb_CAPSLOCK] = keystate;
		break;
	case SDLK_LSHIFT:
		keyID[keyb_LSHIFT] = keystate;
		break;
	case SDLK_LCTRL:
		keyID[keyb_LCTRL] = keystate;
		break;
	case SDLK_LALT:
		keyID[keyb_LALT] = keystate;
		break;
	case SDLK_SPACE:
		keyID[keyb_SPACE] = keystate;
		break;
	case SDLK_BACKSPACE:
		keyID[keyb_BACKSPACE] = keystate;
		break;
	case SDLK_RETURN:
		keyID[keyb_ENTER] = keystate;
		break;
	case SDLK_RSHIFT:
		keyID[keyb_RSHIFT] = keystate;
		break;
	case SDLK_RCTRL:
		keyID[keyb_RCTRL] = keystate;
		break;
	case SDLK_RALT:
		keyID[keyb_RALT] = keystate;
		break;
	case SDLK_PRINTSCREEN:
		keyID[keyb_PRINT] = keystate;
		break;
	case SDLK_SCROLLLOCK:
		keyID[keyb_SCROLL] = keystate;
		break;
	case SDLK_PAUSE:
		keyID[keyb_BREAK] = keystate;
		break;
	case SDLK_INSERT:
		keyID[keyb_INSERT] = keystate;
		break;
	case SDLK_HOME:
		keyID[keyb_HOME] = keystate;
		break;
	case SDLK_PAGEUP:
		keyID[keyb_PAGEUP] = keystate;
		break;
	case SDLK_PAGEDOWN:
		keyID[keyb_PAGEDOWN] = keystate;
		break;
	case SDLK_END:
		keyID[keyb_END] = keystate;
		break;
	case SDLK_DELETE:
		keyID[keyb_DELETE] = keystate;
		break;
	case SDLK_ESCAPE:
		keyID[keyb_ESCAPE] = keystate;
		break;
	case SDLK_UP:
		keyID[keyb_UPARROW] = keystate;
		break;
	case SDLK_DOWN:
		keyID[keyb_DOWNARROW] = keystate;
		break;
	case SDLK_LEFT:
		keyID[keyb_LEFTARROW] = keystate;
		break;
	case SDLK_RIGHT:
		keyID[keyb_RIGHTARROW] = keystate;
		break;
	case SDLK_NUMLOCKCLEAR:
		keyID[keyb_NUMLOCK] = keystate;
		break;
	case SDLK_KP_DIVIDE:
		keyID[keyb_SLASH] = keystate;
		break;
	case SDLK_KP_ENTER:
		keyID[keyb_NUMENTER] = keystate;
		break;
	case SDLK_ASTERISK:
		keyID[keyb_STAR] = keystate;
		break;
	case SDLK_KP_PERIOD:
		keyID[keyb_NUMDOT] = keystate;
		break;
	case SDLK_KP_0:
		keyID[keyb_NUM0] = keystate;
		break;
	case SDLK_KP_1:
		keyID[keyb_NUM1] = keystate;
		break;
	case SDLK_KP_2:
		keyID[keyb_NUM2] = keystate;
		break;
	case SDLK_KP_3:
		keyID[keyb_NUM3] = keystate;
		break;
	case SDLK_KP_4:
		keyID[keyb_NUM4] = keystate;
		break;
	case SDLK_KP_5:
		keyID[keyb_NUM5] = keystate;
		break;
	case SDLK_KP_6:
		keyID[keyb_NUM6] = keystate;
		break;
	case SDLK_KP_7:
		keyID[keyb_NUM7] = keystate;
		break;
	case SDLK_KP_8:
		keyID[keyb_NUM8] = keystate;
		break;
	case SDLK_KP_9:
		keyID[keyb_NUM9] = keystate;
		break;
	case SDLK_F1:
		keyID[keyb_F1] = keystate;
		break;
	case SDLK_F2:
		keyID[keyb_F2] = keystate;
		break;
	case SDLK_F3:
		keyID[keyb_F3] = keystate;
		break;
	case SDLK_F4:
		keyID[keyb_F4] = keystate;
		break;
	case SDLK_F5:
		keyID[keyb_F5] = keystate;
		break;
	case SDLK_F6:
		keyID[keyb_F6] = keystate;
		break;
	case SDLK_F7:
		keyID[keyb_F7] = keystate;
		break;
	case SDLK_F8:
		keyID[keyb_F8] = keystate;
		break;
	case SDLK_F9:
		keyID[keyb_F9] = keystate;
		break;
	case SDLK_F10:
		keyID[keyb_F10] = keystate;
		break;
	case SDLK_F11:
		keyID[keyb_F11] = keystate;
		break;
	case SDLK_F12:
		keyID[keyb_F12] = keystate;
		break;
	}
}

void InputManager::Check_Input() {
	while (SDL_PollEvent(&rawinput)) {

		if (rawinput.type == SDL_QUIT)
			game->SetQuit();

		if (rawinput.type == SDL_WINDOWEVENT) {
			if (rawinput.window.event == SDL_WINDOWEVENT_RESIZED) {
				screen_width = rawinput.window.data1;
				screen_height = rawinput.window.data2;
			}
		}

		if (rawinput.type == SDL_KEYDOWN) {
			TranslateKey(true);
			keypressedstate = true;
		}

		if (rawinput.type == SDL_KEYUP) {
			TranslateKey(false);
			keypressedstate = false;
		}
	}
}

bool InputManager::GetKey(int index) {
	return keyID[index];
}

int InputManager::GetActions(int index) {
	return ActionKeys[index];
}

int InputManager::CheckWindowWidth() {
	return screen_width;
}

int InputManager::CheckWindowHeight() {
	return screen_height;
}

bool InputManager::GetKeyPressedState() {
	return keypressedstate;
}