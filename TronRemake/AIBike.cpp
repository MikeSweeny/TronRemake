#include "AIBike.h"



AIBike::AIBike()
{
	mTimer = Timer::GetInstance();
	
	currenttime = 0;


	path = 2;
	previouspath = 2;


	mMoveSpeed = mBaseSpeed;
	currentDirection = LEFT;
	queuedDirection = LEFT;
	mVisible = false;
	mAnimating = false;
	SetSprite("aiBikeSheet.png", 0, 0, 32, 32);
	mBike->Parent(this);

	mTrail = new Trail("aiBikeSheet.png");
	mTrail->Parent(this->Parent());
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
	HandleCollisions();
}

void AIBike::AddScore(int change)
{
	mAIScore += change;

}

void AIBike::HandleMovement()
{
	
	Vector2 tempPos = this->Position(Local);
	checkY = tempPos.y;
	checkX = tempPos.x;

	
	currenttime += mTimer->GetDeltaTime();
	
	if (currenttime >= ChangePathInterval())
	{
		do
		{
			path = RandomPath();
		
		} while (!ValidPath(path));

		previouspath = path;
		currenttime = 0;
	}
	

	if (path == 1)
	{
		if (checkY % mGridSize == 0)
		{
			previousDirection = currentDirection;
			currentDirection = Direction::RIGHT;
			mNewDirection = true;
			path = -1;
		}
		else
		{
			queuedDirection = Direction::RIGHT;
		}
	}
	else if (path == 3)
	{
		if (checkY % mGridSize == 0)
		{
			previousDirection = currentDirection;
			currentDirection = Direction::LEFT;
			mNewDirection = true;
			path = -1;

		}
		else
		{
			queuedDirection = Direction::LEFT;
		}
	}
	else if (path == 0)
	{
		if (checkX % mGridSize == 0)
		{
			previousDirection = currentDirection;
			currentDirection = Direction::UP;
			mNewDirection = true;
			path = -1;

		}
		else
		{
			queuedDirection = Direction::UP;
		}
	}
	else if (path == 2)
	{
		if (checkX % mGridSize == 0)
		{
			previousDirection = currentDirection;
			currentDirection = Direction::DOWN;
			mNewDirection = true;
			path = -1;

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

	if (checkX % mTrailSize == 0 || checkY % mTrailSize == 0)
	{
		PlaceOTrail();
	}

	this->Position(tempPos);
}

void AIBike::SetupPlayer()
{
}

float AIBike::ChangePathInterval()
{
	srand(time(0));
	float interval = rand() % 1 + 0.5f;

	return interval;
}

int AIBike::RandomPath()
{
	srand(time(0));
	int newpath = rand() % 4;

	return newpath;
}

bool AIBike::ValidPath(int path)
{
	bool bValidPath;
	if (previouspath == 0 && path == 2 || previouspath == 2 && path == 0)
	{
		bValidPath = false;
		
	}
	else if (previouspath == 3 && path == 1 || previouspath == 1 && path == 3)
	{
		bValidPath = false;
	}

	else
	{
		bValidPath = true;
	}

	return bValidPath;
}

int AIBike::GetAIScore()
{
	return mAIScore;
}
