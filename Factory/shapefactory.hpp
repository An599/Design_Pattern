#pragma once
#include "shape.hpp"

class ShapeFactory {
public:
    virtual std::unique_ptr<Shape> factoryMethod() = 0;
    virtual ~ShapeFactory() = default;

    void drawShape() {
        auto shape = factoryMethod();
        shape->draw();
    }
};

class CircleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> factoryMethod() override {
        return std::make_unique<Circle>();
    }
};

class SquareFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> factoryMethod() override {
        return std::make_unique<Square>();
    }
};

class TriangleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> factoryMethod() override {
        return std::make_unique<Triangle>();
    }
};

class RectangleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> factoryMethod() override {
        return std::make_unique<Rectangle>();
    }
};
