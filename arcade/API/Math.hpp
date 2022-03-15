#pragma once

namespace arcade {
namespace math {
/**
 * @brief API Implementation of Vector2
 *
 */
struct Vector2 {
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
struct Vector3 {
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
struct Rectangle {
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
};

/**
 * @brief Get the distance between two points
 *
 * @param a The origin
 * @param b The arrival
 * @return Vector2 The offset
 *
 */
Vector2 distance(const Vector2 &a, const Vector2 &b);

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
double lerp(double a, double b, double c);

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
Vector2 lerp(const Vector2 &a, const Vector2 &b, double c);

/**
 * @brief Transform degrees to radian
 * @param degree The value in degrees
 * @return double The value in radians
 *
 */
double toRadian(double degree);

/**
 * @brief Transform radians to degrees
 * @param radian The value in radians
 * @return double The value in degrees
 *
 */
double toDegree(double radian);

/**
 * @brief Clamping permits to limitate a posisition
 * to a specific area
 * @param value The value to be clamped
 * @param min The minimum value
 * @param max The maximum value
 * @return double The clamped value
 *
 */
double clamp(double value, double min, double max);

/**
 * @brief Tells whether if a given position is inside a rectangle
 *
 * @param rect The rect surface
 * @param pos The position to test
 * @return true If the position is inside the rect
 * @return false If the position is not inside the rect
 *
 */
bool isInRect(const Rectangle &rect, const Vector2 &pos);

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
bool rectIntersect(const Rectangle &a, const Rectangle &b);
} // namespace math
} // namespace arcade
