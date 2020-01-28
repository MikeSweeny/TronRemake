#include "Bike.h"


void Bike::HandleMovement()
{
	if (mInput->KeyDown(SDL_SCANCODE_RIGHT))
	{
		previousDirection = currentDirection;
		currentDirection = Direction::RIGHT;
	}
	else if (mInput->KeyDown(SDL_SCANCODE_LEFT)) 
	{ 
		previousDirection = currentDirection;
		currentDirection = Direction::LEFT;
	}
	else if (mInput->KeyDown(SDL_SCANCODE_UP))
	{
		previousDirection = currentDirection;
		currentDirection = Direction::UP;
	}
	else if (mInput->KeyDown(SDL_SCANCODE_DOWN))
	{
		previousDirection = currentDirection;
		currentDirection = Direction::DOWN;
	}

	Vector2 pos = Position(Local);    
	if (pos.x < mScreenBounds.x)
	{ 
		pos.x = mScreenBounds.x;
	}
	else if (pos.x > mScreenBounds.y)
	{ 
		pos.x = mScreenBounds.y;
	}
	Position(pos);
}

Bike::Bike()
{
	currentDirection = UP; 
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
	if (mAnimating)
	{ 
		mDeathAnimation->Update();        
		//mAnimating = mDeathAnimation->IsAnimating(); 
	}
	else
	{
		if (Active())
		{ 
			HandleMovement(); 
		} 
	}
}

void Bike::Render()
{
	if (mAnimating)
	{ 
		mDeathAnimation->Update();       
		//mAnimating = mDeathAnimation->IsAnimating(); 
	}
	else
	{ 
		if (Active())
		{ 
			HandleMovement(); 
		} 
	}
}
