#ifndef __SCOREHUD
#define __SCOREHUD
#include "AnimatedTexture.h"
#include "Bike.h"
#include "PlayerBike.h"
#include "Player2Bike.h"

using namespace SDLFramework;

class ScoreHud : public GameEntity
{
private:
	GameEntity* mScoreHud;

	PlayerBike* mPlayerBike;
	Player2Bike* mPlayer2Bike;

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
	void Update();
	void Render();
};
#endif
