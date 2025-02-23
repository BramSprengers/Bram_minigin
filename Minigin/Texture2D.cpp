#include <SDL.h>
#include <SDL_image.h>
#include "Texture2D.h"
#include "Renderer.h"
#include <stdexcept>
#include "Gameobject.h"

dae::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_texture);
}

void dae::Texture2D::Render() const
{
	
	Renderer::GetInstance().RenderTexture(*this, this->GetOwner()->GetPosition().x, this->GetOwner()->GetPosition().x);

}

glm::ivec2 dae::Texture2D::GetSize() const
{
	SDL_Rect dst;
	SDL_QueryTexture(GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h);
	return { dst.w,dst.h };
}

SDL_Texture* dae::Texture2D::GetSDLTexture() const
{
	return m_texture;
}

dae::Texture2D::Texture2D(GameObject* ob, const std::string &fullPath) : BaseComponent(ob)
{
	m_texture = IMG_LoadTexture(Renderer::GetInstance().GetSDLRenderer(), fullPath.c_str());
	if (m_texture == nullptr)
		throw std::runtime_error(std::string("Failed to load texture: ") + SDL_GetError());
}

dae::Texture2D::Texture2D(GameObject* ob, SDL_Texture* texture) : BaseComponent(ob), m_texture{texture}
{
	assert(m_texture != nullptr);
}

dae::Texture2D::Texture2D(const std::string& fullPath) : BaseComponent(nullptr)
{
	m_texture = IMG_LoadTexture(Renderer::GetInstance().GetSDLRenderer(), fullPath.c_str());
	if (m_texture == nullptr)
		throw std::runtime_error(std::string("Failed to load texture: ") + SDL_GetError());
}

dae::Texture2D::Texture2D(SDL_Texture* texture) : BaseComponent(nullptr), m_texture{ texture }
{
	assert(m_texture != nullptr);
}

