#pragma once
#include "BaseComponent.h"
#include <vector>

namespace dae
{
	enum TrashType
	{
		intTrashing,
		GOWithPointer,
		GOWithoutPointer
	};

	struct T
	{
		float matrix[16] = {
			1,0,0,0,
			0,1,0,0,
			0,0,1,0,
			0,0,0,1 };
	};

	class GameObject3DWithP
	{
	public:
		dae::T* transform;
		int ID;
	};

	class GameObject3DNoP
	{
	public:
		dae::T transform;
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

		std::vector<float> Trashing(unsigned int times, TrashType type) const;
		
		int OBWTrashing(int stepsize) const;
		int OBNTrashing(int stepsize) const;
		int IntTrashing(int stepsize) const;
	};
}

