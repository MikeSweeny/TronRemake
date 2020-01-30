#include "PlayerBike.h"


PlayerBike::PlayerBike()
{
	mInput = InputManager::Instance();
	currentDirection = UP;
	mVisible = false;
	mAnimating = false;
	SetSprite("bikeSheet.png", 0, 0, 32, 32);
	mBike->Parent(this);

	mTrail = new Trail("bikeSheet.png");
	mTrail->Parent(this->Parent());
	mScore = 0;
	mLives = 1;
}

PlayerBike::~PlayerBike()
{
	mInput = nullptr;
}

void PlayerBike::Update()
{
	base::Update();
	HandleCollisions();
	HandleMovement();
}

void PlayerBike::HandleMovement()
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


void PlayerBike::PlaceTrail()
{
	mTrail->PlaceTrail(mBike->Position(World));
}

void PlayerBike::AddScore(int change)
{
	mScore += change;
}

int PlayerBike::Score()
{
	return mScore;
}

void PlayerBike::HandleCollisions()
{
	switch (currentDirection)
	{
	case UP:
		frontOfBike = mBike->Position(World);
		frontOfBike.y -= 13;
		break;
	case RIGHT:
		frontOfBike = mBike->Position(World);
		frontOfBike.x += 13;
		break;
	case DOWN:
		frontOfBike = mBike->Position(World);
		frontOfBike.y += 13;
		break;
	case LEFT:
		frontOfBike = mBike->Position(World);
		frontOfBike.x -= 13;
		break;
	default:
		break;
	}
	if (mTrail->CheckCollisions(frontOfBike))
	{
		HitWall();
	}
}
