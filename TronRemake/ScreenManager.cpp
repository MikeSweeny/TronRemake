#include "ScreenManager.h"
#include "GameScreenHud.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager::ScreenManager() 
{
	mInput = InputManager::Instance();
	mMainMenu = new MainMenu();
	mGameHud = new GameScreenHud();
	mCurrentScreen = START;
}

ScreenManager::~ScreenManager() 
{
	mInput = nullptr;
	delete mMainMenu;
	mMainMenu = nullptr;
}

ScreenManager* ScreenManager::Instance() 
{
	if (sInstance == nullptr) 
	{
		sInstance = new ScreenManager();
	}
	return sInstance;
}

void ScreenManager::Release() 
{
	delete sInstance;
	sInstance = nullptr;
}

void ScreenManager::Update() 
{
	switch (mCurrentScreen) 
	{
	case START:
		mMainMenu->Update();

		if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) 
		{
			mCurrentScreen = PLAY;
		}
		if (mInput->KeyPressed(SDL_SCANCODE_M))
		{
			mCurrentScreen = MAIN;
		}
		break;
	case PLAY:
		if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) 
		{
			mCurrentScreen = START;
		}
		break;
	case MAIN:
		mGameHud->Update();
		if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE))
		{
			mCurrentScreen = START;
		}
		break;
	}
}

void ScreenManager::Render() 
{
	switch (mCurrentScreen) 
	{
	case START:
		mMainMenu->Render();
		break;
	case PLAY:
		break;
	case MAIN:
		mGameHud->Render();
		break;
	}
}

