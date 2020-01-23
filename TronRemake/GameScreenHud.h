#ifndef __GAMEHUD_H
#define __GAMEHUD_H
#include "MainMenu.h"
class GameScreenHud
{
private:
	GameEntity* mGameHud;

	Texture* mScoreAmt;
	Texture* mHiScoreAmt;
	Texture* mScore;
	Texture* mLives1;
	Texture* mLives2;
	Texture* mLives3;

	Texture* mP2ScoreAmt;
	Texture* mP2HiScoreAmt;
	Texture* mP2Score;
	Texture* mP2Lives1;
	Texture* mP2Lives2;
	Texture* mP2Lives3;
public:
	GameScreenHud();
	~GameScreenHud();
	void Render();
	void Update();

};

#endif

