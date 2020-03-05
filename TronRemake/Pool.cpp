#include "Pool.h"

Pool* Pool::sInstance = nullptr;

Pool::Pool()
{
	AddToBPool(mPoolSize);
	AddToOPool(mPoolSize);
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

void Pool::AddToBPool(int mPoolSize)
{
	for (int i = 0; i < mPoolSize; i++)
	{
		Texture* temp = new Texture(mBSheetName, 13, 25, 6, 6);
		Parent(this->Parent());
		temp->Position(-100, -100);
		temp->isActive = false;
		mBluePool.push_back(temp);
	}
}

void Pool::AddToOPool(int mPoolSize)
{
	for (int i = 0; i < mPoolSize; i++)
	{
		Texture* temp = new Texture(mOSheetName, 13, 25, 6, 6);
		Parent(this->Parent());
		temp->Position(-100, -100);
		temp->isActive = false;
		mOrangePool.push_back(temp);
	}
}

Texture* Pool::GetTileFromBPool()
{
	for (int i = 0; i <= mBluePool.size() - 1; i++)
	{
		if (!mBluePool[i]->isActive)
		{
			mBluePool[i]->isActive = true;
			return mBluePool[i];
		}
		else if (i == mBluePool.size() - 1)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	AddToBPool(50);
	return mBluePool[mBluePool.size() - 1];
}

Texture* Pool::GetTileFromOPool()
{
	for (int i = 0; i <= mOrangePool.size() - 1; i++)
	{
		if (!mOrangePool[i]->isActive)
		{
			mOrangePool[i]->isActive = true;
			return mOrangePool[i];
		}
		else if (i == mOrangePool.size() - 1)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	AddToOPool(50);
	return mOrangePool[mOrangePool.size() - 1];
}

std::vector<Texture*> Pool::GetBPool()
{
	return mBluePool;
}

std::vector<Texture*> Pool::GetOPool()
{
	return mOrangePool;
}

void Pool::Render()
{
	if (!mBluePool.empty())
	{
		for (int i = 0; i < mBluePool.size() - 1; i++)
		{
			mBluePool[i]->Render();
		}
	}
	if (!mOrangePool.empty())
	{
		for (int i = 0; i < mOrangePool.size() - 1; i++)
		{
			mOrangePool[i]->Render();
		}
	}
}
