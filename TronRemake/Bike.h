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
	bool mVisible; // to hide he avatars before we start a game
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

	void Update();
	void Render();

	// ************* Protected ************* //
protected:

	int mGridSize = 30.0f;
	float mBaseSpeed = 1.0f;
	Vector2 mScreenBounds = Vector2(810.0f, 810.0f);
	AnimatedTexture* mDeathAnimation;

	Trail* mTrail;
	int mTrailSize = 4;
	Texture* mBike;
	int mLives;
	bool mNewDirection;
	int checkY;
	int checkX;
	float mMoveSpeed;
	Direction currentDirection;
	Direction previousDirection;
	Direction queuedDirection;
	float timeBetweenDirections;
	Vector2 mStartPos;
	Vector2 frontOfBike;

	void SetSprite(std::string sheet, int x, int y, int h, int w);
	void virtual HandleMovement() = 0;
	void HandleCollisions();
	void virtual SetupPlayer() = 0;

};

#endif