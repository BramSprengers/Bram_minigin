#pragma once
#include <vec2.hpp>
#include <string>
#include "BaseComponent.h"

struct SDL_Texture;
namespace dae
{
	/**
	 * Simple RAII wrapper for an SDL_Texture
	 */
	class Texture2D final : BaseComponent
	{
	public:
		SDL_Texture* GetSDLTexture() const;
		explicit Texture2D(GameObject* ob, SDL_Texture* texture);
		explicit Texture2D(GameObject* ob, const std::string& fullPath);
		~Texture2D();

		void Render() const;

		glm::ivec2 GetSize() const;

		Texture2D(const Texture2D &) = delete;
		Texture2D(Texture2D &&) = delete;
		Texture2D & operator= (const Texture2D &) = delete;
		Texture2D & operator= (const Texture2D &&) = delete;
	private:
		SDL_Texture* m_texture;
	};
}
