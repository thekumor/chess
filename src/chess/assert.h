#pragma once

#include <glad/glad.h>
#include <cstdint>
#include <cstdio>
#include <string>

#ifdef _DEBUG
#define CHESS_ASSERT(x) [&](){ auto value = x; if (!value){ printf("Assertion fail!\nFunction:%s\n%s:%d\n\n", __FUNCTION__, __FILE__, __LINE__); } return value; }()
#define CHESS_CHECK_ERROR(x) x; while(uint32_t error = glGetError()){ printf("(%s:%d) - OpenGL error code: %u\n", __FILE__, __LINE__, error); }
#else
#define CHESS_ASSERT(x) x
#define CHESS_CHECK_ERROR(x) x
#endif