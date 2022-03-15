#pragma once

namespace arcade::api
{
    /**
     * @brief Forward declaration of arcade::IEntity
     *
     */
    class IEntity;

    /**
     * @brief Forward declaration of arcade::IEntityManager
     *
     */
    class IEntityManager;

    /**
     * @brief Forward declaration of arcade::IEvent
     *
     */
    class IEvent;

    /**
     * @brief Forward declaration of arcade::ICanvas
     *
     */
    class ICanvas;

    /**
     * @brief API Implementation of IGame
     *
     */
    class IGame
    {
      public:
        /**
         * @brief Initialize the game
         *
         */
        virtual void init() = 0;

        /**
         * @brief Destroy the game
         *
         */
        virtual void destroy() = 0;

        /**
         * @brief Update the game (Events only)
         *
         * @param event The event object
         *
         */
        virtual void onEvent(const IEvent &event) = 0;

        /**
         * @brief Update the game
         * Should be called after onEvent at each frame
         * For every entities if you use it
         *
         */
        virtual void update() = 0;

        /**
         * @brief Draw you game generally
         * Should draw all your entities if you use it
         *
         */
        virtual void draw(ICanvas &canvas) = 0;

        /**
         * @brief Destroy the IGame object
         *
         */
        virtual ~IGame() = default;
    };
} // namespace arcade::api
