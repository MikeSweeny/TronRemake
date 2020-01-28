#ifndef __BIKE_H
#define __BIKE_H
#include "Types.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "AnimatedTexture.h"


using namespace SDLFramework;

class Bike : public GameEntity
{
	// ************* Attributes ************* //
private:
	Direction currentDirection;
	Direction previousDirection;
	float timeBetweenDirections;

	Timer* mTimer;
	InputManager* mInput;
	AudioManager* mAudio;
	
	int mScore;
	int mLives;

	Texture* mBike;
	AnimatedTexture* mDeathAnimation;

	float mMoveSpeed;
	Vector2 mScreenBounds;

public:
	bool mVisible; // to hide he avatars before we start a game
	bool mAnimating;

	// ************* Functions ************* //
private:

	void HandleMovement();

public:
	Bike();
	~Bike();

	void Visible(bool visible);
	bool isAnimating();

	int Score();
	int Lives();

	void AddScore(int change);

	void HitWall();

	void Update();
	void Render();

	// ************* Protected ************* //
protected:


};

#endif