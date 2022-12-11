#include "utility.h"

namespace chess {

    glm::vec2 Normalize(const glm::vec2& vec)
    {
        glm::vec2 newVec;

        newVec.x = (vec.x) / (1000.0f);
        newVec.y = (vec.y) / (720.0f);

        return newVec;
    }

	glm::vec4 NormalizeColor(const glm::uvec4& color)
	{
		glm::vec4 newVec;

		newVec.r = (float)(color.r) / (255.f);
		newVec.g = (float)(color.g) / (255.f);
		newVec.b = (float)(color.b) / (255.f);
		newVec.a = (float)(color.a) / (255.f);

		return newVec;
	}

}