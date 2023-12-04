#include <iostream>
#include <cstring>

class Figure {
private:
    char* type;

    void copy(char*& target, const char* source) {
        target = new char[strlen(source) + 1];
        strcpy(target, source);
    }
public:
    Figure(const char* type) {
        copy(this->type, type);
    }

    Figure(Figure const& other) {
        copy(this->type, other.type);
    }

    Figure& operator=(Figure const& other) {
        if (this != &other) {
            delete[] type;
            copy(this->type, other.type);
        }

        return *this;
    }

    ~Figure() {
        delete[]this->type;
    }

    const char* getType() const {
        return this->type;
    }

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

class Square : public Figure 
{
    double side;
public:

    Square(double inputSide) : Figure("Square")
    {
        side = inputSide;
    }

    Square(Square const& other)  : Figure("Square")
    {
        side = other.side;
    }

    const char* getType() const
    {
        return "Square";
    }

    double getPerimeter() const
    {
        return side * 4;
    }

    double getArea() const
    {
        return side * side;
    }
};

class Circle : public Figure
{
    double radius;
    const double pi = 3.1415;
public:

    Circle(double inputRadius) : Figure("Circle")
    {
        radius = inputRadius;
    }

    Circle(Circle const& other) : Figure("Circle")
    {
        radius = other.radius;
    }

    const char* getType() const
    {
        return "Circle";
    }

    double getPerimeter() const
    {
        return 2 * pi * radius;
    }

    double getArea() const
    {
        return pi * radius * radius;
    }
};

class Triangle : public Figure
{
    double a, b , c;

public:

    Triangle(double inputA, double inputB, double inputC) : Figure("Triangle")
    {
        a = inputA;
        b = inputB;
        c = inputC;
    }

    Triangle(Triangle const& other) : Figure("Triangle")
    {
        a = other.a;
        b = other.b;
        c = other.c;
    }

    const char* getType() const
    {
        return "Triangle";
    }

    double getPerimeter() const
    {
        return a + b + c;
    }

    double getArea() const
    {
        double halfPerimeter = (a + b + c) / 2;

        return sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));
    }
};