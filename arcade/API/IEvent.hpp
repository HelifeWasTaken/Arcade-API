#pragma once

#include <array>

namespace arcade
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
         * @brief Destroy the IEvent object
         *
         */
        virtual ~IEvent() = default;
    };

    class Button : public IButton
    {
      public:
        ~Button() override = default;

        bool isKeyPressed(void) const override;
        bool isKeyReleased(void) const override;

        void setState(const State newState) override;
        State getState(void) const override;

      private:
        State _state = IDLE;
    };

    class Event : public IEvent
    {
      public:
        void setKeyState(const KeyCode code,
                         const IButton::State state) override;

        bool isKeyPressed(const KeyCode code) const override;
        bool isKeyReleased(const KeyCode code) const override;

        ~Event() override = default;

      private:
        std::array<Button, KeyCode::K_COUNT> _buttonArray;
    };
} // namespace arcade
