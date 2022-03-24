#pragma once

#include <memory>

namespace arcade::api
{
    /**
     * @brief Forward declaration of arcade::IEvent
     *
     */
    class IEvent;

    /**
     * @brief Forward declaration of arcade::IEntity
     *
     */
    class IEntity;

    class ICanvas;

    /**
     * @brief The representation of an Entity id
     *
     */
    using EntityId = unsigned long long;

    /**
     * @brief Abstraction of the shared_ptr object IEntity
     *
     */
    using EntityElement = std::shared_ptr<IEntity>;

    /**
     * @brief API Implementation of IEntity (optional)
     *
     */
    class IEntity
    {
      public:
        /**
         * @brief Update the entity
         * This should never throw an error
         *
         */
        virtual void update() = 0;

        /**
         * @brief Draws the entity
         * This should never throw an error
         *
         */
        virtual void draw(ICanvas& canvas) = 0;

        /**
         * @brief Update the entity (Events only)
         * This should never throw an error
         *
         * @param event The event object
         *
         */
        virtual void onEvent(const IEvent &event) = 0;

        /**
         * @brief Get the Id object
         * This should never throw an error
         *
         * @return EntityId
         *
         */
        virtual EntityId getId() const = 0;

        /**
         * @brief Get the type object
         * This should never throw an error
         *
         * @return type
         *
         */
        virtual int getType() const = 0;

        /**
         * @brief Sets the Id object
         *
         */
        virtual void setId(EntityId id) = 0;

        /**
         * @brief Destroy the IEntity object
         * This should never throw an error
         *
         */
        virtual ~IEntity() = default;
    };

    /**
     * @brief API Implementation of IEntityManager (optional)
     *
     */
    class IEntityManager
    {
      public:
        /**
         * @brief Update all the entities
         * This should never throw an error
         *
         */
        virtual void updateEntities() = 0;

        /**
         * @brief Draw all the entities
         * This should never throw an error
         *
         */
        virtual void drawEntities(ICanvas& canvas) = 0;

        /**
         * @brief Update the events of all the entities
         * This should never throw an error
         *
         * @param event The event object
         *
         */
        virtual void onEventEntities(const IEvent &event) = 0;

        /**
         * @brief Add an entity to the manager
         * This should never throw an arcade::Error as the
         * EntityElement should already be created
         * and the program should be safely added with standard STL
         *
         * @param entity The entity to add
         * @return EntityId The id of the entity
         *
         */
        virtual EntityId addEntity(const EntityElement &entity) = 0;

        /**
         * @brief Get the Entity object
         * If the Entity linked to the given ID
         * does not exists throw a standard arcade::Error
         *
         * @param id The id of the entity
         * @return EntityElement& A reference to the entity
         *
         */
        virtual IEntity &getEntity(EntityId id) = 0;

        /**
         * @brief Get the Entity Element object
         * If the Entity linked to the given ID
         * does not exists throw a standard arcade::Error
         *
         * @param id The id of the entity
         * @return EntityElement& A reference to the entityElement
         *
         */
        virtual EntityElement &getEntityElement(EntityId id) = 0;

        /**
         * @brief Get the entity from a Type
         * if the specified entity is NULL returns the first occurence
         * if the specified entity is non NULL returns the first occurence
         * AFTER the specified entity
         * it is recommended to wrap the return value around a std::shared_ptr
         * if it is non null
         *
         * @param int EntityType
         * @param api::IEntity * pointer to the start of the search
         * @return api::IEntity * A pointer to newly found entity
         *
         */
        virtual IEntity *getEntityFromType(int entityType, api::IEntity *lastEntity) = 0;

        /**
         * @brief Remove an entity from the manager
         * If the Entity linked to the given ID
         * does not exists throw a standard arcade::Error
         *
         * @param id The id of the entity
         *
         */
        virtual void removeEntity(EntityId id) = 0;

        /**
         * @brief Destroy the IEntityManager object
         *
         */
        virtual ~IEntityManager() = default;
    };
} // namespace arcade::api
