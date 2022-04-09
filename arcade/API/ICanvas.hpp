#pragma once

#include <string>
#include <vector>
#include "Math.hpp"

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
         * Values are made using ABGR standard format
         * @see https://en.wikipedia.org/wiki/ABGR_color_space
         *
         * Please avoid using other colors because of terminal applications
         * limitations or provide clamp of the color For example in ncurses
         * 0xFC000A should be transformed to 0xFF0000 but it should keep it's
         * original values in DisplayModules (Engines) that has full (A)RGB
         * support
         */
        enum Color
        {
            BLACK   = 0xFF000000,
            BLUE    = 0xFFFF0000,
            GREEN   = 0xFF00FF00,
            RED     = 0xFF0000FF,
            CYAN    = 0xFFFFFF00,
            MAGENTA = 0xFFFF00FF,
            YELLOW  = 0xFF00FFFF,
            WHITE   = 0xFFFFFFFF
        };

        /**
         * @brief Implementation of informations about Texts
         * It contains the string the position and the color of the text
         *
         */
        struct TextInfo
        {
            std::string text;
            math::Vector2 pos;
            Color color;
        };
    } // namespace utils

    class ISubWindow
    {
    public:
        /**
         * @brief Set the Pixel object
         *
         * @param pos The position of the pixel
         * @param color The color of the pixel
         *
         */
        virtual void setPixel(const api::math::Vector2 &pos,
                      const api::utils::Color color) = 0;
        /**
         * @brief Draw text on the canvas
         *
         * @param pos The position of the pixel
         * @param text The text to draw
         * @param color The color of the text
         *
         */
        virtual void drawText(const api::math::Vector2 &pos, const std::string &text,
                      const api::utils::Color color) = 0;

        /**
         * @brief Draws the Rect object
         *
         * @param rect The rectangle to draw
         * @param color The color of the rectangle
         *
         */
        virtual void drawRect(const api::math::Rectangle &rect,
                      const api::utils::Color color) = 0;
        /**
         * @brief Get the Surface object
         *
         * @return const Rectangle& The surface of the canvas
         *
         */
        virtual const api::math::Rectangle &getSurface() const = 0;

        /**
         * @brief Clears the canvas
         *
         */
        virtual void clear() = 0;

        /**
         * @brief Get pixels
         * @return The pixel pointer
         *
         */
        virtual const uint8_t *getPixels() const = 0;

        /**
         * @brief Get the text Info drawn to the canvas
         *
         * @param window The window to draw on
         *
         * @return std::vector<TextInfo>& Reference to the text info array
         *
         */
        virtual const std::vector<api::utils::TextInfo>& getTextInfo() const = 0;

        /**
         * @brief MakeBox (Draws a box around the given window)
         *
         * @param window The window
         *
         */
        virtual void makeBox() = 0;

        /**
         * @brief Destroy the ISubWindow object
         *
         */
        virtual ~ISubWindow() = default;

        /**
         * @brief Construct ISubWindow Object
         *
         */
        ISubWindow() = default;
    };

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
         * @param window The window to draw on
         *
         */
        virtual void setPixel(unsigned int window,
                              const math::Vector2 &pos,
                              const utils::Color color) = 0;

        /**
         * @brief Draw text on the canvas
         *
         * @param pos The position of the pixel
         * @param text The text to draw
         * @param color The color of the text
         * @param window The window to draw on
         *
         */
        virtual void drawText(unsigned int window,
                              const math::Vector2 &pos,
                              const std::string &text,
                              const utils::Color color) = 0;

        /**
         * @brief Get the text Info drawn to the canvas
         *
         * @param window The window to draw on
         *
         * @return std::vector<TextInfo>& Reference to the text info array
         *
         */
        virtual const std::vector<utils::TextInfo>& getTextInfo(unsigned int window) const = 0;

        /**
         * @brief Draws the Rect object
         *
         * @param window The window to draw on
         * @param rect The rectangle to draw
         * @param color The color of the rectangle
         *
         */
        virtual void drawRect(unsigned int window,
                              const math::Rectangle &rect,
                              const utils::Color color) = 0;

        /**
         * @brief Get the Surface object
         *
         * @param window The window to draw on
         *
         * @return const Rectangle& The surface of the canvas
         *
         */
        virtual const math::Rectangle &getSurface(unsigned int window) const = 0;

        /**
         * @brief Clears the canvas
         * @param window The window to draw on
         *
         */
        virtual void clear(unsigned int window) = 0;

        /**
         * @brief Get pixels
         * @param window The window to draw on
         * @return The pixel pointer
         *
         */
        virtual const uint8_t *getPixels(unsigned int window) const = 0;

        /**
         * @brief Get the number of windows
         *
         */
        virtual const unsigned int getWindowCount() const = 0;

        /**
         * @brief Add subwindow
         * @param x offset of the window
         * @param y offset of the window
         * @param w Width of the current window
         * @param h height of the current window
         *
         */
        virtual void addSubWindow(int x, int y, unsigned int w, unsigned int h) = 0;

        /**
         * @brief Destroy subWindows
         * It never destroy the full window
         *
         */
        virtual void destroySubWindows() = 0;

        /**
         * @brief MakeBox (Draws a box around the given window)
         *
         * @param window The window
         *
         */
        virtual void makeBox(unsigned int window) = 0;

        /**
         * @brief Destroy the ICanvas object
         *
         */
        virtual ~ICanvas() = default;
    };
} // namespace arcade::api
