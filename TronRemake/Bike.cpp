#include "Bike.h"


void Bike::HandleMovement()
{
}

Bike::Bike()
{
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	mVisible = false;
	mAnimating = false;

	mScore = 0;
	mLives = 3;

	mBike = new Texture("TronSpriteSheet.png", 0, 0, 60, 64);
	mBike->Parent(this);
	mBike->Position(Vec2_Zero);

	mMoveSpeed = 100.0f;
	mScreenBounds = Vector2(0.0f, 800.0f);

	//mDeathAnimation = new AnimatedTexture("PlayerDeath.png", 0, 0, 128, 128, 4, 1.0f, AnimatedTexture::Horizontal);
	//mDeathAnimation->Parent(this);
	//mDeathAnimation->Position(Vec2_Zero);
}

Bike::~Bike()
{
	mInput = nullptr;
	mAudio = nullptr;

	delete mBike;
	mBike = nullptr;
	delete mDeathAnimation;
	mDeathAnimation = nullptr;
}

void Bike::Visible(bool visible)
{
	mVisible = visible;
}

bool Bike::isAnimating()
{
	return mAnimating;
}

int Bike::Score()
{
	return mScore;
}

int Bike::Lives()
{
	return mLives;
}

void Bike::AddScore(int change)
{
	mScore += change;
}

void Bike::HitWall()
{
	mLives -= 1;
	mAnimating = true;
	//mDeathAnimation->ResetAnimation();
}

void Bike::Update()
{

}

void Bike::Render()
{

}
