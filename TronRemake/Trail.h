#ifndef __TRAIL_H
#define __TRAIL_H
#include "Texture.h"
#include <vector>

using namespace SDLFramework;

class Trail : GameEntity
{
public:
	Trail();
	~Trail();
	void Render();
	void PlaceTrail(Vector2 pos);
	void SetSheetName(std::string name);

private:
	Texture* trailBlock;
	std::vector<Texture*> pool;
	int mPoolSize = 50;
	std::string mSheetName;

	void AddToPool(int mPoolSize);
	Texture* GetTileFromPool();
};


#endif // !__TRAIL_H