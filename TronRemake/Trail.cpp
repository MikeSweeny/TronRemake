#include "Trail.h"

Trail::Trail() {}

Trail::Trail(std::string sheetName)
{
	mPool = sPool->GetPool();
	mSheetName = sheetName;
	sPool = new Pool(mSheetName);
}

Trail::~Trail()
{

}

void Trail::Render()
{
	for (int i = 0; i < mPool->size() - 1; i++)
	{
		//mPool[i]->Render();
		//mPool[i]->Render();
	}
}


void Trail::PlaceTrail(Vector2 pos)
{
	Texture* newTrail = sPool->GetTileFromPool();
	newTrail->Position(pos);
}

std::vector<Texture*>* Trail::GetPool()
{
	return mPool;
}
