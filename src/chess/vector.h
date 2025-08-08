#pragma once

#include <cstdint>

#define Vec2 chess::Vector2<std::int32_t>
#define Vec3 chess::Vector3<std::int32_t>
#define Vec4 chess::Vector4<std::int32_t>

#define Color chess::Vector4<std::int32_t>
#define ObjectPos chess::Vector2<float>
#define ObjectSize chess::Vector2<float>

namespace chess
{

	template <typename T>
	struct Vector2
	{
		Vector2(T x, T y) :
			X(x), Y(y)
		{
		}
		Vector2(const Vector2<T>& other)
		{
			x = other.x;
			y = other.y;
		}
		Vector2(T val) :
			X(val), Y(val)
		{
		}
		Vector2() :
			X(0), Y(0)
		{
		}

		[[nodiscard]] Vector2 operator+(const Vector2& other) const
		{
			return Vector2(x + other.x, y + other.y);
		}
		[[nodiscard]] Vector2 operator-(const Vector2& other) const
		{
			return Vector2(x - other.x, y - other.y);
		}
		[[nodiscard]] Vector2 operator*(const Vector2& other) const
		{
			return Vector2(x * other.x, y * other.y);
		}
		[[nodiscard]] Vector2 operator/(const Vector2& other) const
		{
			return Vector2(x / other.x, y / other.y);
		}

		union
		{
			T x, X;
		};
		union
		{
			T y, Y;
		};
	};

	template <typename T>
	struct Vector3
	{
		Vector3(T x, T y, T z) :
			X(x), Y(y), Z(z)
		{
		}
		Vector3(const Vector3<T>& other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
		}
		Vector3(T val) :
			X(val), Y(val), Z(val)
		{
		}
		Vector3() :
			X(0), Y(0), Z(0)
		{
		}

		[[nodiscard]] Vector3 operator+(const Vector3& other) const
		{
			return Vector3(x + other.x, y + other.y, z + other.z);
		}
		[[nodiscard]] Vector3 operator-(const Vector3& other) const
		{
			return Vector3(x - other.x, y - other.y, z - other.z);
		}
		[[nodiscard]] Vector3 operator*(const Vector3& other) const
		{
			return Vector3(x * other.x, y * other.y, z * other.z);
		}
		[[nodiscard]] Vector3 operator/(const Vector3& other) const
		{
			return Vector3(x / other.x, y / other.y, z / other.z);
		}

		union
		{
			T x, X, r;
		};
		union
		{
			T y, Y, g;
		};
		union
		{
			T z, Z, b;
		};
	};

	template <typename T>
	struct Vector4
	{
		Vector4(T x, T y, T z, T w) :
			X(x), Y(y), Z(z), W(w)
		{
		}
		Vector4(const Vector4<T>& other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
			w = other.w;
		}
		Vector4(T val) :
			X(val), Y(val), Z(val), W(val)
		{
		}
		Vector4() :
			X(0), Y(0), Z(0), W(0)
		{
		}

		[[nodiscard]] Vector4 operator+(const Vector4& other) const
		{
			return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
		}
		[[nodiscard]] Vector4 operator-(const Vector4& other) const
		{
			return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
		}
		[[nodiscard]] Vector4 operator*(const Vector4& other) const
		{
			return Vector4(x * other.x, y * other.y, z * other.z, w * other.w);
		}
		[[nodiscard]] Vector4 operator/(const Vector4& other) const
		{
			return Vector4(x / other.x, y / other.y, z / other.z, w / other.w);
		}

		union
		{
			T x, X, r;
		};
		union
		{
			T y, Y, g;
		};
		union
		{
			T z, Z, b;
		};
		union
		{
			T w, W, a;
		};
	};

}