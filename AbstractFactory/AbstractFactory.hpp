#pragma once
#include "components.hpp"
#include "corporate.hpp"
#include "creative.hpp"

class PresentationFactory {
public:
    virtual std::unique_ptr<Slide> createSlide() = 0;
    virtual std::unique_ptr<TextBox> createTextBox() = 0;
    virtual std::unique_ptr<Image> createImage() = 0;
    virtual std::unique_ptr<Shape> createShape() = 0;
    virtual ~PresentationFactory() = default;
};

class CorporateFactory : public PresentationFactory {
public:
    std::unique_ptr<Slide> createSlide() override {
        return std::make_unique<CorporateSlide>();
    }
    std::unique_ptr<TextBox> createTextBox() override {
        return std::make_unique<CorporateTextBox>();
    }
    std::unique_ptr<Image> createImage() override {
        return std::make_unique<CorporateImage>();
    }
    std::unique_ptr<Shape> createShape() override {
        return std::make_unique<CorporateShape>();
    }
};

class CreativeFactory : public PresentationFactory {
public:
    std::unique_ptr<Slide> createSlide() override {
        return std::make_unique<CreativeSlide>();
    }
    std::unique_ptr<TextBox> createTextBox() override {
        return std::make_unique<CreativeTextBox>();
    }
    std::unique_ptr<Image> createImage() override {
        return std::make_unique<CreativeImage>();
    }
    std::unique_ptr<Shape> createShape() override {
        return std::make_unique<CreativeShape>();
    }
};
