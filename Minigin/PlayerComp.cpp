#include "PlayerComp.h"


void dae::PlayerComp::TakeDamage(int damage)
{
	m_HP -= damage;
	NotifyObservers(Event::TOOK_DAMAGE);

	if (m_HP <= 0)
	{
			NotifyObservers(Event::IS_DEAD);
	}
}

void dae::PlayerComp::AddScore(int val)
{
	m_score += val;
	NotifyObservers(Event::POINT_INCREASE);
}
