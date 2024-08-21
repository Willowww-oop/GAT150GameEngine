#include "Texture.h"
#include "../Math/VectorTwo.h"
#include "Renderer.h"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "../Core/EAssert.h"

bool Texture::Load(const std::string& filename, Renderer& renderer)
{
    // load image onto surface
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if (surface == nullptr)
    {
        std::cerr << "Could not load image: " << filename << std::endl;
        return false;
    }

    // create texture from surface, texture is a friend class of renderer
    m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
    // once texture is created, surface can be freed up
    SDL_FreeSurface(surface);
    if (m_texture == nullptr)
    {
        std::cerr << "Could not create texture: " << filename << std::endl;
        return false;
    }

    return true;
}

VectorTwo Texture::GetSize()
{
    ASSERT(m_texture != nullptr);

    // query the texture for the size
    // https://wiki.libsdl.org/SDL2/SDL_QueryTexture
    SDL_Point size;
    SDL_QueryTexture(m_texture, NULL, NULL, &size.x, &size.y);

    return VectorTwo(size.x, size.y);
}

bool Texture::Create(std::string name, ...)
{
    va_list args;
    va_start(args, name);
    Renderer renderer = va_arg(args, Renderer);
    va_end(args);

  
    return Load(name, renderer);

}
