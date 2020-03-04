#include "OnePlayerGame.h"


OnePlayerGame::OnePlayerGame()
{
	mOnePlayerGameScreen = new GameEntity(GraphicsManager::SCREEN_WIDTH * 0.5f, GraphicsManager::SCREEN_HEIGHT * 0.35f);
	mScoreHud = new ScoreHud();
	mScoreHud->Parent(this);
	mScoreHud->Position(530, 325);
	isGameOver = false;
	// Play Area
	imageSize = 810;
	mPlayArea = new GameEntity(107, 70);
	mPlayArea->Parent(this);

	backGround = new Texture("lightBikeBG.png");
	backGround->Parent(mPlayArea);
	backGround->Position((imageSize / 2), (imageSize / 2));

	// Bikes
	playerBike = new PlayerBike();
	aiBike = new AIBike();

	SetupGame();
}

OnePlayerGame::~OnePlayerGame()
{

}

void OnePlayerGame::Update()
{
	playerBike->Update();
	//UpdateScore();

	aiBike->Update();
	if (playerBike->IsDead())
	{
		isGameOver = true;
	}
}

void OnePlayerGame::Render()
{
	backGround->Render();
	playerBike->Render();
	mScoreHud->Render();

	aiBike->Render();
}

void OnePlayerGame::SetupGame()
{
	playerBike->Visible(true);
	playerBike->Parent(mPlayArea);
	playerBike->Position(p1StartX, p1StartY);
	playerBike->Active(true);
	playerBike->Score();
	playerBike->Lives();

	aiBike->Visible(true);
	aiBike->Parent(mPlayArea);
	aiBike->Position(p2StartX, p2StartY);
	aiBike->Active(true);
}