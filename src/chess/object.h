// Chess
#include <chess/vector.h>
#include <chess/util.h>

// SDL
#include <sdl3/sdl.h>

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

	private:
		SDL_FRect m_Rect;
	};

	struct Texture
	{
		SDL_Texture* thisTexture;
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
		SDL_Surface* m_Image;
		SDL_FRect m_Rect;
	};

	class Text
	{
	public:
		Text() = default;
	};

	Texture CreateTexture(const std::string& path, SDL_Renderer* renderer);

}