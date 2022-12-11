#pragma once

#include <chess/assert.h>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/vec4.hpp>

namespace chess {

	namespace renderer {

		bool InitializeGLAD();
		bool Initialize();
		void Clear(const glm::vec4& color = { 0.0f, 0.0f, 0.0f, 1.0f });
		void DrawTriangle();
		void DrawElements();

	}

}