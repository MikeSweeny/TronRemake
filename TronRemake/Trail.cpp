#include "Trail.h"

Trail::Trail() {}

Trail::Trail(std::string sheetName)
{
	SetSheetName(sheetName);
	AddToPool(mPoolSize);
}

Trail::~Trail()
{

}

void Trail::Render()
{
	for (int i = 0; i < mPool.size() - 1; i++)
	{
		mPool[i]->Render();
	}
}

void Trail::PlaceTrail(Vector2 pos)
{
	Texture* newTrail = GetTileFromPool();
	newTrail->Position(pos);
	//std::cout << "x: " << newTrail->Position().x << "    y: " << newTrail->Position().y << std::endl;
}

void Trail::SetSheetName(std::string name)
{
	mSheetName = name;
}

void Trail::AddToPool(int mPoolSize)
{
	for (int i = 0; i < mPoolSize; i++)
	{
		Texture* temp = new Texture(mSheetName, 14, 25, 4, 4);
		temp->Position(-100, -100);
		temp->isActive = false;
		mPool.push_back(temp);
	}
}

Texture* Trail::GetTileFromPool()
{
	for (int i = 0; i < mPool.size() - 1; i++)
	{
		if (!mPool[i]->isActive)
		{
			mPool[i]->isActive = true;
			return mPool[i];
		}
		else
		{
			break;
		}
	}
	AddToPool(1);
	return mPool[mPool.size() - 1];
}