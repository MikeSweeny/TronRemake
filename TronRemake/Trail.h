#ifndef __TRAIL_H
#define __TRAIL_H
#include "Texture.h"
#include <vector>

using namespace SDLFramework;

class Trail : public GameEntity
{
public:
	Trail();
	Trail(std::string sheetName);
	~Trail();
	void Render();
	void PlaceTrail(Vector2 pos);
	void SetSheetName(std::string name);
	std::vector<Texture*> mPool;
	bool CheckCollisions();

private:
	int mPoolSize = 50;
	std::string mSheetName;

	void AddToPool(int mPoolSize);
	Texture* GetTileFromPool();
};


#endif // !__TRAIL_H