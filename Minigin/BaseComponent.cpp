#include "BaseComponent.h"
#include "GameObject.h"
#include "Observer.h"

dae::BaseComponent::~BaseComponent()
{
	m_pOwner = nullptr;
	for (int i = 0; i < (int)m_observer.size(); i++)
	{
		delete m_observer[i];
	}
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

void dae::BaseComponent::NotifyObservers(dae::Event ev)
{
	{
		for (auto obs : m_observer)
			obs->OnNotify(GetOwner(), ev);
	}
}
