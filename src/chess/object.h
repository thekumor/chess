// Chess
#include <chess/vector.h>
#include <chess/util.h>

// SDL
#include <sdl3/sdl.h>

// Other
#include "../vendor/stb_image.h"

// STL
#include <string>

namespace chess
{

	class Object
	{
	public:
		Object() = default;

		void SetColor(const Color& color);

	protected:
		SDL_FRect m_Rect;
		Vector2<float> m_Position, m_Size;
		Color m_Color;
	};

	class Rectangle : public Object
	{
	public:
		Rectangle(const Vector2<float>& position, const Vector2<float>& size, const Color& color);
		Rectangle() = default;

		void Draw(SDL_Renderer* renderer);
		void SetSize(const Vector2<float>& size);
		void SetPosition(const Vector2<float>& position);
	};

	struct Texture
	{
		Texture(const std::string& path, SDL_Renderer* renderer);
		Texture() = default;
		SDL_Texture* ThisTexture;
		std::string Path;
	};

	class Sprite : public Object
	{
	public:
		Sprite(const Vector2<float>& position, const Vector2<float>& size, const Color& color, Texture* texture);
		Sprite() = default;

		void Draw(SDL_Renderer* renderer);
		void SetSize(const Vector2<float>& size);
		void SetPosition(const Vector2<float>& position);
		void SetTexture(Texture* texture);

	private:
		Texture* m_Texture;
	};

	class Text
	{
	public:
		Text() = default;
	};

}