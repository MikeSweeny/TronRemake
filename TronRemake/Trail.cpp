#include "Trail.h"

Trail::Trail() {}

Trail::Trail(std::string sheetName)
{
	sPool = new Pool();
	mSheetName = sheetName;
	if (mSheetName == "bikeSheet.png")
	{
		mBPool = sPool->GetBPool();
	}
	if (mSheetName == "aiBikeSheet.png")
	{
		mOPool = sPool->GetOPool();
	}
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
	
	newTrail->Position(pos);
}

std::vector<Texture*> Trail::GetBPool()
{
	return mBPool;
}

std::vector<Texture*> Trail::GetOPool()
{
	return mOPool;
}