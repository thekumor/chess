#include "renderer.h"

namespace chess {

	namespace renderer {

		bool InitializeGLAD()
		{
			return CHESS_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
		}

		bool Initialize()
		{
			bool gladInitialized = InitializeGLAD();

			// Creates a vao
			uint32_t vao = 0;
			CHESS_CHECK_ERROR(glGenVertexArrays(1, &vao));
			CHESS_CHECK_ERROR(glBindVertexArray(vao));

			return gladInitialized;
		}

		void Clear(const glm::vec4& color /*= { 0.0f, 0.0f, 0.0f, 1.0f }*/)
		{
			CHESS_CHECK_ERROR(glClearColor(color.r, color.g, color.b, color.a));
			CHESS_CHECK_ERROR(glClear(GL_COLOR_BUFFER_BIT));
		}

		void DrawTriangle()
		{
			CHESS_CHECK_ERROR(glDrawArrays(GL_TRIANGLES, 0, 3));
		}

		void DrawElements()
		{
			CHESS_CHECK_ERROR(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
		}

	}

}
