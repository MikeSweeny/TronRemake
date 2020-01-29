#ifndef __TWOPLAYERGAME_H
#define __TWOPLAYERGAME_H
#include "MainMenu.h"
#include "Bike.h"
#include "ScoreHud.h"

using namespace SDLFramework;

class TwoPlayerGame : public GameEntity
{
private:
	GameEntity* mTwoPlayerGameScreen;
	ScoreHud* mScoreHud;
	ScoreHud* mP2ScoreHud;
	// play area
	float imageSize;
	GameEntity* mPlayArea;
	Texture* backGround;
	float mGameBounds = 810;

	// Player Bike
	Bike* playerBike;

public:
	TwoPlayerGame();
	~TwoPlayerGame();
	void Render();
	void Update();
};

#endif

