#pragma once
#include <iostream>
#include <memory>

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Square" << std::endl;
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        std::cout << "Triangle" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Rectangle" << std::endl;
    }
};
