#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>

enum keys {
	KEYDEFAULT,

	//Keyboard keys: keyb_ prefix

	keyb_0, keyb_1, keyb_2, keyb_3, keyb_4, keyb_5, keyb_6, keyb_7, keyb_8, keyb_9,

	keyb_A, keyb_B, keyb_C, keyb_D, keyb_E, keyb_F, keyb_G, keyb_H, keyb_I, keyb_J, keyb_K, keyb_L, keyb_M, keyb_N, keyb_O, keyb_P,
	keyb_Q, keyb_R, keyb_S, keyb_T, keyb_U, keyb_V, keyb_W, keyb_X, keyb_Y, keyb_Z, keyb_Ç,

	keyb_BackSlash, keyb_Interrogation, keyb_Plus, keyb_Score,

	keyb_TAB, keyb_CAPSLOCK, keyb_LSHIFT, keyb_LCTRL, keyb_LALT, keyb_SPACE, keyb_BACKSPACE, keyb_ENTER, keyb_RSHIFT, keyb_RCTRL,
	keyb_RALT, keyb_PRINT, keyb_SCROLL, keyb_BREAK, keyb_INSERT, keyb_HOME, keyb_PAGEUP, keyb_PAGEDOWN, keyb_END, keyb_DELETE,
	keyb_ESCAPE,

	keyb_UPARROW, keyb_DOWNARROW, keyb_LEFTARROW, keyb_RIGHTARROW,

	keyb_NUMLOCK, keyb_SLASH, keyb_STAR, keyb_MINUS, keyb_PLUS, keyb_NUMENTER, keyb_NUMDOT,
	keyb_NUM0, keyb_NUM1, keyb_NUM2, keyb_NUM3, keyb_NUM4, keyb_NUM5, keyb_NUM6, keyb_NUM7, keyb_NUM8, keyb_NUM9,

	keyb_F1, keyb_F2, keyb_F3, keyb_F4, keyb_F5, keyb_F6, keyb_F7, keyb_F8, keyb_F9, keyb_F10, keyb_F11, keyb_F12,

	//Mouse keys: mouse_ prefix

	mouse_SCROLLUP, mouse_SCROLLDOWN, mouse_CLICKSCROLL, mouse_LEFTBUTTON, mouse_RIGHTBUTTON, mouse_moveX, mouse_moveY,

	//GamePad keys: GP_ prefix (GP = Game Pad)

	GP_UP, GP_DOWN, GP_LEFT, GP_RIGHT, GP_SELECT, GP_START,
	GP_ANALOG, GP_JOYSTICK1_XPLUS, GP_JOYSTICK1_XMINUS, GP_JOYSTICK1_YPLUS, GP_JOYSTICK1_YMINUS, GP_JOYSTICK1_CLICK,
	GP_JOYSTICK2_XPLUS, GP_JOYSTICK2_XMINUS, GP_JOYSTICK2_YPLUS, GP_JOYSTICK2_YMINUS, GP_JOYSTICK2_CLICK,
	GP_A, GP_B, GP_Y, GP_X, //these controls can be Triangle, Square, Circle and the X on the playstation controller, etc...
	GP_L1, GP_L2, GP_L3, GP_R1, GP_R2, GP_R3,

	TOTALKEYS
};

enum keyActions {
	DefaultAction,

	Action_START, Action_PlayerMOVEUP, Action_PlayerMOVEDOWN, Action_PlayerMOVELEFT, Action_PlayerMOVERIGHT, Action_PlayerINTERACTION,
	Action_PAUSE, Action_BACK, Action_CamZoomIn, Action_CamZoomOut,

	TOTALACTIONS
};

class Application;

class InputManager {
private:
	Application* game;
	int keyID[TOTALKEYS];
	int ActionKeys[TOTALACTIONS];
	SDL_Event rawinput;
	int screen_width, screen_height;
	bool keypressedstate;

private:
	void TranslateKey(bool keystate);

public:
	bool Init(Application* game);
	void Check_Input();
	bool GetKey(int index);
	int GetActions(int index);
	int CheckWindowWidth();
	int CheckWindowHeight();
	bool GetKeyPressedState();
};

#endif