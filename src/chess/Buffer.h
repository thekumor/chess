#pragma once

#include <chess/assert.h>
#include <glad/glad.h>
#include <glm/vec4.hpp>
#include <vector>
#include <cstdint>

namespace chess {

	class BufferBase
	{
	public:
		BufferBase() = default;

		virtual void Data(void* data, size_t size) = 0;
		virtual void Bind() const = 0;

		uint32_t GetIdentifier() const;
		uint32_t Generate();
	protected:
		size_t m_Size = 0;
		uint32_t m_Identifier = 0;
	};

	class VertexBuffer : public chess::BufferBase
	{
	public:
		VertexBuffer(void* data, size_t size);
		VertexBuffer() = default;

		void Data(void* data, size_t size);
		void Bind() const;
	private:
		std::vector<float> m_Data = {};
	};

	class IndexBuffer : public chess::BufferBase
	{
	public:
		IndexBuffer(void* data, size_t size);
		IndexBuffer() = default;

		void Data(void* data, size_t size);
		void Bind() const;
	private:
		std::vector<uint32_t> m_Data = {};
	};

}