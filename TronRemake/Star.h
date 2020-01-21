#ifndef __STAR_H
#define __STAR_H
#include "Texture.h"
#include "Timer.h"
#include "Random.h"

namespace SDLFramework
{
	class Star : public Texture
	{

	private:
		static bool mScroll;
		Timer* mTimer;
		Random* mRand;
		bool mVisible;
		float mFlickerTimer;
		float mFlickerSpeed;
		float mScrollSpeed;

		void ScrollStar();

	public:
		Star(int layer);
		~Star();
		void Update();
		void Render();

		static void Scroll(bool b);

	};
}

#endif