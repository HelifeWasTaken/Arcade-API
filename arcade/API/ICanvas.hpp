#pragma once

#include <string>

namespace arcade::api
{
    namespace math
    {
        /**
         * @brief Forward declaration of Vector2
         *
         */
        class Vector2;

        /**
         * @brief Forward declaration of Rectangle
         *
         */
        class Rectangle;
    } // namespace math

    namespace utils
    {
        /**
         * @brief API Implementation of Colors
         * Thoses values are the standardised RGB values
         * For libraries like ncurses you will need to store the
         * attron values like if possible
         *
         *    R   G  B
         * 0xFF  FF FF
         *
         * Please avoid using other colors because of terminal applications
         * limitations or provide clamp of the color For example in ncurses
         * 0xFC000A should be transformed to 0xFF0000 but it should keep it's
         * original values in DisplayModules (Engines) that has full (A)RGB
         * support
         */
        enum Color
        {
            BLACK   = 0x000000,
            BLUE    = 0x0000FF,
            GREEN   = 0x00FF00,
            RED     = 0xFF0000,
            CYAN    = 0x00FFFF,
            MAGENTA = 0xFF00FF,
            YELLOW  = 0xFFFF00,
            WHITE   = 0xFFFFFF
        };
    } // namespace utils

    /**
     * @brief API Implementation of ICanvas
     * The canvas is the representation of the abstracted display
     *
     */
    class ICanvas
    {
      public:
        /**
         * @brief Set the Pixel object
         *
         * @param pos The position of the pixel
         * @param color The color of the pixel
         *
         */
        virtual void setPixel(const math::Vector2 &pos,
                              const utils::Color color) = 0;

        /**
         * @brief Draw text on the canvas
         *
         * @param pos The position of the pixel
         * @param text The text to draw
         * @param color The color of the text
         *
         */
        virtual void drawText(const math::Vector2 &pos,
                              const std::string &text,
                              const utils::Color color) = 0;

        /**
         * @brief Get the Width object
         *
         * @param rect The rectangle to draw
         * @param color The color of the rectangle
         *
         */
        virtual void drawRect(const math::Rectangle &rect,
                              const utils::Color color) = 0;

        /**
         * @brief Get the Size object
         *
         * @return const Vector2& The size of the canvas
         *
         */
        virtual const math::Vector2 &getSize() const = 0;

        /**
         * @brief Clears the canvas
         *
         */
        virtual void clear() = 0;

        /**
         * @brief Destroy the ICanvas object
         *
         */
        virtual ~ICanvas() = default;
    };
} // namespace arcade::api
