#ifndef __SCOREHUD
#define __SCOREHUD
#include "AnimatedTexture.h"
using namespace SDLFramework;

class ScoreHud : public GameEntity
{
private:
	GameEntity* mScoreHud;
	Texture* mScoreAmt;
	Texture* mHiScoreAmt;
	Texture* mScore;
	Texture* mLives1;
	Texture* mLives2;
	Texture* mLives3;


	Texture* mP2ScoreAmt;
	Texture* mP2HiScoreAmt;
	Texture* mP2Score;


public:

	ScoreHud();
	~ScoreHud();
	void SetHighScore(int score);
	void SetPlayerScore(int score);    
	void SetLives(int lives);
	int playerScore;
	int playerLives;

	void Render();
};
#endif
