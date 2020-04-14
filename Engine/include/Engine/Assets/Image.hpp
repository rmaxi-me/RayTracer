/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <raylib.h>

namespace raylib {
    class Image {
    protected:
        ::Image m_rayImage;
    public:
        /*
         * ctor, dtor, canonical form
         */

        explicit Image(::Image raylibImage);
        explicit Image(const char *filename);
        Image(Color *pixels, int width, int height);
        Image(const char *filename, int width, int height, PixelFormat format, int headerSize);

        ~Image();

        Image(const Image &copy);
        Image &operator=(const Image &copy);

        /*
         *  IMAGE LOADING FUNCTIONS
         */

        inline void exportImage(const char *filename) const
        {
            ExportImage(m_rayImage, filename);
        }

        inline void exportAsCode(const char *filename) const
        {
            ExportImageAsCode(m_rayImage, filename);
        }

        [[nodiscard]] inline Color *getImageData() const
        {
            return GetImageData(m_rayImage);
        }

        [[nodiscard]] inline ::Vector4 *getImageDataNormalized() const
        {
            return GetImageDataNormalized(m_rayImage);
        }

        /*
         * IMAGE GENERATION FUNCTIONS
         */

        static Image GenImageColor(int width, int height, Color color);
        static Image GenImageGradientV(int width, int height, Color top, Color bottom);
        static Image GenImageGradientH(int width, int height, Color left, Color right);
        static Image GenImageGradientRadial(int width, int height, float density, Color inner, Color outer);
        static Image GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2);
        static Image GenImageWhiteNoise(int width, int height, float factor);
        static Image GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale);
        static Image GenImageCellular(int width, int height, int tileSize);

        /*
         * IMAGE MANIPULATION FUNCTIONS
         */

        [[nodiscard]] inline Image FromImage(Rectangle rec) const
        {
            return Image(::ImageFromImage(m_rayImage, rec));
        }

        [[nodiscard]] inline static Image FromText(const char *text, int fontSize, Color color)
        {
            return Image(ImageText(text, fontSize, color));
        }

        [[nodiscard]] inline static Image FromText(::Font font, const char *text, float fontSize, float spacing, Color tint)
        {
            return Image(ImageTextEx(font, text, fontSize, spacing, tint));
        }

        inline void toPOT(Color fillColor)
        {
            ImageToPOT(&m_rayImage, fillColor);
        }

        inline void format(PixelFormat newFormat)
        {
            ImageFormat(&m_rayImage, newFormat);
        }

        inline void alphaMask(const Image &alphaMask)
        {
            ImageAlphaMask(&m_rayImage, alphaMask.m_rayImage);
        }

        inline void alphaClear(Color color, float threshold)
        {
            ImageAlphaClear(&m_rayImage, color, threshold);
        }

        inline void alphaCrop(float threshold)
        {
            ImageAlphaCrop(&m_rayImage, threshold);
        }

        inline void alphaPremultiply()
        {
            ImageAlphaPremultiply(&m_rayImage);
        }

        inline void crop(Rectangle crop)
        {
            ImageCrop(&m_rayImage, crop);
        }

        inline void resize(int newWidth, int newHeight)
        {
            ImageResize(&m_rayImage, newWidth, newHeight);
        }

        inline void resizeNN(int newWidth, int newHeight)
        {
            ImageResizeNN(&m_rayImage, newWidth, newHeight);
        }

        inline void resizeCanvas(int newWidth, int newHeight, int offsetX, int offsetY, Color color)
        {
            ImageResizeCanvas(&m_rayImage, newWidth, newHeight, offsetX, offsetY, color);
        }

        inline void mipmaps()
        {
            ImageMipmaps(&m_rayImage);
        }

        inline void dither(int rBpp, int gBpp, int bBpp, int aBpp)
        {
            ImageDither(&m_rayImage, rBpp, gBpp, bBpp, aBpp);
        }

        inline void flipVertical()
        {
            ImageFlipVertical(&m_rayImage);
        }

        inline void flipHorizontal()
        {
            ImageFlipHorizontal(&m_rayImage);
        }

        inline void rotateCW()
        {
            ImageRotateCW(&m_rayImage);
        }

        inline void rotateCCW()
        {
            ImageRotateCCW(&m_rayImage);
        }

        inline void colorTint(Color color)
        {
            ImageColorTint(&m_rayImage, color);
        }

        inline void colorInvert()
        {
            ImageColorInvert(&m_rayImage);
        }

        inline void colorGrayscale()
        {
            ImageColorGrayscale(&m_rayImage);
        }

        inline void colorContrast(float contrast)
        {
            ImageColorContrast(&m_rayImage, contrast);
        }

        inline void colorBrightness(int brightness)
        {
            ImageColorBrightness(&m_rayImage, brightness);
        }

        inline void colorReplace(Color color, Color replace)
        {
            ImageColorReplace(&m_rayImage, color, replace);
        }

        // Memory needs to be freed
        [[nodiscard]] Color *extractPalette(int maxPaletteSize, int &extractCount);

        inline Rectangle getAlphaBorder(float threshold)
        {
            return GetImageAlphaBorder(m_rayImage, threshold);
        }

        /*
         * GETTERS AND SETTERS
         */

        [[nodiscard]] inline ::Image getRaylibImage() const noexcept
        {
            return m_rayImage;
        }

        inline static int getPixelDataSize(int width, int height, PixelFormat pixelFormat)
        {
            return GetPixelDataSize(width, height, pixelFormat);
        }
    };
}
