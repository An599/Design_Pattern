#pragma once
#include "components.hpp"

class CreativeSlide : public Slide {
public:
    void display() override {
        std::cout << "Creative Slide\n";
    }
};

class CreativeTextBox : public TextBox {
public:
    void type() override {
        std::cout << "Creative TextBox\n";
    }
};

class CreativeImage : public Image {
public:
    void insert() override {
        std::cout << "Creative Image\n";
    }
};

class CreativeShape : public Shape {
public:
    void draw() override {
        std::cout << "Creative Shape\n";
    }
};
