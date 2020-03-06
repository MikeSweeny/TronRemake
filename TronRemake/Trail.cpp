#include "Trail.h"

Trail::Trail() {}

Trail::Trail(std::string sheetName)
{
	sPool = Pool::Instance();
	sPool->Parent(this->Parent());
	mSheetName = sheetName;
	mBPool = sPool->GetBPool();
	mOPool = sPool->GetOPool();
}

Trail::~Trail()
{

}

void Trail::Render()
{
	sPool->Render();
}


void Trail::PlaceTrail(Vector2 pos)
{
	Texture* newTrail = 0;
	if (mSheetName == "bikeSheet.png")
	{
		newTrail = sPool->GetTileFromBPool();
	}
	if (mSheetName == "aiBikeSheet.png")
	{
		newTrail = sPool->GetTileFromOPool();
	}
	mTrail.push_back(newTrail);
	newTrail->Position(pos);
}

void Trail::ResetTrail()
{
	for (int i = 0; i < mTrail.size() - 1; i++)
	{
		sPool->ReturnToPool(mTrail[i]);
	}
}

std::vector<Texture*> Trail::GetBPool()
{
	return mBPool;
}

std::vector<Texture*> Trail::GetOPool()
{
	return mOPool;
}