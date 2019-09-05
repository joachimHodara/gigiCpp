#include <cassert>
#include <fstream>
#include <iostream>

class Vec2
{
public:
    Vec2(float x = 0, float y = 0)
    : x_(x), y_(y)
    {
        std::cout << "I just created a Vec2(x,y)" << std::endl;
        counter_++;
    }

    Vec2(const Vec2& u)
    : x_(u.x_), y_(u.y_)
    {
        std::cout << "I just created a Vec2(u)" << std::endl;
        counter_++;
    }

    ~Vec2()
    {
        std::cout << "I just destroyed a Vec2" << std::endl;
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

    float dot(const Vec2& u) const
    {
        return x_*u.x_ + y_*u.y_;
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

float dot(const Vec2& u, const Vec2& v)
{
    return u.getx()*v.getx() + u.gety()*v.gety();
}

void print(Vec2 v)
{
    std::cout << v << std::endl;
}

int main()
{
    Vec2 v(2,3);
    Vec2 u(v);

    print(u);

    std::cout << "bonjour Bibounde" << std::endl;
}

