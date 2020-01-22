#ifndef __MAINMENU_H
#define __MAINMENU_H
#include "AnimatedTexture.h"
#include "InputManager.h"

using namespace SDLFramework;

class MainMenu : public GameEntity
{

	// ************* Attributes ************* //
public:



private:
	Timer* mTimer;
	InputManager* mInput;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

	// Animated Thingy
	GameEntity* mAnimatedRainbow;
	static const int rowSize = 6;
	static const int rowCount = 3;
	Texture* aFrameOneRow[rowSize];
	Texture* aFrameTwoRow[rowSize];
	Texture* aFrameThreeRow[rowSize];
	Texture* aFrameFourRow[rowSize];
	Texture* rows[rowCount];

	// Play Mode Entities
	GameEntity* mPlayModes;
	Texture* mOnePlayerMode;
	Texture* mTwoPlayerMode;
	Texture* mCursor;

	Vector2 mCursorStartPos;
	Vector2 mCursorOffset;
	int mSelectedMode;


	// Slow-Type Acknowledgements

	// ************* Functions ************* //
public:
	MainMenu();
	~MainMenu();
	void Update() override;
	void Render() override;

private:
	int SelectedMode();
	void ChangeSelectedMode(int change);

	// Animated rainbow functions
	void SetFrameSprites();



	// ************* Protected ************* //
protected:


};


#endif