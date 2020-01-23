#ifndef __ASSETMANAGER_H
#define __ASSETMANAGER_H
#include "GraphicsManager.h"
#include <map>
#include <SDL_Mixer.h>

namespace SDLFramework 
{
	class AssetManager 
	{

	private:
		static AssetManager* sInstance;
		std::map<std::string, SDL_Texture*> mTextures;
		std::map<SDL_Texture*, unsigned> mTextureRefCount;

		std::map<std::string, TTF_Font*> mFonts;
		std::map<std::string, SDL_Texture*> mText;
		TTF_Font* GetFont(std::string filename, int size);

		std::map<std::string, Mix_Music*> mMusic;
		std::map<std::string, Mix_Chunk*> mSFX;
		std::map<Mix_Music*, unsigned> mMusicRefCount;
		std::map<Mix_Chunk*, unsigned*> mSFXRefCount;

		AssetManager();
		~AssetManager();

	public:
		SDL_Texture* GetText(std::string text, std::string filename, int size, SDL_Color color, bool managed = false);

		static AssetManager* Instance();
		static void Release();
		SDL_Texture* GetTexture(std::string filename, bool managed = false);
		void DestroyTexture(SDL_Texture* texture);

		Mix_Music* GetMusic(std::string filename, bool managed = false);
		Mix_Chunk* GetSFX(std::string filename, bool managed = false);
		void DestroyMusic(Mix_Music* music);
		void DestroySFX(Mix_Chunk* sfx);

	};
}
#endif