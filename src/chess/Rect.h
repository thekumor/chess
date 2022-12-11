#pragma once

#include <chess/Entity.h>
#include <chess/buffer.h>
#include <chess/renderer.h>
#include <chess/utility.h>
#include <glm/ext.hpp>

namespace chess {

	class Rect : public virtual chess::Entity
	{
	public:
		Rect(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		Rect();

		void SetPosition(const glm::vec2& position);
		void SetSize(const glm::vec2& size);
		void SetColor(const glm::uvec4& color);
		void Draw();
	private:
		chess::VertexBuffer m_VertexBuffer;
		chess::IndexBuffer m_IndexBuffer;
		glm::vec2 m_Position = { 0.0f, 0.0f };
		glm::vec2 m_Size = { 0.01f , 0.01f };
		glm::vec4 m_Color = { 1.0f, 1.0f, 1.0f, 1.0f };
	};

}