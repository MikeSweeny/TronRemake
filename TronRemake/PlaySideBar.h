#ifndef __PLAYSIDEBAR_H
#define __PLAYSIDEBAR_H
#include "Timer.h"
#include "Scoreboard.h"
#include "AudioManager.h"

class PlaySideBar : public GameEntity 
{

private:
	Timer* mTimer;
	AudioManager* mAudio;
	Texture* mBackground;

public:
	PlaySideBar();
	~PlaySideBar();
	void Update();
	void Render();

};

#endif