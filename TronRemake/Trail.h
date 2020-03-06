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
	std::vector<Texture*> mBPool;
	std::vector<Texture*> mOPool;
	std::vector<Texture*> mTrail;
	void PlaceTrail(Vector2 pos);
	void ResetTrail();
	std::vector<Texture*> GetBPool();
	std::vector<Texture*> GetOPool();
	std::string mSheetName;

private:

	Pool* sPool;

};


#endif // !__TRAIL_H