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
	playerBike = new PlayerBike();
	aiBike = new AIBike();
	playerBike->Parent(mPlayArea);
	aiBike->Parent(mPlayArea);

	SetupGame();
}

OnePlayerGame::~OnePlayerGame()
{

}

void OnePlayerGame::Update()
{
	playerBike->Update();

	aiBike->Update();
	if (playerBike->IsDead())
	{
		isGameOver = true;
	}
	if (aiBike->IsDead())
	{
		SetupGame();
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
	isGameOver = false;

	playerBike->SetupPlayer();
	aiBike->SetupPlayer();
}