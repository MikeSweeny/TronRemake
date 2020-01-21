#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "AudioManager.h"
#include "BackgroundStars.h"
#include "GameEntity.h"
#include "PlaySideBar.h"

using namespace SDLFramework;

class PlayScreen : public GameEntity
{

private:
	Timer* mTimer;
	AudioManager* mAudio;
	BackgroundStars* mStars;
	PlaySideBar* mSideBar;

public:
	PlayScreen();
	~PlayScreen();
	void Update();
	void Render();

};

#endif