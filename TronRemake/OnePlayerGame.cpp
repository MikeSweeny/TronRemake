#include "OnePlayerGame.h"

OnePlayerGame::OnePlayerGame()
{
	mOnePlayerGameScreen = new GameEntity(GraphicsManager::SCREEN_WIDTH * 0.5f, GraphicsManager::SCREEN_HEIGHT * 0.35f);

	mScore = new Texture("HISCORE", "Computerfont.ttf", 32, { 0, 68, 240 });
	mScoreAmt = new Texture("0", "Computerfont.ttf", 32, { 0, 68, 240 });
	mHiScoreAmt = new Texture("00000", "Computerfont.ttf", 32, { 0, 68, 240 });
	mLives1 = new Texture("&", "Computerfont.ttf", 32, { 0, 68, 240 });
	mLives2 = new Texture("&", "Computerfont.ttf", 32, { 0, 68, 240 });
	mLives3 = new Texture("&", "Computerfont.ttf", 32, { 0, 68, 240 });

	mScore->Parent(mOnePlayerGameScreen);
	mScoreAmt->Parent(mOnePlayerGameScreen);
	mHiScoreAmt->Parent(mOnePlayerGameScreen);
	mLives1->Parent(mOnePlayerGameScreen);
	mLives2->Parent(mOnePlayerGameScreen);
	mLives3->Parent(mOnePlayerGameScreen);


	mScore->Position(45.0f, -300.0f);
	mScoreAmt->Position(-128.0f, -270.0f);
	mHiScoreAmt->Position(45.0f, -270.0f);
	mLives1->Position(-145.0f, -300.0f);
	mLives2->Position(-125.0f, -300.0f);
	mLives3->Position(-105.0f, -300.0f);

	// Play Area
	imageSize = 810;
	mPlayArea = new GameEntity(0, 0);
	mPlayArea->Parent(this);

	backGround = new Texture("lightBikeBG.png");
	backGround->Parent(mPlayArea);
	backGround->Position((imageSize / 2) + 107, (imageSize / 2) + 70);
}

OnePlayerGame::~OnePlayerGame()
{
	delete mHiScoreAmt;
	mHiScoreAmt = nullptr;
	delete mScoreAmt;
	mScoreAmt = nullptr;
	delete mScore;
	mScore = nullptr;
	delete mLives1;
	mLives1 = nullptr;
	delete mLives2;
	mLives2 = nullptr;
	delete mLives3;
	mLives3 = nullptr;

}

void OnePlayerGame::Update()
{
	//UpdateScore();
}

void OnePlayerGame::UpdateLives()
{
	// Just a simple function to update the UI for Lives, same as the UpdateScore Function

}

void OnePlayerGame::UpdateScore()
{
	// this checks if something will change the score, and will set the  text string in the mScore texture to the current players score
	
}

void OnePlayerGame::Render()
{
	mScoreAmt->Render();
	mHiScoreAmt->Render();
	mScore->Render();
	mLives1->Render();
	mLives2->Render();
	mLives3->Render();

	backGround->Render();
}
