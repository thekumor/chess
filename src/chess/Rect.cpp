#include "Rect.h"

namespace chess {

	Rect::Rect(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
		: Rect()
	{
		SetPosition(position);
		SetSize(size);
		SetColor(color);
	}

	Rect::Rect()
	{
		uint32_t data[] = {
			0, 1, 2,
			3, 2, 0
		};

		m_IndexBuffer.Data(data, sizeof(data));
	}

	void Rect::SetPosition(const glm::vec2& position)
	{
		m_Position = chess::Normalize(position);

		float data[] = {
			m_Position.x, m_Position.y, m_Color.r, m_Color.g, m_Color.b, m_Color.a,
			m_Position.x + m_Size.x, m_Position.y, m_Color.r, m_Color.g, m_Color.b, m_Color.a,
			m_Position.x + m_Size.x, m_Position.y + m_Size.y, m_Color.r, m_Color.g, m_Color.b, m_Color.a,
			m_Position.x, m_Position.y + m_Size.y, m_Color.r, m_Color.g, m_Color.b, m_Color.a,
		};

		m_VertexBuffer.Data(data, sizeof(data));
	}

	void Rect::SetSize(const glm::vec2& size)
	{
		m_Size = chess::Normalize(size);

		float data[] = {
			m_Position.x, m_Position.y, m_Color.r, m_Color.g, m_Color.b, m_Color.a,
			m_Position.x + m_Size.x, m_Position.y, m_Color.r, m_Color.g, m_Color.b, m_Color.a,
			m_Position.x + m_Size.x, m_Position.y + m_Size.y, m_Color.r, m_Color.g, m_Color.b, m_Color.a,
			m_Position.x, m_Position.y + m_Size.y, m_Color.r, m_Color.g, m_Color.b, m_Color.a,
		};

		m_VertexBuffer.Data(data, sizeof(data));
	}

	void Rect::SetColor(const glm::uvec4& color)
	{
		m_Color = chess::NormalizeColor(color);

		float data[] = {
			m_Position.x, m_Position.y, m_Color.r, m_Color.g, m_Color.b, m_Color.a,
			m_Position.x + m_Size.x, m_Position.y, m_Color.r, m_Color.g, m_Color.b, m_Color.a,
			m_Position.x + m_Size.x, m_Position.y + m_Size.y, m_Color.r, m_Color.g, m_Color.b, m_Color.a,
			m_Position.x, m_Position.y + m_Size.y, m_Color.r, m_Color.g, m_Color.b, m_Color.a,
		};

		m_VertexBuffer.Data(data, sizeof(data));
	}

	void Rect::Draw()
	{
		m_VertexBuffer.Bind();
		renderer::DrawElements();
	}

}