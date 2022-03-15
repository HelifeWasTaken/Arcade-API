#pragma once

#include <string>

namespace arcade
{
    /**
     * @brief Forward declaration of arcade::IEvent
     *
     */
    class Event;

    /**
     * @brief Forward declaration of arcade::IGame
     *
     */
    class IGame;

    /**
     * @brief Forward declaration of arcade::IDisplayEngine
     *
     */
    class IDisplayEngine;

    /**
     * @brief Forward declaration of arcade::ISprite
     *
     */
    class ISprite;

    /**
     * @brief API Implementation of ICore
     *
     */
    class ICore
    {
      public:
        /**
         * @brief Destroy the ICore object
         *
         */
        virtual ~ICore() = default;

        /**
         * @brief Get an event from the event queue
         * Should throw an standard arcade::Error if no DisplayEngine is loaded
         *
         * @param event The event object
         * @return true if an event is available
         * @return false if no event is available
         *
         */
        virtual bool pollEvent(Event &event) = 0;

        /**
         * @brief Draws the sprite on the canvas of the current DisplayEngine
         * at the given position
         * Should throw an standard arcade::Error if no DisplayEngine is loaded
         *
         * @param sprite The sprite to draw
         *
         */
        virtual void draw(const ISprite &sprite) = 0;

        /**
         * @brief Load a new game (throw an exception if the game could not be
         * loaded) The game should be destroyed with inside the IDLLoader
         * before loading a new one
         * Should throw a standard arcade::Error in case of problem while
         * loading the library
         *
         */
        virtual void loadGame(const std::string &game) = 0;

        /**
         * @brief Load a new Display/DisplayEngine (throw an exception if the
         * (D/E) could not be loaded) The (D/E) should be destroyed with inside
         * the IDLLoader before loading a new one Should throw a standard
         * arcade::Error in case of problem while loading the library
         *
         */
        virtual void loadEngine(const std::string &DisplayEngine) = 0;

        /**
         * @brief Run the base loop for every game (So that the game
         * DisplayEngine loop is generic) (This function should be called only
         * if the Game and DisplayEngine are loaded) otherwise a standard
         * arcade::Error will be thrown
         *
         */
        virtual void run() = 0;
    };
} // namespace arcade
