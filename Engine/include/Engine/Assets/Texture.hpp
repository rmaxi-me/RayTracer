/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <raylib.h>
#include "Image.hpp"

namespace raylib {
    class Texture {
    protected:
        // Texture2D and TextureCubemap are the same.
        ::Texture m_raylibTexture;
    public:
        explicit Texture(::Texture texture);
        explicit Texture(const char *filename);
        explicit Texture(const Image &image);

        ~Texture();

        // Can't copy a GPU loaded texture
        Texture(const Texture &) = delete;
        Texture &operator=(const Texture &) = delete;

        [[nodiscard]] inline static Texture loadTextureCubemap(const Image &image, int layoutType)
        {
            return Texture(LoadTextureCubemap(image.getRaylibImage(), layoutType));
        }

        inline void update(const void *pixels)
        {
            UpdateTexture(m_raylibTexture, pixels);
        }

        inline Image getData()
        {
            return Image(GetTextureData(m_raylibTexture));
        }

        inline static Image getScreenData()
        {
            return Image(GetScreenData());
        }

        inline void genMipmaps()
        {
            GenTextureMipmaps(&m_raylibTexture);
        }

        inline void setFilter(TextureFilterMode filterMode)
        {
            SetTextureFilter(m_raylibTexture, filterMode);
        }

        inline void setFilter(TextureWrapMode wrapMode)
        {
            SetTextureWrap(m_raylibTexture, wrapMode);
        }

        inline void draw(int posX, int posY, Color tint)
        {
            DrawTexture(m_raylibTexture, posX, posY, tint);
        }

        inline void draw(Vector2 position, Color tint)
        {
            DrawTextureV(m_raylibTexture, position, tint);
        }

        inline void draw(Vector2 position, float rotation, float scale, Color tint)
        {
            DrawTextureEx(m_raylibTexture, position, rotation, scale, tint);
        }

        inline void draw(Rectangle sourceRec, Vector2 position, Color tint)
        {
            DrawTextureRec(m_raylibTexture, sourceRec, position, tint);
        }

        inline void draw(Vector2 tiling, Vector2 offset, Rectangle quad, Color tint)
        {
            DrawTextureQuad(m_raylibTexture, tiling, offset, quad, tint);
        }

        inline void draw(Rectangle sourceRec, Rectangle destRec, Vector2 origin, float rotation, Color tint)
        {
            DrawTexturePro(m_raylibTexture, sourceRec, destRec, origin, rotation, tint);
        }

        inline void draw(NPatchInfo nPatchInfo, Rectangle destRec, Vector2 origin, float rotation, Color tint)
        {
            DrawTextureNPatch(m_raylibTexture, nPatchInfo, destRec, origin, rotation, tint);
        }

        [[nodiscard]] inline const Texture2D &getRaylibTexture() const
        {
            return m_raylibTexture;
        }
    };

    class RenderTexture {
    protected:
        ::RenderTexture m_raylibRenderTexture;
    public:
        RenderTexture(int width, int height);
        ~RenderTexture();
    };
}
