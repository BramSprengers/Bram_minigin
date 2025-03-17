#include <string>
#include <vector>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "BaseComponent.h"
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

void dae::GameObject::SetParent(GameObject* parent, bool keepWorldPosition)
{
	if (IsChild(parent) || parent == this || m_parent == parent)
		return;
	if (parent == nullptr)
		SetLocalPosition(GetWorldPosition());
	else
	{
		if (keepWorldPosition)
			SetLocalPosition(GetWorldPosition() - parent->GetWorldPosition());
		SetPositionDirty();
	}
	if (m_parent) m_parent->RemoveChild(this);
	m_parent = parent;
	if (m_parent) m_parent->AddChild(this);

}

void dae::GameObject::SetLocalPosition(const glm::vec3& pos)
{
	m_localPosition = pos;
	SetPositionDirty();
}

void dae::GameObject::SetPositionDirty()
{
	m_positionIsDirty = true;
	for (auto& child : m_children)
	{
		child->SetPositionDirty();
	}
}

void dae::GameObject::RemoveComp()
{
	for (auto& comp : m_Components)
	{
		if (comp->IsDead())
		{
			comp->Remove();
			m_Components.erase(std::remove(m_Components.begin(), m_Components.end(), comp), m_Components.end());
		}
	}
}

const glm::vec3& dae::GameObject::GetWorldPosition()
{
	if (m_positionIsDirty)
		UpdateWorldPosition();
	return m_worldPosition;
}
dae::BaseComponent* dae::GameObject::GetComponent(const BaseComponent& comp)
{
	for (auto base : m_Components)
	{
		if (typeid(*base) == typeid(comp))
		{
			return base;
		}
	}

	return nullptr;
}
void dae::GameObject::UpdateWorldPosition()
{
	if (m_positionIsDirty)
	{
		if (m_parent == nullptr)
			m_worldPosition = m_localPosition;
		else
			m_worldPosition = m_parent->GetWorldPosition() + m_localPosition;
	}
	m_positionIsDirty = false;
}

bool dae::GameObject::IsChild(GameObject* ob)
{
	for (auto chiled : m_children)
	{
		if (chiled == ob)
			return true;
	}
	return false;
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
	m_worldPosition = { x, y, 0 };
	m_localPosition = { x, y, 0 };
}
