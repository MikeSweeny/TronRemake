#include "ScoreHud.h"
#include "OnePlayerGame.h"
#include <iostream>
#include <string>

using namespace std;
ScoreHud::ScoreHud()
{


	mScore = new Texture("HISCORE", "Computerfont.ttf", 32, { 0, 68, 240 });
	mScoreAmt = new Texture("0", "Computerfont.ttf", 32, { 0, 68, 240 });
	mHiScoreAmt = new Texture("0000", "Computerfont.ttf", 32, { 0, 68, 240 });

	mLives1 = new Texture("&", "Computerfont.ttf", 32, { 0, 68, 240 });
	mLives2 = new Texture("&", "Computerfont.ttf", 32, { 0, 68, 240 });
	mLives3 = new Texture("&", "Computerfont.ttf", 32, { 0, 68, 240 });


	mScore->Position(45.0f, -300.0f);
	mScoreAmt->Position(-128.0f, -270.0f);
	mHiScoreAmt->Position(45.0f, -270.0f);
	mLives1->Position(-145.0f, -300.0f);
	mLives2->Position(-125.0f, -300.0f);
	mLives3->Position(-105.0f, -300.0f);

	mScore->Parent(this);
	mScoreAmt->Parent(this);
	mHiScoreAmt->Parent(this);
	mLives1->Parent(this);
	mLives2->Parent(this);
	mLives3->Parent(this);

}

ScoreHud::~ScoreHud()
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

void ScoreHud::SetHighScore(int score)
{
}

void ScoreHud::SetPlayerScore(int score)
{
}

void ScoreHud::SetLives(int lives)
{
}

void ScoreHud::Update()
{
	int ScoreValue = mPlayerBike->Score();

}

void ScoreHud::Render()
{
	mScore->Render();
	mScoreAmt->Render();
	mHiScoreAmt->Render();
	mScore->Render();
	mLives1->Render();
	mLives2->Render();
	mLives3->Render();

}