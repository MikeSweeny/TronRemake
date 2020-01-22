#include "MainMenu.h"

MainMenu::MainMenu()
{
	mTimer = Timer::GetInstance();
	mInput = InputManager::Instance();
	mAnimatedRainbow = new GameEntity(GraphicsManager::SCREEN_WIDTH * 0.5f, GraphicsManager::SCREEN_HEIGHT * 0.4f);
	mAnimatedRainbow->Parent(this);

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

	// 
	SetFrameSprites();

	float spriteStart = -64;
	float spriteGap = 32;
	for (int i = 0; i < rowSize; i++)
	{
		aFrameOneRow[i]->Parent(mAnimatedRainbow);
		aFrameOneRow[i]->Position(spriteStart + (spriteGap * i), 0);
	}
}

MainMenu::~MainMenu()
{

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
	for (int i = 0; i < rowSize; i++)
	{
		aFrameOneRow[i]->Render();
	}

	mOnePlayerMode->Render();
	mTwoPlayerMode->Render();
	mCursor->Render();

}

void MainMenu::SetFrameSprites()
{
	aFrameOneRow[0] = new Texture("TronSpriteSheet", 330, 99, 32, 32);
	aFrameOneRow[1] = new Texture("TronSpriteSheet", 363, 99, 32, 32);
	aFrameOneRow[2] = new Texture("TronSpriteSheet", 396, 99, 32, 32);
	aFrameOneRow[3] = new Texture("TronSpriteSheet", 0, 132, 32, 32);
	aFrameOneRow[4] = new Texture("TronSpriteSheet", 33, 132, 32, 32);
	aFrameOneRow[5] = new Texture("TronSpriteSheet", 66, 132, 32, 32);
}

