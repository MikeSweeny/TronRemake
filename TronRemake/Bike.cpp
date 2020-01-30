#include "Bike.h"


Bike::Bike()
{
	mAudio = AudioManager::Instance();

	//mDeathAnimation = new AnimatedTexture("PlayerDeath.png", 0, 0, 128, 128, 4, 1.0f, AnimatedTexture::Horizontal);
	//mDeathAnimation->Parent(this);
	//mDeathAnimation->Position(Vec2_Zero);
	mVisible = false;
	mAnimating = false;

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
	mLives -= 1;
  	mDeathAnimation->Position(mBike->Position(Space::Local));
	mAnimating = true;
	//mDeathAnimation->ResetAnimation();
	//SetupPlayer();
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
