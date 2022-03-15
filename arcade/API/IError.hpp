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
        virtual char const *what() const noexcept = 0;

        /**
         * @brief Destruct the Error object
         *
         */
        virtual ~IError() = default;
    };
} // namespace arcade

/**
 * @brief Should be used as a nested class
 *
 */
#define ARCADE_ERROR_CLASS_IMPL \
    class Error : public IError \
    { \
      private: \
        const std::string _error; \
        \
      public: \
        Error(const std::string &error) \
            : _error(error) \
        { \
        } \
        \
        const char *what() const noexcept override \
        { \
            return _error.c_str(); \
        } \
    };

