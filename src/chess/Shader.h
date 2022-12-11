#pragma once

#include <chess/assert.h>
#include <glad/glad.h>
#include <string>
#include <cstdio>
#include <cstdint>
#include <fstream>
#include <utility>

namespace chess {

	namespace shaders {

		const std::pair<std::string, std::string> LoadCode(const std::string& filePath);

	}

	enum class ShaderType
	{
		Invalid = 0,
		Vertex = GL_VERTEX_SHADER,
		Fragment = GL_FRAGMENT_SHADER
	};

	class Shader
	{
	public:
		Shader() = default;
		~Shader();

		chess::ShaderType GetType() const;
		uint32_t GetIdentifier() const;

		void Generate(chess::ShaderType type);
		void SetCode(const std::string& code);
		void Delete();
	private:
		chess::ShaderType m_Type = chess::ShaderType::Invalid;
		uint32_t m_Identifier = 0;
		std::string m_Code = "";
	};

	class Program
	{
	public:
		Program() = default;

		uint32_t GetIdentifier() const;

		uint32_t Generate();
		void AttachShader(const chess::Shader& shader);
		void Link() const;
		void Bind() const;
	private:
		uint32_t m_Identifier = 0;
		chess::Shader m_VertexShader;
		chess::Shader m_FragmentShader;
	};

}