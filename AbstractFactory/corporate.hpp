#pragma once
#include "components.hpp"

class CorporateSlide : public Slide {
public:
    void display() override {
        std::cout << "Corporate Slide\n";
    }
};

class CorporateTextBox : public TextBox {
public:
    void type() override {
        std::cout << "Corporate TextBox\n";
    }
};

class CorporateImage : public Image {
public:
    void insert() override {
        std::cout << "Corporate Image\n";
    }
};

class CorporateShape : public Shape {
public:
    void draw() override {
        std::cout << "Corporate Shape\n";
    }
};
