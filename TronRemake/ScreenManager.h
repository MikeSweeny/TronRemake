#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H
#include "MainMenu.h"
#include "OnePlayerGame.h"
#include "TwoPlayerGame.h"

class ScreenManager 
{

private:
	static ScreenManager* sInstance;
	enum Screens { TWOPLAYER, START, ONEPLAYER };
	Screens mCurrentScreen;
	InputManager* mInput;
	MainMenu* mMainMenu;
	OnePlayerGame* mOnePlayerGame;
	TwoPlayerGame* mTwoPlayerGame;

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