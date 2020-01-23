#include "PlayScreen.h"

PlayScreen::PlayScreen() 
{
	mTimer = Timer::GetInstance();
	mAudio = AudioManager::Instance();
	mStars = BackgroundStars::Instance();
	mSideBar = new PlaySideBar();
	mSideBar->Parent(this);
	mSideBar->Position(GraphicsManager::SCREEN_WIDTH * 0.5f, GraphicsManager::SCREEN_HEIGHT * 0.5f);
}

PlayScreen::~PlayScreen() 
{
	mTimer = nullptr;
	mAudio = nullptr;
	mStars = nullptr;
	delete mSideBar;
	mSideBar = nullptr;
}

void PlayScreen::Update() 
{
	mSideBar->Update();
}

void PlayScreen::Render() 
{
	mSideBar->Render();
}