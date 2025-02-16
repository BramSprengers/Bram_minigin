#pragma once
#include <memory>
#include "Transform.h"

namespace dae
{
	class Texture2D;
	class TextObject;

	// todo: this should become final.
	class GameObject final
	{
	public:
		virtual void Update();
		virtual void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		void SetText(std::shared_ptr<TextObject> text);

		glm::vec3 GetPosition() const { return m_transform.GetPosition(); };

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_transform{};

		std::shared_ptr<Texture2D> m_texture{};
		std::shared_ptr<TextObject> m_text{};
	};
}
