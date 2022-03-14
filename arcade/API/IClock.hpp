#pragma once

namespace arcade
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
        virtual Time getTimeAsMillseconds() const = 0;

        /**
         * @brief Get the Time As Seconds object
         *
         * @return Time as Seconds
         *
         */
        virtual Time getTimeAsSeconds() const = 0;

        /**
         * @brief Destroy the IClock object
         *
         */
        virtual ~IClock() = default;
    };
} // namespace arcade
