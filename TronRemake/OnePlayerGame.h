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
	float mGameBounds = 780;
	Vector2 p1Start = Vector2(390.0f, 750.0f);
	Vector2 p2Start = Vector2(390.0f, 60.0f);


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

