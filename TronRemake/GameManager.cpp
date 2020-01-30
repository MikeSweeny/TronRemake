#include "GameManager.h"

namespace SDLFramework 
{
	GameManager* GameManager::sInstance = nullptr;
	
	GameManager* GameManager::Instance()
	{
		if (sInstance == nullptr) 
		{
			sInstance = new GameManager();
		}
		return sInstance;
	}

	void GameManager::Release() 
	{
		delete sInstance;
		sInstance = nullptr;
	}

	void GameManager::Run() 
	{
		// main game loop
		while (!mQuit) 
		{
			mTimer->Update();
			// event processing loop
			while (SDL_PollEvent(&mEvent)) 
			{
				switch (mEvent.type) 
				{
				case SDL_QUIT:
					mQuit = true;
					break;
				}
			}
			if (mTimer->GetDeltaTime() >= 1.0f / FRAME_RATE)
			{
				Update();
				LateUpdate();
				Render();
				mTimer->Reset();
			}
		}
	}

	void GameManager::Update() 
	{
		mInputManager->Update();
		mScreenManager->Update();

		//PlayerOneInputUpdate();
		//PlayerTwoInputUpdate();
		
		if (mInputManager->KeyDown(SDL_SCANCODE_1))
		{
			mAudioManager->PlaySFX("SFX/59873__uzerx__lazer.wav", 0, -1);
		}
		if (mInputManager->KeyDown(SDL_SCANCODE_2))
		{
			mAudioManager->PlaySFX("SFX/243020__plasterbrain__game-start.wav", 0, 0);
		}

		// Anything after this comment is just printing shit
		if (mInputManager->KeyPressed(SDL_SCANCODE_SPACE)) 
		{
			std::cout << "Space pressed!" << std::endl;
		}
		if (mInputManager->KeyReleased(SDL_SCANCODE_SPACE)) 
		{
			std::cout << "Space released!" << std::endl;
		}
		if (mInputManager->MouseButtonPressed(InputManager::Left)) 
		{
			std::cout << "Left mouse button pressed!" << std::endl;
		}
		if (mInputManager->MouseButtonReleased(InputManager::Left)) 
		{
			std::cout << "Left mouse button released!" << std::endl;
		}
	}

	void GameManager::LateUpdate() 
	{
		mInputManager->UpdatePrevInput();
	}

	void GameManager::Render() 
	{
		mGraphics->ClearBackBuffer();
		mScreenManager->Render();
		mGraphics->Render();
	}

	//void GameManager::PlayerOneInputUpdate()
	//{
	//	if (mInputManager->KeyDown(SDL_SCANCODE_W)) //Forward and Back
	//	{
	//		//->Translate(Vector2(0, -80.0f) * mTimer->GetDeltaTime(), GameEntity::World);
	//	}
	//	else if (mInputManager->KeyDown(SDL_SCANCODE_S))
	//	{
	//		//->Translate(Vector2(0, 80.0f) * mTimer->GetDeltaTime(), GameEntity::World);
	//	}
	//	if (mInputManager->KeyDown(SDL_SCANCODE_A)) //Left and Right
	//	{
	//		//->Translate(Vector2(-80.0f, 0) * mTimer->GetDeltaTime(), GameEntity::World);
	//	}
	//	else if (mInputManager->KeyDown(SDL_SCANCODE_D))
	//	{
	//		//->Translate(Vector2(80.0f, 0) * mTimer->GetDeltaTime(), GameEntity::World);
	//	}
	//	if (mInputManager->KeyDown(SDL_SCANCODE_Q)) //Rotate Left and Right
	//	{
	//		//->Rotate((-25) * mTimer->GetDeltaTime());
	//	}
	//	else if (mInputManager->KeyDown(SDL_SCANCODE_E))
	//	{
	//		//->Rotate((25) * mTimer->GetDeltaTime());
	//	}
	//	if (mInputManager->KeyDown(SDL_SCANCODE_Z)) //Scale Up and Down
	//	{
	//		//Vector2 tempScale = mTex->Scale();
	//		//tempScale += Vector2(0.1f, 0.1f);
	//		//mTex->Scale(tempScale);
	//		//mTex->Translate(Vector2(-120.0f, -120.0f) * mTimer->GetDeltaTime(), GameEntity::World);
	//	}
	//	else if (mInputManager->KeyDown(SDL_SCANCODE_C))
	//	{
	//		//Vector2 tempScale = mTex->Scale();
	//		//tempScale -= Vector2(0.1f, 0.1f);
	//		//mTex->Scale(tempScale);
	//		//mTex->Translate(Vector2(120.0f, 120.0f) * mTimer->GetDeltaTime(), GameEntity::World);
	//	}
	//}

	//void GameManager::PlayerTwoInputUpdate()
	//{
	//	if (mInputManager->KeyDown(SDL_SCANCODE_I)) //Forward and Back
	//	{
	//		//->Translate(Vector2(0, -80.0f) * mTimer->GetDeltaTime(), GameEntity::World);
	//	}
	//	else if (mInputManager->KeyDown(SDL_SCANCODE_K))
	//	{
	//		//->Translate(Vector2(0, 80.0f) * mTimer->GetDeltaTime(), GameEntity::World);
	//	}
	//	if (mInputManager->KeyDown(SDL_SCANCODE_J)) //Left and Right
	//	{

	//	}
	//	else if (mInputManager->KeyDown(SDL_SCANCODE_L))
	//	{

	//	}
	//	if (mInputManager->KeyDown(SDL_SCANCODE_U)) //Rotate Left and Right
	//	{

	//	}
	//	else if (mInputManager->KeyDown(SDL_SCANCODE_O))
	//	{

	//	}
	//	if (mInputManager->KeyDown(SDL_SCANCODE_M)) //Scale Up and Down
	//	{

	//	}
	//	else if (mInputManager->KeyDown(SDL_SCANCODE_PERIOD))
	//	{

	//	}
	//}

	GameManager::GameManager() : mQuit(false) 
	{
		// create Graphics singleton
		mGraphics = GraphicsManager::Instance();
		// create timer singleton
		mTimer = Timer::GetInstance();
		// verify Graphics module is ready
		if (!GraphicsManager::Initialized())
		{
			mQuit = true;
		}
		mAssetManager = AssetManager::Instance();
		mInputManager = InputManager::Instance();
		mAudioManager = AudioManager::Instance();

		mAudioManager->PlayMusic("SFX/478313__skibkamusic__skibka-music-theoretical-perspectives.wav", 0);

		mScreenManager = ScreenManager::Instance();
	}

	GameManager::~GameManager() 
	{
		// release modules
		delete mScreenManager;
		mScreenManager = nullptr;

		GraphicsManager::Release();
		mGraphics = nullptr;
		Timer::Release();
		mTimer = nullptr;
		AssetManager::Release();
		mAssetManager = nullptr;
		InputManager::Release();
		mInputManager = nullptr;

		AudioManager::Release();
		mAudioManager = nullptr;
		InputManager::Release();
		mInputManager = nullptr;

		// Quit SDL subsystems
		SDL_Quit();
	}
}