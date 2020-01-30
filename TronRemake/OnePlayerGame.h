#ifndef __ONEPLAYERGAME_H
#define __ONEPLAYERGAME_H
#include "MainMenu.h"
#include "Bike.h"
#include "ScoreHud.h"
#include "PlayerBike.h"
#include "AIBike.h"
//#include "ScreenManager.h"

using namespace SDLFramework;

class OnePlayerGame : public GameEntity
{
private:

	GameEntity* mOnePlayerGameScreen;
	ScoreHud* mScoreHud;
	// play area
	float imageSize;
	GameEntity* mPlayArea;
	Texture* backGround;
	float mGameBounds = 810;
	int p1StartX = 405;
	int p1StartY = 765;


	// Player Bike
	PlayerBike* playerBike;

	// AI Bike
	AIBike* aiBike;

public:

	bool isGameOver;
	OnePlayerGame();
	~OnePlayerGame();
	void Render();
	void Update();

	void SetupGame();

};

#endif

