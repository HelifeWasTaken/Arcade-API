#pragma once

namespace arcade::api
{

/**
 * @brief Standard window size on X axis
 *
 */
#define WINDOW_X 800

/**
 * @brief Standard window size on Y axis
 *
 */
#define WINDOW_Y 600

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
     * The IDisplayEngine implementation of the pollEvent system should be like the SFML one
     * It is recommended to use std::queue<int> for the event queue
     * in ncurses (and similar) because of the limitations
     * Other libraries should just use the event queue from their
     * respective libraries
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
         * @brief Should clear the canvas
         * It should always clear the canvas to black
         * due to limitations on libraries such as ncurses
         *
         */
        virtual void clear() = 0;

        /**
         * @brief Should draw the canvas
         * @param canvas The canvas to draw
         *
         */
        virtual void display(const ICanvas& canvas) = 0;

        /**
         * @brief Tells whether the Display/Arcade is running
         *
         */
        virtual bool isOpen() const = 0;

        /**
         * @brief Destroy the IDisplayEngine object
         *
         */
        virtual ~IDisplayEngine() = default;
    };
} // namespace arcade::api
