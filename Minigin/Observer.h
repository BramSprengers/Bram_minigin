#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Singleton.h"

namespace dae
{
	class GameObject;

	enum class Event
	{
		TOOK_DAMAGE,
		POINT_INCREASE,
		IS_DEAD
	};

	class Observer
	{
	public:
		virtual ~Observer() = default;
		virtual void OnNotify(GameObject* ob, const Event& event) = 0;
	};

	class GamePlay : public Observer
	{
	public:
		GamePlay(GameObject* ob) : m_UI{ ob } {}

		void OnNotify(GameObject* ob, const Event& event) override;
	private:
		GameObject* m_UI;
	};
}

