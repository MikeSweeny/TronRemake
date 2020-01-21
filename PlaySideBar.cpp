#include "PlaySideBar.h"

PlaySideBar::PlaySideBar() 
{
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mBackground = new Texture("Black.png");
	mBackground->Parent(this);
}

PlaySideBar::~PlaySideBar() 
{
	mTimer = nullptr;
	mAudio = nullptr;
	delete mBackground;
	mBackground = nullptr;
}

void PlaySideBar::Update() 
{

}

void PlaySideBar::Render() 
{
	mBackground->Render();
}
