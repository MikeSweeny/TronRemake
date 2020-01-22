#include "MainMenu.h"

MainMenu::MainMenu()
{
	mTimer = Timer::GetInstance();
	mInput = InputManager::Instance();
	mAnimatedRainbow = new GameEntity(GraphicsManager::SCREEN_WIDTH * 0.5f, GraphicsManager::SCREEN_HEIGHT * 0.4f);
	mAnimatedRainbow->Parent(this);

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
}

void MainMenu::Render()
{
	for (int i = 0; i < rowSize; i++)
	{
		aFrameOneRow[i]->Render();
	}
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