#include "Bike.h"


void Bike::HandleMovement()
{
	Vector2 tempPos = mBike->Position(Local);
	int checkY = tempPos.y;
	int checkX = tempPos.x;

	if (mInput->KeyDown(SDL_SCANCODE_SPACE))
	{
		mMoveSpeed = mBaseSpeed * 4;
		mBoosted = true;
	}
	else
	{
		mMoveSpeed = mBaseSpeed;
		mBoosted = false;
	}

	if (!mBoosted)
	{
		if (mInput->KeyDown(SDL_SCANCODE_RIGHT))
		{
			if (checkY % mGridSize == 0)
			{
				previousDirection = currentDirection;
				currentDirection = Direction::RIGHT;
				mNewDirection = true;
			}
			else
			{
				queuedDirection = Direction::RIGHT;
			}
		}
		else if (mInput->KeyDown(SDL_SCANCODE_LEFT)) 
		{
			if (checkY % mGridSize == 0)
			{
				previousDirection = currentDirection;
				currentDirection = Direction::LEFT;
				mNewDirection = true;
			}
			else
			{
				queuedDirection = Direction::LEFT;
			}
		}
		else if (mInput->KeyDown(SDL_SCANCODE_UP))
		{
			if (checkX % mGridSize == 0)
			{
				previousDirection = currentDirection;
				currentDirection = Direction::UP;
				mNewDirection = true;
			}
			else
			{
				queuedDirection = Direction::UP;
			}
		}
		else if (mInput->KeyDown(SDL_SCANCODE_DOWN))
		{
			if (checkX % mGridSize == 0)
			{
				previousDirection = currentDirection;
				currentDirection = Direction::DOWN;
				mNewDirection = true;
			}
			else
			{
				queuedDirection = Direction::DOWN;
			}
		}

		switch (queuedDirection)
		{
		case UP:
			if (checkX % mGridSize == 0)
			{
				previousDirection = currentDirection;
				currentDirection = Direction::UP;
				queuedDirection = currentDirection;
				mNewDirection = true;
			}
			break;
		case RIGHT:
			if (checkY % mGridSize == 0)
			{
				previousDirection = currentDirection;
				currentDirection = Direction::RIGHT;
				queuedDirection = currentDirection;
				mNewDirection = true;
			}
			break;
		case DOWN:
			if (checkX % mGridSize == 0)
			{
				previousDirection = currentDirection;
				currentDirection = Direction::DOWN;
				queuedDirection = currentDirection;
				mNewDirection = true;
			}
			break;
		case LEFT:
			if (checkY % mGridSize == 0)
			{
				previousDirection = currentDirection;
				currentDirection = Direction::LEFT;
				queuedDirection = currentDirection;
				mNewDirection = true;
			}
			break;
		default:
			break;
		}
	}

	switch (currentDirection)
	{
	case Direction::UP:
		if (mNewDirection)
		{
			mBike->Rotation(0);
			mNewDirection = false;
		}
		tempPos.y -= mMoveSpeed;
		break;
	case Direction::RIGHT:
		if (mNewDirection)
		{
			mBike->Rotation(90);
			mNewDirection = false;
		}
		tempPos.x += mMoveSpeed;
		break;
	case Direction::DOWN:
		if (mNewDirection)
		{
			mBike->Rotation(180);
			mNewDirection = false;
		}
		tempPos.y += mMoveSpeed;
		break;
	case Direction::LEFT:
		if (mNewDirection)
		{
			mBike->Rotation(270);
			mNewDirection = false;
		}
		tempPos.x -= mMoveSpeed;
		break;
	default:
		break;
	}
	//std::cout << "x: " << mBike->Position().x << "   y: " << mBike->Position().y << std::endl;
	//std::cout << "Tx: " << tempPos.x << "   Ty: " << tempPos.y << std::endl;
	if (tempPos.x > mScreenBounds.x)
	{ 
		tempPos.x = mScreenBounds.x;
		HitWall();
	}
	else if (tempPos.x < -mScreenBounds.x)
	{ 
		tempPos.x = -mScreenBounds.x;
		HitWall();

	}
	if (tempPos.y < -mScreenBounds.y)
	{
		tempPos.y = -mScreenBounds.y;
		HitWall();

	}
	else if (tempPos.y > mScreenBounds.y)
	{
		tempPos.y = mScreenBounds.y;
		HitWall();

	}
	mBike->Position(tempPos);
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

	mBike = new Texture("BikeSheet.png", 0, 0, 32, 32);
	mBike->Parent(this);

	mBaseSpeed = 1.0f;
	mGridSize = 30.0f;
	mScreenBounds = Vector2(405.0f, 405.0f);

	mDeathAnimation = new AnimatedTexture("explosionSprites.png", 0, 0, 32, 32, 8, 1.0f, AnimatedTexture::Horizontal);
	mDeathAnimation->Parent(this);

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
  	mDeathAnimation->Position(mBike->Position(Space::Local));

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
       		mDeathAnimation->Render();       
		//mAnimating = mDeathAnimation->IsAnimating(); 
	}
	else
	{ 
		if (mVisible)
		{ 
			mBike->Render();
		} 
	}
}
