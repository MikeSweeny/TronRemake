#ifndef __INPUTMANAGER_H
#define __INPUTMANAGER_H
#include <SDL.h>
#include "MathHelper.h"

namespace SDLFramework 
{
	class InputManager
	{

	public:
		enum MouseButton { Left = 0, Right, Middle, Back, Forward };

		static InputManager* Instance();
		static void Release();

		bool KeyDown(SDL_Scancode scancode);
		bool KeyPressed(SDL_Scancode scancode);
		bool KeyReleased(SDL_Scancode scancode);

		void Update();
		void UpdatePrevInput();
		bool MouseButtonDown(MouseButton button);
		bool MouseButtonPressed(MouseButton button);
		bool MouseButtonReleased(MouseButton button);
		Vector2 MousePosition();

	private:
		static InputManager* sInstance;
		const Uint8* mKeyboardState;
		Uint8* mPrevKeyboardState;
		int mKeyLength;

		Uint32 mPrevMouseState;
		Uint32 mMouseState;
		int mMouseXPos;
		int mMouseYPos;

		InputManager();
		~InputManager();

	};
}
#endif