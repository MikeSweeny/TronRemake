#include "Bike.h"


Bike::Bike()
{
	mAudio = AudioManager::Instance();

	//mDeathAnimation = new AnimatedTexture("PlayerDeath.png", 0, 0, 128, 128, 4, 1.0f, AnimatedTexture::Horizontal);
	//mDeathAnimation->Parent(this);
	//mDeathAnimation->Position(Vec2_Zero);


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

	if (mTrail->CheckCollisions(frontOfBike, frontOfBike2))
	{
		HitWall();
	}
	std::cout << "BikeX: " << this->Position(Local).x << "  BikeY: " << this->Position(Local).y << std::endl;
	std::cout << "FrontX: " << frontOfBike.x << "  FrontY: " << frontOfBike.y << std::endl << std::endl;
}

bool Bike::IsDead()
{
	return isDead;
}
