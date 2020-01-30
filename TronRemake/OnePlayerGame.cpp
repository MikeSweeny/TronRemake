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
		GameOver();
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

	aiBike->Visible(true);
	aiBike->Parent(mPlayArea);
	aiBike->Position(205, 205);
	aiBike->Active(true);
}

void OnePlayerGame::GameOver()
{
	//ScreenManager::Instance()->SetCurrentScreen(0);
}