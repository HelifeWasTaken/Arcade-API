#pragma once

namespace arcade::api
{
    /**
     * @brief Specific abstraction of the time
     *        in case of type modification
     *
     */
    using Time = double;

    /**
     * @brief API Implementation of IClock
     *
     */
    class IClock
    {
      public:
        /**
         * @brief Restarts the clock
         *
         */
        virtual void restart() = 0;

        /**
         * @brief Get the Time As Millseconds object
         *
         * @return Time as Milliseconds
         *
         */
        virtual Time getTimeAsMilliseconds() const = 0;

        /**
         * @brief Get the Time As Seconds object
         *
         * @return Time as Seconds
         *
         */
        virtual Time getTimeAsSeconds() const = 0;

        /**
         * @brief Get the current tick
         *
         * @return unsigned int The current tick
         *
         */
        virtual unsigned int getTick() const = 0;

        /**
         * @brief Set the number of milliseconds between ticks
         *
         * @return Set the number of seconds
         *
         */
        virtual void setTick(unsigned int milliseconds) = 0;

        /**
         * @brief Destroy the IClock object
         *
         */
        virtual ~IClock() = default;
    };
} // namespace arcade::api
