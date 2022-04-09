#pragma once

#include <string>

namespace arcade::api
{
    /**
     * @brief Forward declaration of arcade::ICore
     *
     */
    class ICore;

    /**
     * @brief API Implementation of DLLoader
     *
     */
    template <typename T>
    class IDLLoader
    {
      public:
        /**
         * @brief Load a library
         * If the library could not be load OR the constructor
         * could not be load OR the destructor could not be load
         * throw an Error
         *
         * @param path The path to the library
         * @tparam T The type of the library
         * @return T* the object of the library
         *
         */
        virtual T *load(const std::string &path) = 0;

        /**
         * @brief Unload the current library safely
         * Should never throw an Error as the destructor should
         * always be safe
         *
         */
        virtual void unload() = 0;

        /**
         * @brief Get the current library name
         *
         * @return T* the object of the library
         *
         */
        const std::string &getName() const;

        /**
         * @brief Destroy the IDLLoader object
         *
         */
        virtual ~IDLLoader() = default;
    };
} // namespace arcade::api

extern "C"
{

/**
 * @brief Arcade C symbol display engine constructor symbol
 *
 */
#define ARCADE_DISPLAY_ENGINE_CONSTRUCTOR_SYM \
    "__arcade_display_engine_constructor"

/**
 * @brief Arcade C symbol game constructor symbol
 *
 */
#define ARCADE_GAME_CONSTRUCTOR_SYM "__arcade_game_constructor"

/**
 * @brief Arcade C style destructor symbol
 *
 */
#define ARCADE_DESTRUCTOR_SYM "__arcade_destructor"

/**
 * @brief default c style constructor to load
 * a display engine module (in order to have a default symbol)
 * This should never throw an exception
 *
 * @param core the arcade core to query it through the module
 * @return void * the new module object
 *
 */
#define ARCADE_DISPLAY_ENGINE_CONSTRUCTOR \
    void *__arcade_display_engine_constructor()

/**
 * @brief default c style constructor to load
 * a game module (in order to have a default symbol)
 * This should never throw an exception
 *
 * @param core the arcade core to query it through the module
 * @return void * the new module object
 *
 */
#define ARCADE_GAME_CONSTRUCTOR void *__arcade_game_constructor()

/**
 * @brief Default C style destructor to unload
 * a module (In order to have a default symbol)
 * This should never throw an exception
 *
 * @param cObject Object to static or C style cast
 * to delete it
 * @param bool cleanup Should cleanup the library
 *
 */
#define ARCADE_DESTRUCTOR void __arcade_destructor(void *cObject, bool cleanup)

    /**
     * @brief default c style constructor to load
     * a module (in order to have a default symbol)
     *
     * @return void * the new module object
     *
     */
    ARCADE_DISPLAY_ENGINE_CONSTRUCTOR;

    /**
     * @brief default c style constructor to load
     * a module (in order to have a default symbol)
     *
     * @return void * the new module object
     *
     */
    ARCADE_GAME_CONSTRUCTOR;

    /**
     * @brief Default C style destructor to unload
     * a module (In order to have a default symbol)
     *
     * @param cObject Object to static or C style cast
     * to delete it
     *
     */
    ARCADE_DESTRUCTOR;
};
