#ifndef __TWOPLAYERGAME_H
#define __TWOPLAYERGAME_H
#include "MainMenu.h"

using namespace SDLFramework;

class TwoPlayerGame : public GameEntity
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
	TwoPlayerGame();
	~TwoPlayerGame();
	void Render();
	void Update();
	void LoseLife();
	void UpdateScore();
};

#endif

