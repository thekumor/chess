#include "create.h"

namespace chess {

    namespace create {

        Program NewProgram(const std::string& filePath)
		{
			Shader vertex, fragment;
			vertex.Generate(chess::ShaderType::Vertex);
			fragment.Generate(chess::ShaderType::Fragment);

			std::pair<std::string, std::string> codes = chess::shaders::LoadCode(filePath);
			vertex.SetCode(codes.first);
			fragment.SetCode(codes.second);

			chess::Program prog;
			prog.Generate();
			prog.AttachShader(vertex);
			prog.AttachShader(fragment);
			prog.Link();

			vertex.Delete();
			fragment.Delete();

			return prog;
        }

    }

}