#ifndef __POOL_H
#define __POOL_H

#include "Texture.h"
#include <vector>

using namespace SDLFramework;

static class Pool
{
public:

	std::vector<Texture*> mPool;

private:

	static Pool* sInstance;
	int mPoolSize = 150;
	std::string mSheetName;
	void SetSheetName(std::string name);
	void AddToPool(int mPoolSize);

public:

	Pool();
	Pool(std::string sheetName);
	~Pool();
	static Pool* Instance();
	Texture* GetTileFromPool();
	std::vector<Texture*>* GetPool();

};


#endif // !_POOL__H