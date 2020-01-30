#include "ScreenManager.h"
#include "OnePlayerGame.h"
#include "TwoPlayerGame.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager::ScreenManager() 
{
	mInput = InputManager::Instance();
	mMainMenu = new MainMenu();
	mOnePlayerGame = new OnePlayerGame();
	mTwoPlayerGame = new TwoPlayerGame();
	mCurrentScreen = START;
}

ScreenManager::~ScreenManager() 
{
	delete mOnePlayerGame;
	mOnePlayerGame = nullptr;
	delete mTwoPlayerGame;
	mTwoPlayerGame = nullptr;
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
			if(mMainMenu->mSelectedMode == 0)
				mCurrentScreen = ONEPLAYER;
			if (mMainMenu->mSelectedMode == 1)
				mCurrentScreen = TWOPLAYER;
		}
		break;

	case ONEPLAYER:

		mOnePlayerGame->Update();
		if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) 
		{
			mCurrentScreen = START;
		}

		break;

	case TWOPLAYER:

		mTwoPlayerGame->Update();

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
	case ONEPLAYER:
		mOnePlayerGame->Render();
		break;
	case TWOPLAYER:
		mTwoPlayerGame->Render();
		break;

	}
}

void ScreenManager::SetCurrentScreen(int screen)
{
	mCurrentScreen = Screens(screen);
}