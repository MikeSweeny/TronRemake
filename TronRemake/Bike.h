#ifndef __BIKE_H
#define __BIKE_H
#include "Types.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "AnimatedTexture.h"
#include "Trail.h"

using namespace SDLFramework;

class Bike : public GameEntity
{
	// ************* Attributes ************* //
private:

	Timer* mTimer;
	AudioManager* mAudio;

public:
	bool mVisible; // to hide the avatars before we start a game
	bool mAnimating;

	// ************* Functions ************* //
private:


public:
	Bike();
	~Bike();

	void Visible(bool visible);
	bool isAnimating();

	int Lives();
	void HitWall();
	bool IsDead();

	void Update();
	void Render();

	// ************* Protected ************* //
protected:

	int mGridSize = 30.0f;
	float mBaseSpeed = 3.0f;
	Vector2 mScreenBounds = Vector2(810.0f, 810.0f);
	AnimatedTexture* mDeathAnimation;

	Trail* mTrail = 0;
	int mTrailSize = 6;
	Texture* mBike = 0;
	int mLives = 0;
	bool mNewDirection = 0;
	int checkY = 0;
	int checkX = 0;
	float mMoveSpeed = 0;
	Direction currentDirection = UP;
	Direction previousDirection = UP;
	Direction queuedDirection = UP;
	float timeBetweenDirections = 0;
	Vector2 mStartPos = 0;
	Vector2 frontOfBike = 0;
	Vector2 frontOfBike2 = 0;
	bool isDead = false;

	void SetSprite(std::string sheet, int x, int y, int h, int w);
	void virtual HandleMovement() = 0;
	void HandleCollisions();
	void virtual SetupPlayer() = 0;

};

#endif