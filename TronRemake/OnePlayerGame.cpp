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
	playerBike->Position(p1Start);
	playerBike->Active(true);
	playerBike->Score();
	playerBike->Lives();

	aiBike->Visible(true);
	aiBike->Position(p2Start);
	aiBike->Active(true);
	std::cout << playerBike->Position(Local).x << " " << playerBike->Position(Local).y << std::endl;
	std::cout << aiBike->Position(Local).x << " " << aiBike->Position(Local).y << std::endl;
}