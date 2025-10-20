#pragma once
#include <iostream>
#include <memory>

class Slide {
public:
    virtual void display() = 0;
    virtual ~Slide() = default;
};

class TextBox {
public:
    virtual void type() = 0;
    virtual ~TextBox() = default;
};

class Image {
public:
    virtual void insert() = 0;
    virtual ~Image() = default;
};

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};
