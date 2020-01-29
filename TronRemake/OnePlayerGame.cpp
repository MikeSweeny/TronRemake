#include "OnePlayerGame.h"


OnePlayerGame::OnePlayerGame()
{
	mOnePlayerGameScreen = new GameEntity(GraphicsManager::SCREEN_WIDTH * 0.5f, GraphicsManager::SCREEN_HEIGHT * 0.35f);

	mScoreHud = new ScoreHud();
	mScoreHud->Parent(this);
	mScoreHud->Position(530, 325);

	// Play Area
	imageSize = 810;
	mPlayArea = new GameEntity(107, 70);
	mPlayArea->Parent(this);

	backGround = new Texture("lightBikeBG.png");
	backGround->Parent(mPlayArea);
	backGround->Position((imageSize / 2), (imageSize / 2));

	// Bikes
	playerBike = new Bike();
	playerBike->Visible(true);
	playerBike->Parent(mPlayArea);
	playerBike->Position(405, 405);
	playerBike->Active(true);
}

OnePlayerGame::~OnePlayerGame()
{

}

void OnePlayerGame::Update()
{
	//std::cout << "x: " << playerBike->Position().x << "   y: " << playerBike->Position().y << std::endl;
	playerBike->Update();
	//UpdateScore();
}


void OnePlayerGame::Render()
{
	backGround->Render();
	playerBike->Render();
	mScoreHud->Render();
}
