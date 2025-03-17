#pragma once
#include "BaseComponent.h"
#include "Observer.h"

namespace dae
{
	class GameObject;

	class PlayerComp : public BaseComponent
	{
	public:
		PlayerComp(GameObject* ob, int hp) : BaseComponent(ob), m_HP{ hp } {}

		void TakeDamage(int damage);
		void AddScore(int val);
		int GetHP() const { return m_HP; }
		int GetScore() const { return m_score; }

	private:
		int m_HP;
		int m_score{};
	};
}

