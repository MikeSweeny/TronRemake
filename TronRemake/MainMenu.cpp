#include "MainMenu.h"

MainMenu::MainMenu()
{
	mTimer = Timer::GetInstance();
	mInput = InputManager::Instance();

	// Main Menu Top Banner High Scores

	int SCREEN_WIDTH = 1024;

	StartScreenTopBanner = new GameEntity(SCREEN_WIDTH * 0.5, 80.0f);
	PlayerOneSubBar = new GameEntity(150.0f, 80.0f);
	PlayerTwoSubBar = new GameEntity(150.0f, 80.0f);
	HighScoreSubBar = new GameEntity(150.0f, 80.0f);

	VSPlayerOneWins = new Texture("PLAYER 1 WINS", "Computerfont.ttf", 32, { 0, 68, 240 });
	VSPlayerTwoWins = new Texture("PLAYER 2 WINS", "Computerfont.ttf", 32, { 0, 68, 240 });
	OnePlayerHighScore = new Texture("HIGHSCORE", "Computerfont.ttf", 32, { 0, 68, 240 });
	
	P1Wins = new Texture("000" /* Player 1 win int */, "Computerfont.ttf", 32, { 0, 68, 240 });
	P2Wins = new Texture("000" /* Player 2 win int */, "Computerfont.ttf", 32, { 0, 68, 240 });
	HighScoreValue = new Texture("000" /* 1 Player high score */, "Computerfont.ttf", 32, { 0, 68, 240 });

	StartScreenTopBanner->Parent(this);

	PlayerOneSubBar->Parent(StartScreenTopBanner);
	PlayerTwoSubBar->Parent(StartScreenTopBanner);
	HighScoreSubBar->Parent(StartScreenTopBanner);

	VSPlayerOneWins->Parent(PlayerOneSubBar);
	VSPlayerTwoWins->Parent(PlayerTwoSubBar);
	P1Wins->Parent(PlayerOneSubBar);
	P2Wins->Parent(PlayerTwoSubBar);

	OnePlayerHighScore->Parent(HighScoreSubBar);
	HighScoreValue->Parent(HighScoreSubBar);

	

	PlayerOneSubBar->Position(-SCREEN_WIDTH * 0.3f, 0.0f);
	PlayerTwoSubBar->Position(0.0f, 0.0f);
	HighScoreSubBar->Position(SCREEN_WIDTH * 0.3f, 0.0f);

	VSPlayerOneWins->Position(0.0f, 0.0f);
	VSPlayerTwoWins->Position(0.0f, 0.0f);

	P1Wins->Position(0.0f, 50.0f);
	P2Wins->Position(0.0f, 50.0f);

	OnePlayerHighScore->Position(0.0f, 0.0f);
	HighScoreValue->Position(0.0f, 50.0f);
	

	// Main Menu game select Stuff
	mPlayModes = new GameEntity(GraphicsManager::SCREEN_WIDTH * 0.5f, GraphicsManager::SCREEN_HEIGHT * 0.35f);
	mPlayModes->Parent(this);

	mOnePlayerMode = new Texture("1 Player ", "Computerfont.ttf", 32, { 0, 68, 240 });
	mTwoPlayerMode = new Texture("2 Players", "Computerfont.ttf", 32, { 0, 68, 240 });
	mOnePlayerMode->Parent(mPlayModes);
	mTwoPlayerMode->Parent(mPlayModes);
	mOnePlayerMode->Position(0.0f, -35.0f);
	mTwoPlayerMode->Position(0.0f, 35.0f);


	mCursor = new Texture("Cursor.png");
	mCursor->Parent(mPlayModes);
	mCursor->Position(-175.0f, -35.0f);
	mCursorStartPos = mCursor->Position(Local);
	mCursorOffset = Vector2(0.0f, 70.0f);

	mSelectedMode = 0;

	// Animated Rainbow

	mAnimatedSection = new GameEntity(GraphicsManager::SCREEN_WIDTH * 0.5f, GraphicsManager::SCREEN_HEIGHT * 0.6f);
	mAnimatedSection->Parent(this);

	lastChange = 0;
	changeIncrement = 0.08f;
	frameToRender = 0;

	SetFrameOneSprites(aFrameOneRow1, 0, 0);
	SetFrameOneSprites(aFrameOneRow2, 0, 24);
	SetFrameOneSprites(aFrameOneRow3, 0, 48);
	SetFrameOneSprites(aFrameOneRow4, 0, 72);
	SetFrameOneSprites(aFrameOneRow5, 0, 96);

	SetFrameTwoSprites(aFrameTwoRow1, 0, 0);
	SetFrameTwoSprites(aFrameTwoRow2, 0, 24);
	SetFrameTwoSprites(aFrameTwoRow3, 0, 48);
	SetFrameTwoSprites(aFrameTwoRow4, 0, 72);
	SetFrameTwoSprites(aFrameTwoRow5, 0, 96);

	SetFrameThreeSprites(aFrameThreeRow1, 0, 0);
	SetFrameThreeSprites(aFrameThreeRow2, 0, 24);
	SetFrameThreeSprites(aFrameThreeRow3, 0, 48);
	SetFrameThreeSprites(aFrameThreeRow4, 0, 72);
	SetFrameThreeSprites(aFrameThreeRow5, 0, 96);

	SetFrameFourSprites(aFrameFourRow1, 0, 0);
	SetFrameFourSprites(aFrameFourRow2, 0, 24);
	SetFrameFourSprites(aFrameFourRow3, 0, 48);
	SetFrameFourSprites(aFrameFourRow4, 0, 72);
	SetFrameFourSprites(aFrameFourRow5, 0, 96);

	// Animated Pyramid thingy

	for (int i = 0; i < gridHeight; i++)
	{
		for (int j = 0; j < gridWidth; j++)
		{
			switch (aPyramidLayout[i][j])
			{
			case 0:
				aPyramidBuild[i][j] = nullptr;
				break;
			case 1:
				aPyramidBuild[i][j] = new AnimatedTexture("TopperSpriteSheet.png", 0, 0, 32, 32, 4, changeIncrement * 10, AnimatedTexture::Horizontal);
				aPyramidBuild[i][j]->Parent(mAnimatedSection);
				break;
			case 2:
				aPyramidBuild[i][j] = new AnimatedTexture("TopperSpriteSheet.png", 0, 32, 32, 32, 4, changeIncrement * 10, AnimatedTexture::Horizontal);
				aPyramidBuild[i][j]->Parent(mAnimatedSection);
				break;
			case 3:
				aPyramidBuild[i][j] = new AnimatedTexture("TopperSpriteSheet.png", 0, 64, 32, 32, 4, changeIncrement * 10, AnimatedTexture::Horizontal);
				aPyramidBuild[i][j]->Parent(mAnimatedSection);
				break;
			case 4:
				aPyramidBuild[i][j] = new AnimatedTexture("TopperSpriteSheet.png", 0, 96, 32, 32, 4, changeIncrement * 10, AnimatedTexture::Horizontal);
				aPyramidBuild[i][j]->Parent(mAnimatedSection);
				break;
			default:
				break;
			}
		}
	}
	for (int i = 0; i < gridHeight; i++)
	{
		for (int j = 0; j < gridWidth; j++)
		{
			if (aPyramidBuild[i][j] != nullptr)
			{
				float tempX = (j * 16) - 35;
				float tempY = (-120 + (i * 32));
				aPyramidBuild[i][j]->Position(tempX, tempY);
			}
		}
	}

}

MainMenu::~MainMenu()
{
	//Top Banner Entities

	delete StartScreenTopBanner;
	StartScreenTopBanner = nullptr;

	delete PlayerOneSubBar;
	PlayerOneSubBar = nullptr;
	delete PlayerTwoSubBar;
	PlayerTwoSubBar = nullptr;
	delete HighScoreSubBar;
	HighScoreSubBar = nullptr;

	delete VSPlayerOneWins;
	VSPlayerOneWins = nullptr;
	delete VSPlayerTwoWins;
	VSPlayerTwoWins = nullptr;
	delete OnePlayerHighScore;
	OnePlayerHighScore = nullptr;

	delete P1Wins;
	P1Wins = nullptr;
	delete P2Wins;
	P2Wins = nullptr;
	delete HighScoreValue;
	HighScoreValue = nullptr;

	// play mode entities
	delete mPlayModes;
	mPlayModes = nullptr;
	delete mOnePlayerMode;
	mOnePlayerMode = nullptr;
	delete mTwoPlayerMode;
	mTwoPlayerMode = nullptr;
	delete mCursor;
	mCursor = nullptr;

}

int MainMenu::SelectedMode()
{
	return mSelectedMode;
}

void MainMenu::ChangeSelectedMode(int change)
{
	mSelectedMode += change;
	if (mSelectedMode < 0)
	{
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1)
	{
		mSelectedMode = 0;
	}
	mCursor->Position(mCursorStartPos + mCursorOffset * (float)mSelectedMode);
}

void MainMenu::Update()
{
	currentTime += mTimer->GetDeltaTime();
	for (int i = 0; i < gridHeight; i++)
	{
		for (int j = 0; j < gridWidth; j++)
		{
			if (aPyramidBuild[i][j] != nullptr)
			{
				aPyramidBuild[i][j]->Update();
			}
		}
	}

	if (mInput->KeyPressed(SDL_SCANCODE_DOWN) || mInput->KeyPressed(SDL_SCANCODE_UP))
	{
		mAnimationTimer = mAnimationTotalTime;
	}

	if (mAnimationTimer >= mAnimationTotalTime)
	{
		mAnimationDone = true;
	}

	if (mInput->KeyPressed(SDL_SCANCODE_DOWN))
	{
		ChangeSelectedMode(1);
	}
	else if (mInput->KeyPressed(SDL_SCANCODE_UP))
	{
		ChangeSelectedMode(-1);
	}
}

void MainMenu::Render()
{
	//Top Banner Rendering
	VSPlayerOneWins->Render();
	VSPlayerTwoWins->Render();
	OnePlayerHighScore->Render();

	P1Wins->Render();
	P2Wins->Render();
	HighScoreValue->Render();


	mOnePlayerMode->Render();
	mTwoPlayerMode->Render();
	mCursor->Render(); 

	for (int i = 0; i < gridHeight; i++)
	{
		for (int j = 0; j < gridWidth; j++)
		{
			if (aPyramidBuild[i][j] != nullptr)
			{
				aPyramidBuild[i][j]->Render();
			}
		}
	}

	if (currentTime >= lastChange + changeIncrement)
	{
		lastChange = currentTime;
		frameToRender++;
		if (frameToRender > 3)
		{
			frameToRender = 0;
		}
	}

	switch (frameToRender)
	{
	case 0:
		for (int i = 0; i < rowSize; i++)
		{
			aFrameOneRow1[i]->Render();
			aFrameOneRow2[i]->Render();
			aFrameOneRow3[i]->Render();
			aFrameOneRow4[i]->Render();
			aFrameOneRow5[i]->Render();
		}
		break;
	case 1:
		for (int i = 0; i < rowSize; i++)
		{
			aFrameTwoRow1[i]->Render();
			aFrameTwoRow2[i]->Render();
			aFrameTwoRow3[i]->Render();
			aFrameTwoRow4[i]->Render();
			aFrameTwoRow5[i]->Render();
		}
		break;
	case 2:
		for (int i = 0; i < rowSize; i++)
		{
			aFrameThreeRow1[i]->Render();
			aFrameThreeRow2[i]->Render();
			aFrameThreeRow3[i]->Render();
			aFrameThreeRow4[i]->Render();
			aFrameThreeRow5[i]->Render();
		}
		break;
	case 3:
		for (int i = 0; i < rowSize; i++)
		{
			aFrameFourRow1[i]->Render();
			aFrameFourRow2[i]->Render();
			aFrameFourRow3[i]->Render();
			aFrameFourRow4[i]->Render();
			aFrameFourRow5[i]->Render();
		}
		break;
	default:
		break;
	}


}

void MainMenu::SetFrameOneSprites(Texture* row[], float rootX, float rootY)
{
	row[0] = new Texture("TronSpriteSheet.png", 330, 99, 32, 32);
	row[1] = new Texture("TronSpriteSheet.png", 371, 99, 24, 32);
	row[2] = new Texture("TronSpriteSheet.png", 396, 99, 32, 32);
	row[3] = new Texture("TronSpriteSheet.png", 0, 132, 32, 32);
	row[4] = new Texture("TronSpriteSheet.png", 33, 132, 24, 32);
	row[5] = new Texture("TronSpriteSheet.png", 66, 132, 32, 32);


	float spriteStart = -64;
	float spriteGap = 32;
	for (int i = 0; i < rowSize; i++)
	{
		float adjustedY = 0;
		float adjustedX = 0;
		if (i == 0 || i == 5)
		{
			adjustedY = -10;
			if (i == 0)
			{
				adjustedX = 10;
			}
			if (i == 5)
			{
				adjustedX = -10;
			}
		}
		if (i == 1 || i == 4)
		{
			adjustedY = -4;
			if (i == 1)
			{
				adjustedX = 6;
			}
			if (i == 4)
			{
				adjustedX = -6;
			}
		}
		row[i]->Parent(mAnimatedSection);
		row[i]->Position(spriteStart + (spriteGap * i) + adjustedX + rootX, adjustedY + rootY);
	}
}

void MainMenu::SetFrameTwoSprites(Texture* row[], float rootX, float rootY)
{
	row[0] = new Texture("TronSpriteSheet.png", 760, 99, 32, 32);
	row[1] = new Texture("TronSpriteSheet.png", 801, 99, 24, 32);
	row[2] = new Texture("TronSpriteSheet.png", 826, 99, 32, 32);
	row[3] = new Texture("TronSpriteSheet.png", 430, 132, 32, 32);
	row[4] = new Texture("TronSpriteSheet.png", 463, 132, 24, 32);
	row[5] = new Texture("TronSpriteSheet.png", 496, 132, 32, 32);


	float spriteStart = -64;
	float spriteGap = 32;
	for (int i = 0; i < rowSize; i++)
	{
		float adjustedY = 0;
		float adjustedX = 0;
		if (i == 0 || i == 5)
		{
			adjustedY = -10;
			if (i == 0)
			{
				adjustedX = 10;
			}
			if (i == 5)
			{
				adjustedX = -10;
			}
		}
		if (i == 1 || i == 4)
		{
			adjustedY = -4;
			if (i == 1)
			{
				adjustedX = 6;
			}
			if (i == 4)
			{
				adjustedX = -6;
			}
		}
		row[i]->Parent(mAnimatedSection);
		row[i]->Position(spriteStart + (spriteGap * i) + adjustedX + rootX, adjustedY + rootY);
	}

	mOnePlayerMode->Render();
	mTwoPlayerMode->Render();
	mCursor->Render();
}

void MainMenu::SetFrameThreeSprites(Texture* row[], float rootX, float rootY)
{
	row[0] = new Texture("TronSpriteSheet.png", 330, 265, 32, 32);
	row[1] = new Texture("TronSpriteSheet.png", 371, 265, 24, 32);
	row[2] = new Texture("TronSpriteSheet.png", 396, 265, 32, 32);
	row[3] = new Texture("TronSpriteSheet.png", 0,   298, 32, 32);
	row[4] = new Texture("TronSpriteSheet.png", 33,  298, 24, 32);
	row[5] = new Texture("TronSpriteSheet.png", 66,  298, 32, 32);


	float spriteStart = -64;
	float spriteGap = 32;
	for (int i = 0; i < rowSize; i++)
	{
		float adjustedY = 0;
		float adjustedX = 0;
		if (i == 0 || i == 5)
		{
			adjustedY = -10;
			if (i == 0)
			{
				adjustedX = 10;
			}
			if (i == 5)
			{
				adjustedX = -10;
			}
		}
		if (i == 1 || i == 4)
		{
			adjustedY = -4;
			if (i == 1)
			{
				adjustedX = 6;
			}
			if (i == 4)
			{
				adjustedX = -6;
			}
		}
		row[i]->Parent(mAnimatedSection);
		row[i]->Position(spriteStart + (spriteGap * i) + adjustedX + rootX, adjustedY + rootY);
	}
}

void MainMenu::SetFrameFourSprites(Texture* row[], float rootX, float rootY)
{
	row[0] = new Texture("TronSpriteSheet.png", 760, 265, 32, 32);
	row[1] = new Texture("TronSpriteSheet.png", 801, 265, 24, 32);
	row[2] = new Texture("TronSpriteSheet.png", 826, 265, 32, 32);
	row[3] = new Texture("TronSpriteSheet.png", 430, 298, 32, 32);
	row[4] = new Texture("TronSpriteSheet.png", 463, 298, 24, 32);
	row[5] = new Texture("TronSpriteSheet.png", 496, 298, 32, 32);


	float spriteStart = -64;
	float spriteGap = 32;
	for (int i = 0; i < rowSize; i++)
	{
		float adjustedY = 0;
		float adjustedX = 0;
		if (i == 0 || i == 5)
		{
			adjustedY = -10;
			if (i == 0)
			{
				adjustedX = 10;
			}
			if (i == 5)
			{
				adjustedX = -10;
			}
		}
		if (i == 1 || i == 4)
		{
			adjustedY = -4;
			if (i == 1)
			{
				adjustedX = 6;
			}
			if (i == 4)
			{
				adjustedX = -6;
			}
		}
		row[i]->Parent(mAnimatedSection);
		row[i]->Position(spriteStart + (spriteGap * i) + adjustedX + rootX, adjustedY + rootY);
	}
}
