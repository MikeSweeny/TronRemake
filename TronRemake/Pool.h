#ifndef __POOL_H
#define __POOL_H

#include "Texture.h"
#include <vector>

using namespace SDLFramework;

static class Pool : public GameEntity
{
public:

	std::vector<Texture*> mBluePool;
	std::vector<Texture*> mOrangePool;

private:

	static Pool* sInstance;
	int mPoolSize = 500;
	std::string mBSheetName = "bikeSheet.png";
	std::string mOSheetName = "aiBikeSheet.png";
	void AddToBPool(int mPoolSize);
	void AddToOPool(int mPoolSize);

public:

	Pool();
	~Pool();
	static Pool* Instance();
	Texture* GetTileFromBPool();
	Texture* GetTileFromOPool();
	void ReturnToPool(Texture* tile);
	std::vector<Texture*> GetBPool();
	std::vector<Texture*> GetOPool();
	void Render();

};


#endif // !_POOL__H