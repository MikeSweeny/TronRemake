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
	playerBike = new PlayerBike();
	playerBike->Visible(true);
	playerBike->Parent(mPlayArea);
	playerBike->Position(405, 405);
	playerBike->Active(true);

	player2Bike = new Player2Bike();
	player2Bike->Visible(true);
	player2Bike->Parent(mPlayArea);
	player2Bike->Position(405, 5);
	player2Bike->Active(true);

}

TwoPlayerGame::~TwoPlayerGame()
{

}

void TwoPlayerGame::Update()
{
	playerBike->Update();
	player2Bike->Update();
	//UpdateScore();
}


void TwoPlayerGame::Render()
{
	backGround->Render();
	player2Bike->Render();
	playerBike->Render();
	mScoreHud->Render();
	mP2ScoreHud->Render();

}
