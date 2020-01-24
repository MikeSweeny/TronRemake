#ifndef __ONEPLAYER_H
#define __ONEPLAYER_H
#include "MainMenu.h"
class OnePlayerGame
{

private:
	GameEntity* mOnePlayerGame;

	Texture* mScoreAmt;
	Texture* mHiScoreAmt;
	Texture* mScore;
	Texture* mLives1;
	Texture* mLives2;
	Texture* mLives3;
public:
	OnePlayerGame();
	~OnePlayerGame();
	void Render();
	void Update();
	void LoseLife();
	void GainLife();
	void UpdateScore();

};

#endif

