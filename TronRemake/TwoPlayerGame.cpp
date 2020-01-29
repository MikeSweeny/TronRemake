#include "TwoPlayerGame.h"

TwoPlayerGame::TwoPlayerGame()
{
	mTwoPlayerGameScreen = new GameEntity(GraphicsManager::SCREEN_WIDTH * 0.5f, GraphicsManager::SCREEN_HEIGHT * 0.35f);

	mScoreHud = new ScoreHud();
	mScoreHud->Parent(this);
	mScoreHud->Position(330, 325);

	mP2ScoreHud = new ScoreHud();
	mP2ScoreHud->Parent(this);
	mP2ScoreHud->Position(730, 325);
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

TwoPlayerGame::~TwoPlayerGame()
{

}

void TwoPlayerGame::Update()
{
	playerBike->Update();

	//UpdateScore();
}


void TwoPlayerGame::Render()
{
	backGround->Render();
	playerBike->Render();
	mScoreHud->Render();
	mP2ScoreHud->Render();

}
