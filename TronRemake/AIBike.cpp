#include "AIBike.h"



AIBike::AIBike()
{
	mTimer = Timer::GetInstance();
	
	currenttime = 0;


	path = 2;
	previouspath = 2;


	currentDirection = DOWN;
	mVisible = false;
	mAnimating = false;
	SetSprite("aiBikeSheet.png", 0, 0, 32, 32);
	mBike->Parent(this);

	mTrail = new Trail("bikeSheet.png");
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
}

void AIBike::AddScore(int change)
{
	mAIScore += change;

}

void AIBike::HandleMovement()
{
	mMoveSpeed = mBaseSpeed;
	
	

	Vector2 tempPos = mBike->Position(Local);
	checkY = tempPos.y;
	checkX = tempPos.x;

	
	currenttime += mTimer->GetDeltaTime();
	
	if (currenttime >= 1.5f)
	{
		do
		{
			path = RandomPath();
			ValidPath(path);
		
		} while (!ValidPath(path));

		if (path == 0)
			std::cout << "Forward" << std::endl;
		if (path == 1)
			std::cout << "Right" << std::endl;
		if (path == 2)
			std::cout << "Down" << std::endl;
		if (path == 3)
			std::cout << "Left" << std::endl;


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

void AIBike::SetupPlayer()
{
}

int AIBike::RandomPath()
{
	int randomNum = rand() % 100;
	int newpath = 0;

	if (randomNum <= 24)
	{
		newpath = 0;
		
	}
	else if (randomNum > 24 && randomNum <= 49)
	{
		newpath = 1;
	}
	else if (randomNum > 49 && randomNum <= 74)
	{
		newpath = 2;
	}
	else if (randomNum < 74)
	{
		newpath = 3;
	}

	return newpath;
}

bool AIBike::ValidPath(int path)
{
	bool BvalidPath;
	if (previouspath == 0 && path == 2 || previouspath == 2 && path == 0)
	{
		BvalidPath = false;
		
	}
	else if (previouspath == 3 && path == 1 || previouspath == 1 && path == 3)
	{
		BvalidPath = false;
	}

	else
	{
		BvalidPath = true;
	}

	return BvalidPath;
}

void AIBike::PlaceTrail()
{
	mTrail->PlaceTrail(mBike->Position(World));
}

int AIBike::AIScore()
{
	return mAIScore;
}
