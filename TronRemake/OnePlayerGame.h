#ifndef __ONEPLAYER_H
#define __ONEPLAYER_H
#include "MainMenu.h"
#include "Bike.h"
#include "ScoreHud.h"
#include "PlayerBike.h"

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

	// Player Bike
	PlayerBike* playerBike;

public:
	OnePlayerGame();
	~OnePlayerGame();
	void Render();
	void Update();

};

#endif

