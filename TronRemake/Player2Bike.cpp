#include "Player2Bike.h"

Player2Bike::Player2Bike()
{
	mInput = InputManager::Instance();
	currentDirection = Direction::DOWN;
	queuedDirection = Direction::DOWN;
	mVisible = false;
	mAnimating = false;
	SetSprite("aiBikeSheet.png", 0, 0, 32, 32);
	mBike->Parent(this);

	mTrail = new Trail("aiBikeSheet.png");
	mTrail->Parent(this->Parent());
	mScore = 0;
	mLives = 1;
}
Player2Bike::~Player2Bike()
{
	mInput = nullptr;
}
void Player2Bike::Update()
{
	base::Update();
	HandleCollisions();
	//if (mAnimating)
	//{
	//	mDeathAnimation->Update();
	//	//mAnimating = mDeathAnimation->IsAnimating(); 
	//}
	//else
	//{
	//	if (Active())
	//	{
	//		HandleP2Movement();
	//	}
	//}

}

void Player2Bike::AddScore(int change)
{
	mScore += change;
}
void Player2Bike::HandleMovement()
{
	if (mInput->KeyDown(SDL_SCANCODE_SPACE))
	{
		mMoveSpeed = mBaseSpeed * 2;
		mBoosted = true;
	}
	else
	{
		mMoveSpeed = mBaseSpeed;
		mBoosted = false;
	}

	Vector2 tempPos = mBike->Position(Local);
	checkY = tempPos.y;
	checkX = tempPos.x;

	if (!mBoosted)
	{
		if (mInput->KeyDown(SDL_SCANCODE_D))
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
		else if (mInput->KeyDown(SDL_SCANCODE_A))
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
		else if (mInput->KeyDown(SDL_SCANCODE_W))
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
		else if (mInput->KeyDown(SDL_SCANCODE_S))
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

	if (checkX % mTrailSize == 0 || checkY % mTrailSize)
	{
		PlaceTrail();
	}

	mBike->Position(tempPos);
}
void Player2Bike::PlaceTrail()
{
	mTrail->PlaceTrail(mBike->Position(World));

}

void Player2Bike::SetupPlayer()
{

}
