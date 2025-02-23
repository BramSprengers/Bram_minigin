#include <string>
#include <vector>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "TextObject.h"
#include "Texture2D.h"

void dae::GameObject::AddComponent(BaseComponent* comp)
{
	m_Components.emplace_back(std::move(comp));
}

dae::GameObject::~GameObject()
{
	for (const auto& comp : m_Components)
	{
		delete comp;
	}
}

void dae::GameObject::Update(float deltaTime)
{
	for(const auto& comp : m_Components)
	{
		comp->Update(deltaTime);
	}
}

void dae::GameObject::FixedUpdate(float fixedTime)
{
	for (const auto& comp : m_Components)
	{
		comp->FixedUpdate(fixedTime);
	}
}

void dae::GameObject::Render() const
{
	for (const auto& comp : m_Components)
	{
		comp->Render();
	}
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}
