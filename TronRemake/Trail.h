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
	void Update();
	void Render();

private:
	Texture* trailBlock;
	std::vector<Texture*> pool;

	Texture* GetTileFromPool();
};


#endif // !__TRAIL_H