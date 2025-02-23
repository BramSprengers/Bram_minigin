#include "BaseComponent.h"
#include "GameObject.h"

dae::BaseComponent::~BaseComponent()
{
	m_pOwner = nullptr;
}

void dae::BaseComponent::Update(float)
{
}

void dae::BaseComponent::FixedUpdate(float)
{
}

void dae::BaseComponent::Render() const
{
}
