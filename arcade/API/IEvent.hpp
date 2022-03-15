#pragma once

namespace arcade::api
{
    /**
     * @brief All the keycodes for Event API
     *
     */
    enum KeyCode
    {
        K_UP,
        K_RIGHT,
        K_DOWN,
        K_LEFT,
        K_A,
        K_B,
        K_C,
        K_D,
        K_E,
        K_F,
        K_G,
        K_H,
        K_I,
        K_J,
        K_K,
        K_L,
        K_M,
        K_N,
        K_O,
        K_P,
        K_Q,
        K_R,
        K_S,
        K_T,
        K_U,
        K_V,
        K_W,
        K_X,
        K_Y,
        K_Z,
        K_0,
        K_1,
        K_2,
        K_3,
        K_4,
        K_5,
        K_6,
        K_7,
        K_8,
        K_9,
        K_SPACE,
        K_ENTER,
        // Is not a KeyBoard key but
        // is used to simulate a quit event
        K_QUIT,
        // Is not a KeyBoard key but
        // is used to know how many keys are available
        K_COUNT
    };

    /**
     * @brief API Implementation of IButton
     *
     */
    class IButton
    {
      public:
        /**
         * @brief API Implementation of Button
         *
         */
        enum State
        {
            IDLE,
            PRESSED,
            RELEASED
        };

        /**
         * @brief Set the state of the button
         *
         * @param state The new state of the button
         *
         */
        virtual void setState(const State state) = 0;

        /**
         * @brief Get the state of the button
         *
         * @return State The state of the button
         *
         */
        virtual State getState() const = 0;

        /**
         * @brief Check if the button was pressed
         *
         * @return true The key is currently pressed
         * @return false The key is not currently pressed
         *
         */
        virtual bool isKeyPressed() const = 0;

        /**
         * @brief Check if the button was released
         *
         * @return true The key is currently pressed
         * @return false The key is not currently pressed
         *
         */
        virtual bool isKeyReleased() const = 0;

        /**
         * @brief Destroy the IButton object
         *
         */
        virtual ~IButton() = default;
    };

    /**
     * @brief API Implementation of IEvent
     *
     */
    class IEvent
    {
      public:
        /**
         * @brief Set the state of the button
         *
         * @param KeyCode The keycode of the button
         * @param State The new state of the button
         *
         */
        virtual void setKeyState(const KeyCode code,
                                 const IButton::State state) = 0;

        /**
         * @brief Check if the event is a key event
         *        and if it is currently pressed at the moment
         *
         * @param code KeyCode to check
         * @return true The key is currently pressed
         * @return false The key is not currently pressed
         *
         */
        virtual bool isKeyPressed(const KeyCode code) const = 0;

        /**
         * @brief Check if the event is a key event
         *        and if it is currently released at the moment
         *        This might not work in some cases like ncurses
         *        try to make a workaround if you need it
         * @param code KeyCode to check
         * @return true The key is currently released
         * @return false The key is not currently released
         *
         */
        virtual bool isKeyReleased(const KeyCode code) const = 0;

        /**
         * @brief Resets the event object
         *
         */
        virtual void reset() = 0;

        /**
         * @brief Destroy the IEvent object
         *
         */
        virtual ~IEvent() = default;
    };

} // namespace arcade::api

namespace arcade
{
    using KeyCode = api::KeyCode;
}
