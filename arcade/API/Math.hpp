#pragma once

namespace arcade::api
{
    namespace math
    {
        /**
         * @brief API Implementation of Vector2
         *
         */
        struct Vector2
        {
            /**
             * @brief x axis in a 2D graph
             *
             */
            int x;

            /**
             * @brief y axis in a 2D graph
             *
             */
            int y;
        };

        /**
         * @brief API Implementation of Vector3
         *
         */
        struct Vector3
        {
            /**
             * @brief x axis in a 3D graph
             *
             */
            int x;

            /**
             * @brief y axis in a 3D graph
             *
             */
            int y;

            /**
             * @brief z axis in a 3D graph
             *
             */
            int z;
        };

        /**
         * @brief API Implementation of Rectangle
         *
         */
        struct Rectangle
        {
            /**
             * @brief x axis in a 2D plane
             *
             */
            int x;

            /**
             * @brief y axis in a 2D plane
             *
             */
            int y;

            /**
             * @brief Width of the current element
             *
             */
            unsigned int width;

            /**
             * @brief Height of the current element
             *
             */
            unsigned int height;
        };

        /**
         * @brief Get the distance between two points
         *
         * @param a The origin
         * @param b The arrival
         * @return Vector2 The offset
         *
         */
        static Vector2 distance(const Vector2 &a, const Vector2 &b);

        /**
         * @brief Get the lerp between a and b with the speed c
         * between two single points
         *
         * @param a The origin
         * @param b The arrival
         * @param c The speed
         * @return double The offset
         *
         */
        static double lerp(double a, double b, double c);

        /**
         * @brief Get the lerp between a and b with the speed c
         * between two vectors
         *
         * @param a The origin
         * @param b The arrival
         * @param c The speed
         * @return Vector2 The offset
         *
         */
        static Vector2 lerp(const Vector2 &a, const Vector2 &b, double c);

        /**
         * @brief Transform degrees to radian
         * @param degree The value in degrees
         * @return double The value in radians
         *
         */
        static double toRadian(double degree);

        /**
         * @brief Transform radians to degrees
         * @param radian The value in radians
         * @return double The value in degrees
         *
         */
        static double toDegree(double radian);

        /**
         * @brief Clamping permits to limitate a posisition
         * to a specific area
         * @param value The value to be clamped
         * @param min The minimum value
         * @param max The maximum value
         * @return double The clamped value
         *
         */
        static double clamp(double value, double min, double max);

        /**
         * @brief Tells whether if a given position is inside a rectangle
         *
         * @param rect The rect surface
         * @param pos The position to test
         * @return true If the position is inside the rect
         * @return false If the position is not inside the rect
         *
         */
        static bool isInRect(const Rectangle &rect, const Vector2 &pos);

        /**
         * @brief Tells whether if a given rectangle touches/intersects with an
         * another rectangle
         *
         * @param a The first rect surface
         * @param b The seconds rect surface
         * @return true If the first rect intersects with the second rect
         * @return false If the first rect does not intersects with the second
         * rect
         *
         */
        static bool rectIntersect(const Rectangle &a, const Rectangle &b);
    } // namespace math
} // namespace arcade::api

namespace arcade
{
    /**
     * @brief Easily access Vector2 from api::math::Vector2
     *
     */
    using Vector2 = api::math::Vector2;

    /**
     * @brief Easily access Vector3 from api::math::Vector3
     *
     */
    using Vector3 = api::math::Vector3;

    /**
     * @brief Easily access Rectangle from api::math::Rectangle
     *
     */
    using Rectangle = api::math::Rectangle;
} // namespace arcade
