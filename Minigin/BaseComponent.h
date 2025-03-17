#pragma once
//#include "Observer.h"
#include <vector>

namespace dae
{
	class GameObject;
	class Observer;
	enum class Event;
	class BaseComponent
	{
	public:
		explicit BaseComponent(GameObject* pOwner) : m_pOwner{ pOwner } {};
		BaseComponent() : m_pOwner{} {};
		virtual ~BaseComponent();

		BaseComponent(const	BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const	BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;

		virtual void Update(float deltaTime);
		virtual void FixedUpdate(float fixedDeltaTime);
		virtual void Render() const;

		void MarktDead() { m_IsDead = true; }
		bool IsDead() const { return m_IsDead; }

		void AddObserver(Observer* ov) { m_observer.push_back(ov); }
		void RemoveObserver(Observer* ov) { m_observer.erase(std::remove(m_observer.begin(), m_observer.end(), ov)); }

		void Remove() { delete this; }

	protected:
		GameObject* GetOwner() const { return m_pOwner; }

		void NotifyObservers(Event ev);

	private:
		GameObject* m_pOwner;
		bool m_IsDead{ false };

		std::vector<Observer*> m_observer;
	};
}

