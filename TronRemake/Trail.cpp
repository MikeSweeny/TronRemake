#include "Trail.h"

Trail::Trail()
{
	trailBlock = new Texture(mSheetName, 14, 25, 4, 4);
	AddToPool(mPoolSize);
}

Trail::~Trail()
{

}

void Trail::Render()
{
	for (int i = 0; i < pool.size - 1; i++)
	{
		pool[i]->Render();
	}
}

void Trail::PlaceTrail(Vector2 pos)
{
	GetTileFromPool()->Position(pos);
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
		pool.push_back(temp);
	}
}

Texture* Trail::GetTileFromPool()
{
	for (int i = 0; i < pool.size - 1; i++)
	{
		if (!pool[i]->isActive)
		{
			return pool[i];
		}
		else
		{
			AddToPool(1);
			return pool[i];
		}
	}
}