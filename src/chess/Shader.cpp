#include "Shader.h"

namespace chess {

	namespace shaders {

		const std::pair<std::string, std::string> LoadCode(const std::string& filePath)
		{
			std::pair<std::string, std::string> codes("", "");
			std::ifstream handle(filePath, std::ios::in);

			if (!CHESS_ASSERT(handle.is_open()))
				return codes;

			std::string line = "";
			chess::ShaderType currentShader = ShaderType::Invalid;

			while (std::getline(handle, line))
			{
				if (line == "$$type vertex")
					currentShader = ShaderType::Vertex;
				else if (line == "$$type fragment")
					currentShader = ShaderType::Fragment;
				else
					switch (currentShader)
					{
						case chess::ShaderType::Vertex:
							codes.first += line + "\n";
							break;

						case chess::ShaderType::Fragment:
							codes.second += line + "\n";
							break;
					}
			}

			handle.close();

			return codes;
		}

	}

	Shader::~Shader()
	{
		Delete();
	}

	chess::ShaderType Shader::GetType() const
	{
		return m_Type;
	}

	uint32_t Shader::GetIdentifier() const
	{
		return m_Identifier;
	}

	void Shader::Generate(chess::ShaderType type)
	{
		m_Type = type;
		m_Identifier = CHESS_CHECK_ERROR(glCreateShader((GLenum)type));
	}

	void Shader::SetCode(const std::string& code)
	{
		m_Code = code;

		const char* cCode = code.c_str();
		CHESS_CHECK_ERROR(glShaderSource(m_Identifier, 1, &cCode, nullptr));
		CHESS_CHECK_ERROR(glCompileShader(m_Identifier));

		int32_t success = 0;
		CHESS_CHECK_ERROR(glGetShaderiv(m_Identifier, GL_COMPILE_STATUS, &success));

		if (!success)
		{
			int32_t msgLength = 0;
			CHESS_CHECK_ERROR(glGetShaderiv(m_Identifier, GL_INFO_LOG_LENGTH, &msgLength));
			char* infoLog = (char*)_malloca(sizeof(char) * msgLength);
			CHESS_CHECK_ERROR(glGetShaderInfoLog(m_Identifier, msgLength, &msgLength, infoLog));

			if (m_Type == chess::ShaderType::Vertex)
				printf("Vertex shader fail: %s\n", infoLog);
			else
				printf("Fragment shader fail: %s\n", infoLog);
		}
	}

	void Shader::Delete()
	{
		CHESS_CHECK_ERROR(glDeleteShader(m_Identifier));
	}

	uint32_t Program::GetIdentifier() const
	{
		return m_Identifier;
	}

	uint32_t Program::Generate()
	{
		m_Identifier = glCreateProgram();

		return GetIdentifier();
	}

	void Program::AttachShader(const chess::Shader& shader)
	{
		if (shader.GetType() == chess::ShaderType::Vertex)
			m_VertexShader = shader;
		else
			m_FragmentShader = shader;

		CHESS_CHECK_ERROR(glAttachShader(m_Identifier, shader.GetIdentifier()));
	}

	void Program::Link() const
	{
		CHESS_CHECK_ERROR(glLinkProgram(m_Identifier));
	}

	void Program::Bind() const
	{
		CHESS_CHECK_ERROR(glUseProgram(m_Identifier));
	}

}
