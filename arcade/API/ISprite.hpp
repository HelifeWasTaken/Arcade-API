#pragma once

namespace arcade::api
{
    /**
     * @brief Forward declaration of arcade::ICanvas
     *
     */
    class ICanvas;

    namespace math
    {
        /**
         * @brief Forward declaration of arcade::Vector2
         *
         */
        class Vector2;
    } // namespace math

    /**
     * @brief API Implementation of the ISprite
     * The sprite should be able to draw itself on the canvas
     *
     */
    class ISprite
    {
      public:
        /**
         * @brief Destroy the ISprite object
         *
         */
        virtual ~ISprite() = default;

        /**
         * @brief Draw the sprite on the canvas
         *
         * @param canvas The canvas to draw on
         */
        virtual void draw(ICanvas &canvas) const = 0;

        /**
         * @brief Get the Size object
         *
         * @return const Vector2& The width of the sprite
         */
        virtual const unsigned int &getScale() const = 0;

        /**
         * @brief Get the Position object
         *
         * @return const Vector2& The position of the sprite
         */
        virtual const math::Vector2 &getPos() const = 0;

        /**
         * @brief Set the Position object
         *
         * @param pos The position of the sprite
         */
        virtual void setPos(const math::Vector2 &pos) = 0;

        /**
         * @brief Set the scale object
         *
         * @param scale The scale of the sprite
         */
        virtual void setScale(unsigned int scale) = 0;
    };
} // namespace arcade::api
