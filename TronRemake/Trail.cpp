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
}

void Trail::SetSheetName(std::string name)
{
	mSheetName = name;
}

bool Trail::CheckCollisions(Vector2 pos1)
{
	for (int i = 0; i < mPool.size() - 1; i++)
	{
		if ((pos1.x > mPool[i]->Position().x && pos1.x < mPool[i]->Position().x + 6) &&
			(pos1.y > mPool[i]->Position().y && pos1.y < mPool[i]->Position().y + 6)) 
		{
			return true;
		}
	}
	return false;
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