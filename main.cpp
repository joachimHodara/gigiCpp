#include <cassert>
#include <fstream>
#include <iostream>

class Vec2
{
public:
    Vec2(float x = 0, float y = 0)
    : x_(x), y_(y)
    {
        counter_++;
    }

    float getx() const
    {
        return x_;
    }

    float gety() const
    {
        return y_;
    }

    float operator[](int i) const
    {
        assert(i < 2);
        return (i == 0) ? x_ : y_;
    }

    float& operator[](int i)
    {
        assert(i < 2);
        return (i == 0) ? x_ : y_;
    }

    Vec2& operator+=(const Vec2& u)
    {
        x_ += u.x_;
        y_ += u.y_;
        return *this;
    }

    Vec2 operator+(const Vec2& u) const
    {
        return Vec2(x_ + u.x_, y_ + u.y_);
    }

    static int howMany() { return counter_; }

private:
    float x_, y_;
    static int counter_;
};

int Vec2::counter_ = 0;

std::ostream& operator<<(std::ostream& out, const Vec2& v)
{
    out << '(' << v.getx() << ',' << v.gety() << ')';
    return out;
}

int main()
{
    Vec2 v(2,3);
    Vec2 u(3);

    std::cout << Vec2::howMany() << std::endl;

    Vec2 w = v + u;
    std::cout << w << std::endl;

    w += u;
    std::cout << w << std::endl;
}

