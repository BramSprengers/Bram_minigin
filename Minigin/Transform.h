#pragma once
#include <glm.hpp>

namespace dae
{
	class Transform final
	{
	public:
		const glm::vec3& GetWorldPosition() const { return m_worldPosition; }
		const glm::vec3& GetLocalPosition() const { return m_worldPosition; }
		void SetWorldPosition(float x, float y, float z);
		void SetLocalposition(float x, float y, float z);
	private:
		glm::vec3 m_worldPosition;
		glm::vec3 m_localPosition;
	};
}
