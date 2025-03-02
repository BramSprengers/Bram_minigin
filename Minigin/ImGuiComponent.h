#pragma once
#include "BaseComponent.h"
#include <vector>

namespace dae
{
	struct T
	{
		float matrix[16] = {
			1,0,0,0,
			0,1,0,0,
			0,0,1,0,
			0,0,0,1 };
	};

	class GameObject3D
	{
	public:
		dae::T* transform;
		int ID;
	};

	class ImGuiComponent : public BaseComponent
	{
	public:
		ImGuiComponent(GameObject* ob) : dae::BaseComponent(ob) {};
		virtual ~ImGuiComponent() {};

		ImGuiComponent(const			ImGuiComponent& other) = delete;
		ImGuiComponent(					ImGuiComponent&& other) = delete;
		ImGuiComponent& operator=(const	ImGuiComponent& other) = delete;
		ImGuiComponent& operator=(		ImGuiComponent&& other) = delete;

		void Update(float deltaTime);
		void FixedUpdate(float fixedDeltaTime);
		void Render() const;

	private:

		std::vector<float> IntTrashing(int times) const;
		std::vector<float> OBTrashing(int times) const;

	};
}

