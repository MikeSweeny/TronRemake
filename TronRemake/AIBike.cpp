#include "AIBike.h"



AIBike::AIBike()
{
	mTimer = Timer::GetInstance();

	currenttime = 0;
	mMoveSpeed = mBaseSpeed;
	mVisible = false;
	mAnimating = false;
	SetSprite("aiBikeSheet.png", 0, 0, 32, 32);
	mBike->Parent(this);

	aiBrain = new AiFSM(this);

	mTrail = new Trail("aiBikeSheet.png");
	mTrail->Parent(this->Parent());
	mLives = 1;
	SetupPlayer();
}

AIBike::~AIBike()
{

}

bool AIBike::CollisionAvoidF(Vector2 pos)
{
	std::vector<Texture*> tempPool = mTrail->GetBPool();
	if (!tempPool.empty())
	{
		for (int i = 0; i < tempPool.size() - 1; i++)
		{
			if (tempPool[i]->isActive)
			{
				Vector2 tempPos = tempPool[i]->Position(World);
				if ((pos.x + offset > tempPos.x&& pos.x - offset < tempPos.x
					&& pos.y + offset > tempPos.y && pos.y - offset < tempPos.y))
				{
					return true;
				}
			}
		}
	}
	tempPool = mTrail->GetOPool();
	if (!tempPool.empty())
	{
		for (int i = 0; i < tempPool.size() - 1; i++)
		{
			if (tempPool[i]->isActive)
			{
				Vector2 tempPos = tempPool[i]->Position(World);
				if ((pos.x + offset > tempPos.x&& pos.x - offset < tempPos.x
					&& pos.y + offset > tempPos.y && pos.y - offset < tempPos.y))
				{
					return true;
				}
			}
		}
	}
	float tempX = mScreenBounds.x + 16;
	float tempY = mScreenBounds.y + 16;
	if (pos.x >= tempX)
	{
		pos.x = tempX;
		return true;
	}
	else if (pos.x < 16)
	{
		pos.x = 16;
		return true;
	}
	if (pos.y >= tempY)
	{
		pos.y = tempY;
		return true;
	}
	else if (pos.y < 16)
	{
		pos.y = 16;
		return true;
	}
	return false;
}

bool AIBike::CollisionAvoidL(Vector2 pos)
{
	std::vector<Texture*> tempPool = mTrail->GetBPool();
	if (!tempPool.empty())
	{
		for (int i = 0; i < tempPool.size() - 1; i++)
		{
			if (tempPool[i]->isActive)
			{
				Vector2 tempPos = tempPool[i]->Position(World);
				if ((pos.x + offset > tempPos.x&& pos.x - offset < tempPos.x
					&& pos.y + offset > tempPos.y && pos.y - offset < tempPos.y))
				{
					return true;
				}
			}
		}
	}
	tempPool = mTrail->GetOPool();
	if (!tempPool.empty())
	{
		for (int i = 0; i < tempPool.size() - 1; i++)
		{
			if (tempPool[i]->isActive)
			{
				Vector2 tempPos = tempPool[i]->Position(World);
				if ((pos.x + offset > tempPos.x&& pos.x - offset < tempPos.x
					&& pos.y + offset > tempPos.y && pos.y - offset < tempPos.y))
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool AIBike::CollisionAvoidR(Vector2 pos)
{
	std::vector<Texture*> tempPool = mTrail->GetBPool();
	if (!tempPool.empty())
	{
		for (int i = 0; i < tempPool.size() - 1; i++)
		{
			if (tempPool[i]->isActive)
			{
				Vector2 tempPos = tempPool[i]->Position(World);
				if ((pos.x + offset > tempPos.x&& pos.x - offset < tempPos.x
					&& pos.y + offset > tempPos.y && pos.y - offset < tempPos.y))
				{
					return true;
				}
			}
		}
	}
	tempPool = mTrail->GetOPool();
	if (!tempPool.empty())
	{
		for (int i = 0; i < tempPool.size() - 1; i++)
		{
			if (tempPool[i]->isActive)
			{
				Vector2 tempPos = tempPool[i]->Position(World);
				if ((pos.x + offset > tempPos.x&& pos.x - offset < tempPos.x
					&& pos.y + offset > tempPos.y && pos.y - offset < tempPos.y))
				{
					return true;
				}
			}
		}
	}
	return false;
}

void AIBike::SetTriggerBoxes()
{
	topTriggerBoxPos = Vector2(Position(World).x, Position(World).y - checkDistance);
	botTriggerBoxPos = Vector2(Position(World).x, Position(World).y + checkDistance);
	leftTriggerBoxPos = Vector2(Position(World).x - checkDistance, Position(World).y);
	rightTriggerBoxPos = Vector2(Position(World).x + checkDistance, Position(World).y);
}


void AIBike::IncrementTimer()
{
	currenttime += mTimer->GetDeltaTime();
}


void AIBike::Update()
{
	base::Update();
	aiBrain->Update();
	HandleCollisions();
}

void AIBike::Move()
{
	checkPos = this->Position(Local);
	checkY = checkPos.y;
	checkX = checkPos.x;
	SetTriggerBoxes();

	switch (currentDirection)
	{
	case Direction::UP:
		//Rotating (move to turn() later
		if (mNewDirection)
		{
			mBike->Rotation(0);
			mNewDirection = false;
		}
		//Moving
		checkPos.y -= mMoveSpeed;
		// Watching for collisions
		if (CollisionAvoidF(topTriggerBoxPos))
		{
			validDirections.clear();
			if (!CollisionAvoidL(leftTriggerBoxPos))
			{
				validDirections.push_back(Direction::LEFT);
			}
			if (!CollisionAvoidR(rightTriggerBoxPos))
			{
				validDirections.push_back(Direction::RIGHT);
			}
			aiBrain->SetState(TURNING);
		}
		break;
	case Direction::RIGHT:
		if (mNewDirection)
		{
			mBike->Rotation(90);
			mNewDirection = false;
		}
		checkPos.x += mMoveSpeed;
		// Watching for collisions
		if (CollisionAvoidF(rightTriggerBoxPos))
		{
			validDirections.clear();
			if (!CollisionAvoidL(topTriggerBoxPos))
			{
				validDirections.push_back(Direction::UP);
			}
			if (!CollisionAvoidR(botTriggerBoxPos))
			{
				validDirections.push_back(Direction::DOWN);
			}
			aiBrain->SetState(TURNING);
		}
		break;
	case Direction::DOWN:
		if (mNewDirection)
		{
			mBike->Rotation(180);
			mNewDirection = false;
		}
		checkPos.y += mMoveSpeed;
		// Watching for collisions
		if (CollisionAvoidF(botTriggerBoxPos))
		{
			validDirections.clear();
			if (!CollisionAvoidL(rightTriggerBoxPos))
			{
				validDirections.push_back(Direction::RIGHT);
			}
			if (!CollisionAvoidR(leftTriggerBoxPos))
			{
				validDirections.push_back(Direction::LEFT);
			}
			aiBrain->SetState(TURNING);
		}
		break;
	case Direction::LEFT:
		if (mNewDirection)
		{
			mBike->Rotation(270);
			mNewDirection = false;
		}
		checkPos.x -= mMoveSpeed;
		// Watching for collisions
		if (CollisionAvoidF(leftTriggerBoxPos))
		{
			validDirections.clear();
			if (!CollisionAvoidL(botTriggerBoxPos))
			{
				validDirections.push_back(Direction::DOWN);
			}
			if (!CollisionAvoidR(topTriggerBoxPos))
			{
				validDirections.push_back(Direction::UP);
			}
			aiBrain->SetState(TURNING);
		}
		break;
	default:
		break;
	}

	if (checkX % mTrailSize == 0 || checkY % mTrailSize == 0)
	{
		PlaceOTrail();
	}

	this->Position(checkPos);

}

void AIBike::Turn()
{
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

	Direction tempDir;
	do
	{
		path = RandomPath();
		switch (path)
		{
		case 0:
			tempDir = UP;
			break;
		case 1:
			tempDir = RIGHT;
			break;
		case 2:
			tempDir = DOWN;
			break;
		case 3:
			tempDir = LEFT;
			break;
		default:
			break;
		}
	} while (!ValidPath(tempDir));

	aiBrain->SetState(MOVING);
}

void AIBike::SetupPlayer()
{
	checkPos = this->Position(Local);
	currentDirection = DOWN;
	queuedDirection = DOWN;
	mStartPos = Vector2(390.0f, 60.0f);
	Visible(true);
	Position(mStartPos);
	Active(true);
	ResetBike();
	aiBrain->SetState(AiStates::MOVING);
	SetLives(1);
	isDead = false;
}

void AIBike::HandleMovement()
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

bool AIBike::ValidPath(Direction dir)
{
	bool found = false;
	for (int i = 0; i < validDirections.size() - 1; i++)
	{
		if (path == validDirections[i])
		{
			found = true;
		}
	}
	return found;
}

