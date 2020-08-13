#include <iostream>
#include <stdexcept>
#include <assert.h>

class Point2D
{
public:
  float x;
  float y;

  Point2D(float initialX, float initialY)
  : x(initialX), y(initialY) { }
};

/*
 * An axis-aligned 2D rectangle
 */
class Rectangle2D
{
public:
  Rectangle2D(const Point2D& bottomLeftOrigin, float width, float height)
  : m_bottomLeftOrigin(bottomLeftOrigin), m_width(width), m_height(height)
  {
    std::cout << "normal ctor" << std::endl;

    if(width < 0.0f)
    {
      throw std::invalid_argument("The width argument cannot be negative");
    }
    else if(height < 0.0f)
    {
      throw std::invalid_argument("The height argument cannot be negative");
    }
  }
  
  Rectangle2D(const Rectangle2D& other)
  : m_bottomLeftOrigin(other.m_bottomLeftOrigin), m_width(other.m_width), m_height(other.m_height)
  {
    std::cout << "copy ctor" << std::endl;
  }

  Rectangle2D& operator=(const Rectangle2D& other)
  {
    std::cout << "assignment operator" << std::endl;

    if(this == &other) { return *this; }

    m_bottomLeftOrigin = other.m_bottomLeftOrigin;
    m_width = other.m_width;
    m_height = other.m_height;

    return *this;
  }

  const Point2D& GetBottomLeftOrigin() const { return m_bottomLeftOrigin; }
  float GetWidth() const { return m_width; }
  float GetHeight() const { return m_height; }

  bool ContainsPoint(const Point2D& point) const;
  bool IntersectsRectangle(const Rectangle2D& other) const;

private:
  Point2D m_bottomLeftOrigin;
  float m_width;
  float m_height;
};

// helper functions begins

bool Intersects(float x1, float y1, float w1, float h1, 
                float x2, float y2, float w2, float h2)
{
  return x1 + w1 >= x2 &&
          x1 <= x2 + w2 &&
          y1 + h1 >= y2 &&
          y1 <= y2 + h2;
}

// Rectangle2D implementation begins

bool Rectangle2D::ContainsPoint(const Point2D &point) const 
{
  return Intersects(point.x, point.y, 0.0f, 0.0f, 
                    m_bottomLeftOrigin.x, m_bottomLeftOrigin.y, m_width, m_height);
}

bool Rectangle2D::IntersectsRectangle(const Rectangle2D& other) const 
{
  return Intersects(m_bottomLeftOrigin.x, m_bottomLeftOrigin.y, m_width, m_height, 
                    other.GetBottomLeftOrigin().x, other.GetBottomLeftOrigin().y, other.GetWidth(), other.GetHeight());
}

// Testing code begins

int main()
{
  Point2D pointA1(0.0f, 0.0f);
  Point2D pointA2(10.0f, 0.0f);
  Point2D pointA3(0.0f, 10.0f);
  Point2D pointA4(10.0f, 10.0f);
  Point2D pointB1(5.0f, -10.0f);
  Point2D pointB2(10.0f, -10.0f);
  Point2D pointB3(5.0f, 20.0f);
  Point2D pointB4(10.0f, 20.0f);
  Point2D pointC1(-10.0f, 5.0f);
  Point2D pointC2(15.0f, 5.0f);
  Point2D pointC3(-10.0f, 20.0f);
  Point2D pointC4(15.0f, 20.0f);
  Point2D pointD1(-10.0f, -10.0f);
  Point2D pointD2(-5.0f, -10.0f);
  Point2D pointD3(-10.0f, -5.0f);
  Point2D pointD4(-5.0f, -5.0f);
  Point2D pointE1(-20.0f, -20.0f);
  Point2D pointE2(20.0f, -20.0f);
  Point2D pointE3(-20.0f, 30.0f);
  Point2D pointE4(20.0f, 30.0f);

  // use parameter constructor
  Rectangle2D rectangleA(pointA1, pointA4.x - pointA1.x, pointA4.y - pointA1.y);
  Rectangle2D rectangleB(pointB1, pointB4.x - pointB1.x, pointB4.y - pointB1.y);
  Rectangle2D rectangleC(pointC1, pointC4.x - pointC1.x, pointC4.y - pointC1.y);
  Rectangle2D rectangleD(pointD1, pointD4.x - pointD1.x, pointD4.y - pointD1.y);
  Rectangle2D rectangleE(pointE1, pointE4.x - pointE1.x, pointE4.y - pointE1.y);

  // use copy constructor
  Rectangle2D rectangle2(rectangleA);
  Rectangle2D rectangle3 = rectangleA;

  // use assignment operator
  rectangle2 = rectangleB;

  // test ContainsPoint
  // simple inside check
  assert(rectangleE.ContainsPoint(pointA1));
  // check for edge points
  assert(rectangleE.ContainsPoint(pointE1));
  assert(rectangleE.ContainsPoint(pointE2));
  assert(rectangleE.ContainsPoint(pointE3));
  assert(rectangleE.ContainsPoint(pointE4));
  // simple outside checks
  assert(!rectangleA.ContainsPoint(pointE1));
  assert(!rectangleA.ContainsPoint(pointE2));
  assert(!rectangleA.ContainsPoint(pointE3));
  assert(!rectangleA.ContainsPoint(pointE4));
  // 4 directangleional outside checks
  assert(!rectangleA.ContainsPoint(pointB1));
  assert(!rectangleA.ContainsPoint(pointC1));
  assert(!rectangleA.ContainsPoint(pointB3));
  assert(!rectangleA.ContainsPoint(pointC2));

  // test IntersectsRectangle
  // simple intersect
  assert(rectangleA.IntersectsRectangle(rectangleB));
  assert(rectangleA.IntersectsRectangle(rectangleC));
  assert(rectangleB.IntersectsRectangle(rectangleA));
  assert(rectangleB.IntersectsRectangle(rectangleC));
  assert(rectangleC.IntersectsRectangle(rectangleA));
  assert(rectangleC.IntersectsRectangle(rectangleB));
  // intersect self
  assert(rectangleA.IntersectsRectangle(rectangleA));
  // intersect when fully contained within
  assert(rectangleA.IntersectsRectangle(rectangleE));
  // intersect when fully containing
  assert(rectangleE.IntersectsRectangle(rectangleA));
  // simple no intersect
  assert(!rectangleA.IntersectsRectangle(rectangleD));
  assert(!rectangleD.IntersectsRectangle(rectangleA));
}