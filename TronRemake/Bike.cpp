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
	//mDeathAnimation->ResetAnimation();
	//SetupPlayer();
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
	switch (currentDirection)
	{
	case UP:
		frontOfBike = mBike->Parent()->Position(Local);
		frontOfBike2 = frontOfBike;
		frontOfBike.y -= 16;
		frontOfBike2.y -= 13;
		break;
	case RIGHT:
		frontOfBike = mBike->Parent()->Position(Local);
		frontOfBike2 = frontOfBike;
		frontOfBike.x += 16;
		frontOfBike2.x += 13;
		break;
	case DOWN:
		frontOfBike = mBike->Parent()->Position(Local);
		frontOfBike2 = frontOfBike;
		frontOfBike.y += 16;
		frontOfBike2.y += 13;
		break;
	case LEFT:
		frontOfBike = mBike->Parent()->Position(Local);
		frontOfBike2 = frontOfBike;
		frontOfBike.x -= 16;
		frontOfBike2.x -= 13;
		break;
	default:
		break;
	}

	if (CheckCollisions(frontOfBike, frontOfBike2))
	{
		HitWall();
	}
}

bool Bike::CheckCollisions(Vector2 pos1, Vector2 pos2)
{
	std::vector<Texture*> mPool = mTrail->GetPool();
	for (int i = 0; i < mPool.size() - 1; i++)
	{
		if ((pos1.x < mPool[i]->Position().x + offset && pos1.x > mPool[i]->Position().x - offset
			&& pos1.y < mPool[i]->Position().y + offset && pos1.y > mPool[i]->Position().y - offset))
		{
			return true;
		}
		if ((pos2.x < mPool[i]->Position().x + offset && pos2.x > mPool[i]->Position().x - offset
			&& pos2.y < mPool[i]->Position().y + offset && pos2.y > mPool[i]->Position().y - offset))
		{
			return true;
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

void Bike::PlaceTrail()
{
	mTrail->PlaceTrail(mBike->Position());
}
