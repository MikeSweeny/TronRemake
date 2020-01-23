#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H
#include "MainMenu.h"
#include "GameScreenHud.h"

class ScreenManager 
{

private:
	static ScreenManager* sInstance;
	enum Screens { MAIN, START, PLAY };
	Screens mCurrentScreen;
	InputManager* mInput;
	MainMenu* mMainMenu;
	GameScreenHud* mGameHud;

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