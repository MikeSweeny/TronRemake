#include "Bike.h"


Bike::Bike()
{
	mAudio = AudioManager::Instance();

	mDeathAnimation = new AnimatedTexture("explosionSprites.png", 0, 0, 32, 32, 8, 0.3f, AnimatedTexture::Horizontal);
	mDeathAnimation->Parent(this);
}

Bike::~Bike()
{
	mAudio = nullptr;

	delete mBike;
	mBike = nullptr;
	delete mDeathAnimation;
	mDeathAnimation = nullptr;

	delete mTrail;
	mTrail = nullptr;
}

void Bike::Update()
{
	if (mAnimating)
	{ 
  		mDeathAnimation->Update();        
	}
	else
	{
		if (Active())
		{ 
			HandleMovement(); 
		} 
	}
}

void Bike::Visible(bool visible)
{
	mVisible = visible;
}

bool Bike::isAnimating()
{
	return mAnimating;
}

int Bike::Lives()
{
	return mLives;
}


void Bike::HitWall()
{
	this->Active(false);
	mLives -= 1;
  	mDeathAnimation->Position(mBike->Position(Space::Local));
	mDeathAnimation->SetWrapMode(mDeathAnimation->Once);
	mAnimating = true;
	if (mLives <= 0)
	{
		isDead = true;
	}
}

void Bike::Render()
{
	if (mAnimating)
	{ 
       	mDeathAnimation->Render();
	}
	else
	{ 
		if (mVisible)
		{ 
			mBike->Render();
			if (mTrail)
			{
				mTrail->Render();
			}
		} 
	}
}

void Bike::SetSprite(std::string sheet, int x, int y, int h, int w)
{

	mBike = new Texture(sheet, x, y, w, h);
}

void Bike::HandleCollisions()
{
	Vector2 tempCollider = mBike->Parent()->Position(World);
	switch (currentDirection)
	{
	case UP:
		tempCollider.y = mBike->Parent()->Position(World).y - 16;
		break;
	case RIGHT:
		tempCollider.x = mBike->Parent()->Position(World).x + 16;
		break;
	case DOWN:
		tempCollider.y = mBike->Parent()->Position(World).y + 16;
		break;
	case LEFT:
		tempCollider.x = mBike->Parent()->Position(World).x - 16;
		break;
	default:
		break;
	}
	
	if (CheckCollisions(tempCollider))
	{
		HitWall();
	}

	Vector2 tempPos = this->Position(Local);
	float tempX = mScreenBounds.x + 16;
	float tempY = mScreenBounds.y + 16;


	if (tempPos.x >= tempX)
	{
		tempPos.x = tempX;
		HitWall();
	}
	else if (tempPos.x < 16)
	{
		tempPos.x = 16;
		HitWall();
	}
	if (tempPos.y >= tempY)
	{
		tempPos.y = tempY;
		HitWall();
	}
	else if (tempPos.y < 16)
	{
		tempPos.y = 16;
		HitWall();
	}
}

bool Bike::CheckCollisions(Vector2 pos)
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
				if ((pos.x + offset > tempPos.x && pos.x - offset < tempPos.x
					&& pos.y + offset > tempPos.y && pos.y - offset < tempPos.y))
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Bike::IsDead()
{
	return isDead;
}

void Bike::AnimationDelay()
{
	if (mAnimating)
	{
		float tempTime = 0;
		tempTime += mTimer->GetDeltaTime();
		if (tempTime >= 8 * 0.3f)
		{
			mAnimating = false;
			this->Active(true);
		}
	}
}

void Bike::ResetBike()
{
	mTrail->ResetTrail();
	mAnimating = false;
	mBike->Active(true);
}

void Bike::PlaceBTrail()
{
	mTrail->PlaceTrail(mBike->Position(World));
}

void Bike::PlaceOTrail()
{
	mTrail->PlaceTrail(mBike->Position(World));
}

