#pragma once

namespace arcade
{
    /**
     * @brief Forward declaration of arcade::IEvent
     *
     */
    class IEvent;

    /**
     * @brief Forward declaration of arcade::ISprite
     *
     */
    class ISprite;

    /**
     * @brief Forward declaration of arcade::ICanvas
     *
     */
    class ICanvas;

    /**
     * @brief API Implementation of IDisplayEngine
     * The IDisplayEngine should have a Canvas to manage the display
     * And an implementation of the pollEvent system like the SFML one
     * It is recommended to use std::queue<IEvent> for the event queue
     *
     */
    class IDisplayEngine
    {
      public:
        /**
         * @brief Poll an event from the event queue
         *
         * @param event The event object
         * @return true if an event is available
         * @return false if no event is available
         *
         */
        virtual bool pollEvent(IEvent &event) = 0;

        /**
         * @brief Draws the sprite on the canvas at the given position
         *
         * @param sprite The sprite to draw
         *
         */
        virtual void draw(const ISprite &sprite) = 0;

        /**
         * @brief Should clear the canvas
         * It should always clear the canvas to black
         * due to limitations on libraries such as ncurses
         *
         */
        virtual void clear() = 0;

        /**
         * @brief Should draw the current canvas
         *
         */
        virtual void display() = 0;

        /**
         * @brief Get the canvas of the current display
         *
         */
        virtual ICanvas &getCanvas() = 0;

        /**
         * @brief Destroy the IDisplayEngine object
         *
         */
        virtual ~IDisplayEngine() = default;
    };
} // namespace arcade
