#include "object.h"

namespace chess
{

	void Object::SetColor(const Color& color)
	{
		m_Color = color;
	}

	Rectangle::Rectangle(const Vector2<float>& position, const Vector2<float>& size, const Color& color)
	{
		SetPosition(position);
		SetSize(size);
		SetColor(color);
	}

	void Rectangle::SetSize(const Vector2<float>& size)
	{
		m_Size = size;
		m_Rect.w = size.x;
		m_Rect.h = size.y;
	}

	void Rectangle::Draw(SDL_Renderer* renderer)
	{
		SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, m_Color.a);
		SDL_RenderFillRect(renderer, &m_Rect);
	}

	void Rectangle::SetPosition(const Vector2<float>& position)
	{
		m_Position = position;
		m_Rect.x = position.x;
		m_Rect.y = position.y;
	}

	Sprite::Sprite(const Vector2<float>& position, const Vector2<float>& size, const Color& color, Texture* texture)
	{
		SetPosition(position);
		SetSize(size);
		SetColor(color);
		SetTexture(texture);
	}

	void Sprite::Draw(SDL_Renderer* renderer)
	{
		SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, m_Color.a);
		SDL_RenderTexture(renderer, m_Texture->ThisTexture, nullptr, &m_Rect);
	}

	void Sprite::SetSize(const Vector2<float>& size)
	{
		m_Size = size;
		m_Rect.w = size.x;
		m_Rect.h = size.y;
	}

	void Sprite::SetPosition(const Vector2<float>& position)
	{
		m_Position = position;
		m_Rect.x = position.x;
		m_Rect.y = position.y;
	}

	void Sprite::SetTexture(Texture* texture)
	{
		m_Texture = texture;
	}

	Texture::Texture(const std::string& path, SDL_Renderer* renderer)
		: Path(path)
	{
		int x, y, channels;
		stbi_uc* buffer = stbi_load(path.c_str(), &x, &y, &channels, 4);

		SDL_Surface* surface = SDL_CreateSurfaceFrom(x, y, SDL_PIXELFORMAT_RGBA32, buffer, x * 4);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		ThisTexture = texture;
		
		SDL_DestroySurface(surface);
		stbi_image_free(buffer);

	}

}