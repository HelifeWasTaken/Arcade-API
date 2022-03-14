#pragma once

#include <exception>

namespace arcade
{
    /**
     * @brief Base class for all errors in the arcade
     *
     */
    class IError : public std::exception
    {
      public:
        /**
         * @brief Return a C style string
         * giving information about the error
         *
         */
        virtual char const *what() = 0;

        /**
         * @brief Destruct the Error object
         *
         */
        virtual ~IError() = default;
    };
} // namespace arcade
