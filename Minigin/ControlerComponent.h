#pragma once
#include "BaseComponent.h"
#include <Xinput.h>

namespace dae
{
	class GameObject;
	class ControlerComponent : public BaseComponent
	{
		ControlerComponent(GameObject* pOwner) : BaseComponent(pOwner) {};
		virtual ~ControlerComponent() {};

		ControlerComponent(const			ControlerComponent& other) = delete;
		ControlerComponent(					ControlerComponent&& other) = delete;
		ControlerComponent& operator=(const	ControlerComponent& other) = delete;
		ControlerComponent& operator=(		ControlerComponent&& other) = delete;

		virtual void Update(float deltaTime);


	};
}

