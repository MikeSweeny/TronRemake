#ifndef __TRAIL_H
#define __TRAIL_H
#include "Texture.h"
#include "Pool.h"
#include <vector>

using namespace SDLFramework;

class Trail : public GameEntity
{
public:

	Trail();
	Trail(std::string sheetName);
	~Trail();
	void Render();
	std::vector<Texture*>* mPool;
	void PlaceTrail(Vector2 pos);
	std::vector<Texture*>* GetPool();
	std::string mSheetName;

private:

	Pool* sPool;

};


#endif // !__TRAIL_H