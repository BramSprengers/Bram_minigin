#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "TextObject.h"
#include "Texture2D.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(float deltaTime)
{
	if (m_text != nullptr)
		m_text->Update();

	deltaTime = 0;
}

void dae::GameObject::Render() const
{
	if (m_texture != nullptr)
		m_texture->Render(*this);

	if (m_text != nullptr)
		m_text->Render(*this);
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

std::shared_ptr<dae::TextObject> dae::GameObject::GetTextObject()
{
	return m_text;
}

void dae::GameObject::SetTextObject(std::shared_ptr<TextObject> text)
{
	m_text = text;
}
