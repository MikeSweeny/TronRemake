#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H
#include <SDL.h>
#include "AnimatedTexture.h"
#include "Timer.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "ScreenManager.h"

namespace SDLFramework 
{
	class GameManager 
	{

	public:
		GameManager();
		~GameManager();
		static GameManager* Instance();
		static void Release();

		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		// singleton
		static GameManager* sInstance;
		// loop control
		bool mQuit;
		// modules
		GraphicsManager* mGraphics;
		SDL_Event mEvent;
		// timer variables
		const int FRAME_RATE = 60;
		Timer* mTimer;

		// Asset/textures
		AssetManager* mAssetManager;
		InputManager* mInputManager;
		AudioManager* mAudioManager;

		AnimatedTexture* mTex;
		Texture* mTexTwo;
		Texture* mFontTexture;

		const float scaleIncrement = 2.0f;
		void PlayerOneInputUpdate();
		void PlayerTwoInputUpdate();

		ScreenManager* mScreenManager;
	};
}

#endif