#ifndef __ONEPLAYER_H
#define __ONEPLAYER_H
#include "MainMenu.h"
#include "Bike.h"
#include "ScoreHud.h"
#include "PlayerBike.h"
#include "AIBike.h"

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
	Vector2* startPos = new Vector2(405, 765);

	// Player Bike
	PlayerBike* playerBike;

	// AI Bike
	AIBike* aiBike;

public:
	OnePlayerGame();
	~OnePlayerGame();
	void Render();
	void Update();

};

#endif

