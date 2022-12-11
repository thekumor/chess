#include "Buffer.h"

namespace chess {

	VertexBuffer::VertexBuffer(void* data, size_t size)
	{
		Generate();
		Data(data, size);
	}

	void VertexBuffer::Data(void* data, size_t size)
	{
		if (m_Identifier == 0)
			Generate();

		Bind();
		CHESS_CHECK_ERROR(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
		//CHESS_CHECK_ERROR(glBindBuffer(GL_ARRAY_BUFFER, 0)); // unbinds

		m_Size = size;

		float* point = (float*)data;

		for (uint32_t i = 0; i < size / sizeof(float); i++)
		{
			m_Data.push_back(*point);
			point++;
		}
	}

	void VertexBuffer::Bind() const
	{
		CHESS_CHECK_ERROR(glBindBuffer(GL_ARRAY_BUFFER, m_Identifier));
	}

	uint32_t BufferBase::GetIdentifier() const
	{
		return m_Identifier;
	}

	uint32_t BufferBase::Generate()
	{
		CHESS_CHECK_ERROR(glGenBuffers(1, &m_Identifier));

		return GetIdentifier();
	}

	IndexBuffer::IndexBuffer(void* data, size_t size)
	{
		Generate();
		Data(data, size);
	}

	void IndexBuffer::Data(void* data, size_t size)
	{
		if (m_Identifier == 0)
			Generate();

		Bind();
		CHESS_CHECK_ERROR(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
		//CHESS_CHECK_ERROR(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0)); // unbinds

		m_Size = size;

		uint32_t* point = (uint32_t*)data;

		for (uint32_t i = 0; i < size / sizeof(uint32_t); i++)
		{
			m_Data.push_back(*point);
			point++;
		}
	}

	void IndexBuffer::Bind() const
	{
		CHESS_CHECK_ERROR(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Identifier));
	}

}