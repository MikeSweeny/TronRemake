#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H
#include "StartScreen.h"
#include "PlayScreen.h"

class ScreenManager 
{

private:
	static ScreenManager* sInstance;
	enum Screens { Start, Play };
	Screens mCurrentScreen;

	PlayScreen* mPlayScreen;
	InputManager* mInput;
	BackgroundStars* mBackgroundStars;
	StartScreen* mStartScreen;

public:
	static ScreenManager* Instance();
	static void Release();

	void Update();
	void Render();
	ScreenManager();
	~ScreenManager();

private:

};
#endif