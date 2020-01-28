#ifndef __ONEPLAYER_H
#define __ONEPLAYER_H
#include "MainMenu.h"

using namespace SDLFramework;

class OnePlayerGame : public GameEntity
{

private:
	GameEntity* mOnePlayerGameScreen;

	Texture* mScoreAmt;
	Texture* mHiScoreAmt;
	Texture* mScore;
	Texture* mLives1;
	Texture* mLives2;
	Texture* mLives3;

	// play area
	float imageSize;
	GameEntity* mPlayArea;
	Texture* backGround;

public:
	OnePlayerGame();
	~OnePlayerGame();
	void Render();
	void Update();
	void UpdateLives();
	void UpdateScore();

};

#endif

