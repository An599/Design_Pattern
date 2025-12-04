#pragma once
#include <iostream>
#include <string>

class IVisualComponent
{
public:
    virtual void Draw() = 0;
    virtual void Resize() = 0;
    virtual ~IVisualComponent() = default;
};

class Decorator : public IVisualComponent
{
public:
    Decorator(IVisualComponent* component);
    virtual void Draw() override;
    virtual void Resize() override;

protected:
    IVisualComponent* m_component;
};

class BorderDecorator : public Decorator
{
public:
    BorderDecorator(IVisualComponent* component, int width);

    void Draw() override;
    void Resize() override;

    void SetBorderWidth(int w);
    int GetBorderWidth() const;

private:
    int m_width;
};

class ColoredDecorator : public Decorator
{
public:
    ColoredDecorator(IVisualComponent* component, const std::string& color);

    void Draw() override;
    void Resize() override;

    void SetColor(const std::string& c);
    std::string GetColor() const;

private:
    std::string m_color;
};

class RectangleComponent : public IVisualComponent
{
public:
    void Draw() override;
    void Resize() override;
};
