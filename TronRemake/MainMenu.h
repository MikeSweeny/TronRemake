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

	// Top Bar Score Thingy
	GameEntity* StartScreenTopBanner;
	GameEntity* PlayerOneSubBar;
	GameEntity* PlayerTwoSubBar;
	GameEntity* HighScoreSubBar;

	Texture* VSPlayerOneWins;
	Texture* VSPlayerTwoWins;
	Texture* OnePlayerHighScore;

	Texture* P1Wins;
	Texture* P2Wins;
	Texture* HighScoreValue;

	// Animated Thingy


	const static int gridHeight = 4;
	const static int gridWidth = 7;
	int aPyramidLayout[gridHeight][gridWidth] = {0, 0, 0, 3, 0, 0, 0,
									   		     0, 0, 1, 0, 4, 0, 0,
										         0, 1, 0, 2, 0, 4, 0,
											     1, 0, 2, 0, 2, 0, 4};
	AnimatedTexture* aPyramidBuild[gridHeight][gridWidth];

	// Animated "Rainbow"
	GameEntity* mAnimatedSection;
	static const int rowSize = 6;
	static const int rowCount = 3;
	float currentTime;
	float lastChange;
	float changeIncrement;
	int frameToRender;
	const int numFrames = 4;
	Texture* aFrameOneRow1[rowSize];
	Texture* aFrameOneRow2[rowSize];
	Texture* aFrameOneRow3[rowSize];
	Texture* aFrameOneRow4[rowSize];
	Texture* aFrameOneRow5[rowSize];

	Texture* aFrameTwoRow1[rowSize];
	Texture* aFrameTwoRow2[rowSize];
	Texture* aFrameTwoRow3[rowSize];
	Texture* aFrameTwoRow4[rowSize];
	Texture* aFrameTwoRow5[rowSize];

	Texture* aFrameThreeRow1[rowSize];
	Texture* aFrameThreeRow2[rowSize];
	Texture* aFrameThreeRow3[rowSize];
	Texture* aFrameThreeRow4[rowSize];
	Texture* aFrameThreeRow5[rowSize];

	Texture* aFrameFourRow1[rowSize];
	Texture* aFrameFourRow2[rowSize];
	Texture* aFrameFourRow3[rowSize];
	Texture* aFrameFourRow4[rowSize];
	Texture* aFrameFourRow5[rowSize];
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
	void SetFrameOneSprites(Texture* row[], float rootX, float rootY);
	void SetFrameTwoSprites(Texture* row[], float rootX, float rootY);
	void SetFrameThreeSprites(Texture* row[], float rootX, float rootY);
	void SetFrameFourSprites(Texture* row[], float rootX, float rootY);



	// ************* Protected ************* //
protected:


};


#endif