#pragma once
#include <string>
#include <memory>
#include "GameObject.h"
#include "Transform.h"
#include "BaseComponent.h"

namespace dae
{
	class Font;
	class Texture2D;
	class TextObject : public BaseComponent
	{
	public:
		void Update(float DeltaTime) override;
		void Render() const;

		void SetText(const std::string& text);

		TextObject(GameObject* ob, const std::string& text, std::shared_ptr<Font> font);
		TextObject(const std::string& text, std::shared_ptr<Font> font);
		~TextObject() = default;
		TextObject(const TextObject& other) = delete;
		TextObject(TextObject&& other) = delete;
		TextObject& operator=(const TextObject& other) = delete;
		TextObject& operator=(TextObject&& other) = delete;
	private:
		bool m_needsUpdate;
		std::string m_text;

		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
	};
}
