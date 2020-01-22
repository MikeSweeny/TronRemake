#include "ScreenManager.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager::ScreenManager() 
{
	mInput = InputManager::Instance();
	mBackgroundStars = BackgroundStars::Instance();
	mStartScreen = new StartScreen();
	mPlayScreen = new PlayScreen();
	mMainMenu = new MainMenu();
	mCurrentScreen = START;
}

ScreenManager::~ScreenManager() 
{
	mInput = nullptr;
	BackgroundStars::Release();
	mBackgroundStars = nullptr;
	delete mStartScreen;
	mStartScreen = nullptr;
	delete mPlayScreen;
	mPlayScreen = nullptr;
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
	mBackgroundStars->Update();
	switch (mCurrentScreen) 
	{
	case START:
		mStartScreen->Update();
		if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) 
		{
			mCurrentScreen = PLAY;
			mStartScreen->ResetAnimation();
		}
		if (mInput->KeyPressed(SDL_SCANCODE_M))
		{
			mCurrentScreen = MAIN;
		}
		break;
	case PLAY:
		mPlayScreen->Update();
		if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) 
		{
			mCurrentScreen = START;
		}
		break;
	case MAIN:
		mMainMenu->Update();
		if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE))
		{
			mCurrentScreen = START;
		}
		break;
	}
}

void ScreenManager::Render() 
{
	mBackgroundStars->Render();
	switch (mCurrentScreen) 
	{
	case START:
		mStartScreen->Render();
		break;
	case PLAY:
		mPlayScreen->Render();
		break;
	case MAIN:
		mMainMenu->Render();
		break;
	}
}

