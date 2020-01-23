#include "TwoPlayerGame.h"

TwoPlayerGame::TwoPlayerGame()
{
	mGameHud = new GameEntity(GraphicsManager::SCREEN_WIDTH * 0.5f, GraphicsManager::SCREEN_HEIGHT * 0.35f);

	mScore = new Texture("HISCORE", "Computerfont.ttf", 32, { 0, 68, 240 });
	mScoreAmt = new Texture("0", "Computerfont.ttf", 32, { 0, 68, 240 });
	mHiScoreAmt = new Texture("00000", "Computerfont.ttf", 32, { 0, 68, 240 });
	mLives1 = new Texture("&", "Computerfont.ttf", 32, { 0, 68, 240 });
	mLives2 = new Texture("&", "Computerfont.ttf", 32, { 0, 68, 240 });
	mLives3 = new Texture("&", "Computerfont.ttf", 32, { 0, 68, 240 });

	mScore->Parent(mGameHud);
	mScoreAmt->Parent(mGameHud);
	mHiScoreAmt->Parent(mGameHud);
	mLives1->Parent(mGameHud);
	mLives2->Parent(mGameHud);
	mLives3->Parent(mGameHud);


	mScore->Position	(-165.0f, -300.0f);
	mScoreAmt->Position	(-328.0f, -270.0f);
	mHiScoreAmt->Position(-165.0f, -270.0f);
	mLives1->Position	(-365.0f, -300.0f);
	mLives2->Position	(-345.0f, -300.0f);
	mLives3->Position	(-325.0f, -300.0f);

	mP2Score = new Texture("HISCORE", "Computerfont.ttf", 32, { 237, 237, 12 });
	mP2ScoreAmt = new Texture("0", "Computerfont.ttf", 32, { 237, 237, 12 });
	mP2HiScoreAmt = new Texture("00000", "Computerfont.ttf", 32, { 237, 237, 12 });
	mP2Lives1 = new Texture("&", "Computerfont.ttf", 32, { 237, 237, 12 });
	mP2Lives2 = new Texture("&", "Computerfont.ttf", 32, { 237, 237, 12 });
	mP2Lives3 = new Texture("&", "Computerfont.ttf", 32, { 237, 237, 12 });

	mP2Score->Parent(mGameHud);
	mP2ScoreAmt->Parent(mGameHud);
	mP2HiScoreAmt->Parent(mGameHud);
	mP2Lives1->Parent(mGameHud);
	mP2Lives2->Parent(mGameHud);
	mP2Lives3->Parent(mGameHud);


	mP2Score->Position	(165.0f, -300.0f);
	mP2ScoreAmt->Position	(328.0f, -270.0f);
	mP2HiScoreAmt->Position(165.0f, -270.0f);
	mP2Lives1->Position	(365.0f, -300.0f);
	mP2Lives2->Position	(345.0f, -300.0f);
	mP2Lives3->Position	(325.0f, -300.0f);


}

TwoPlayerGame::~TwoPlayerGame()
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
	delete mP2HiScoreAmt;
	mP2HiScoreAmt = nullptr;
	delete mP2ScoreAmt;
	mP2ScoreAmt = nullptr;
	delete mP2Score;
	mP2Score = nullptr;
	delete mP2Lives1;
	mP2Lives1 = nullptr;
	delete mP2Lives2;
	mP2Lives2 = nullptr;
	delete mP2Lives3;
	mP2Lives3 = nullptr;

}

void TwoPlayerGame::Update()
{
	//UpdateScore();
}

void TwoPlayerGame::LoseLife()
{
	//If the player hits a players wall
	// check which player hit a wall
	// remove a life counter from that player
	// reset the players to starting points

}
void TwoPlayerGame::UpdateScore()
{
	// this checks if something will change the score, and will set the  text string in the mScore texture to the current players score

}

void TwoPlayerGame::Render()
{
	mScoreAmt->Render();
	mHiScoreAmt->Render();
	mScore->Render();
	mLives1->Render();
	mLives2->Render();
	mLives3->Render();
	mP2ScoreAmt->Render();
	mP2HiScoreAmt->Render();
	mP2Score->Render();
	mP2Lives1->Render();
	mP2Lives2->Render();
	mP2Lives3->Render();
}
