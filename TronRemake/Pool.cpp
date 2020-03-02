#include "Pool.h"

Pool* Pool::sInstance = nullptr;

Pool::Pool()
{
	AddToPool(mPoolSize);
}

Pool::Pool(std::string sheetName)
{
	SetSheetName(sheetName);
	AddToPool(mPoolSize);
}

Pool::~Pool()
{

}

Pool* Pool::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new Pool();
	}
	return sInstance;
}


void Pool::SetSheetName(std::string name)
{
	mSheetName = name;
}

void Pool::AddToPool(int mPoolSize)
{
	for (int i = 0; i < mPoolSize; i++)
	{
		Texture* temp = new Texture(mSheetName, 13, 25, 6, 6);
		temp->Position(-100, -100);
		temp->isActive = false;
		mPool.push_back(temp);
	}
}

Texture* Pool::GetTileFromPool()
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

std::vector<Texture*>* Pool::GetPool()
{
	return &mPool;
}
