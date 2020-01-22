#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H
#include "StartScreen.h"
#include "PlayScreen.h"
#include "MainMenu.h"

class ScreenManager 
{

private:
	static ScreenManager* sInstance;
	enum Screens { MAIN, START, PLAY };
	Screens mCurrentScreen;

	PlayScreen* mPlayScreen;
	InputManager* mInput;
	BackgroundStars* mBackgroundStars;
	StartScreen* mStartScreen;
	MainMenu* mMainMenu;

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