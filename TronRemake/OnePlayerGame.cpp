#include "OnePlayerGame.h"

OnePlayerGame::OnePlayerGame()
{
	mOnePlayerGame = new GameEntity(GraphicsManager::SCREEN_WIDTH * 0.5f, GraphicsManager::SCREEN_HEIGHT * 0.35f);

	mScore = new Texture("HISCORE", "Computerfont.ttf", 32, { 0, 68, 240 });
	mScoreAmt = new Texture("0", "Computerfont.ttf", 32, { 0, 68, 240 });
	mHiScoreAmt = new Texture("00000", "Computerfont.ttf", 32, { 0, 68, 240 });
	mLives1 = new Texture("&", "Computerfont.ttf", 32, { 0, 68, 240 });
	mLives2 = new Texture("&", "Computerfont.ttf", 32, { 0, 68, 240 });
	mLives3 = new Texture("&", "Computerfont.ttf", 32, { 0, 68, 240 });

	mScore->Parent(mOnePlayerGame);
	mScoreAmt->Parent(mOnePlayerGame);
	mHiScoreAmt->Parent(mOnePlayerGame);
	mLives1->Parent(mOnePlayerGame);
	mLives2->Parent(mOnePlayerGame);
	mLives3->Parent(mOnePlayerGame);


	mScore->Position(45.0f, -300.0f);
	mScoreAmt->Position(-128.0f, -270.0f);
	mHiScoreAmt->Position(45.0f, -270.0f);
	mLives1->Position(-145.0f, -300.0f);
	mLives2->Position(-125.0f, -300.0f);
	mLives3->Position(-105.0f, -300.0f);

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

void OnePlayerGame::LoseLife()
{
	//If the player hits the enemy
	// remove a life counter
	// I think we just set the text to a null value, then in the gain life function set it back
}

void OnePlayerGame::GainLife()
{
	// if player gains a life
	// add life counter
	//Set the null vaule of the text back to the character we have for a life counter
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
}
