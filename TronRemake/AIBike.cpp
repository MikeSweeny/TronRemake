#include "AIBike.h"



AIBike::AIBike()
{
	currentDirection = DOWN;
	mVisible = false;
	mAnimating = false;
	SetSprite("aiBikeSheet.png", 0, 0, 32, 32);
	mBike->Parent(this);

	mAIScore = 0;
	mLives = 1;
}

AIBike::~AIBike()
{
	//RandomPath() = nullptr;
}

void AIBike::Update()
{
	base::Update();
	HandleMovement();
}

void AIBike::HandleMovement()
{
	mMoveSpeed = mBaseSpeed;
	

	Vector2 tempPos = mBike->Position(Local);
	checkY = tempPos.y;
	checkX = tempPos.x;

	
	if (RandomPath() == 1)
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
	else if (RandomPath() == 3)
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
	else if (RandomPath() == 0)
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
	else if (RandomPath() == 2)
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
	mBike->Position(tempPos);
}

int AIBike::RandomPath()
{
	int path = rand() % 100;

	if (path <= 24)
	{
		path = 0;
	}
	else if (path > 24 && path <= 49)
	{
		path = 1;
	}
	else if (path > 49 && path <= 74)
	{
		path = 2;
	}
	else if (path < 74)
	{
		path = 3;
	}

	return path;
}

int AIBike::AIScore()
{
	return mAIScore;
}
