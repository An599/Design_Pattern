#include "VisualComponent.h"

Decorator::Decorator(IVisualComponent* component)
    : m_component(component) {
}

void Decorator::Draw()
{
    if (m_component) m_component->Draw();
}

void Decorator::Resize()
{
    if (m_component) m_component->Resize();
}

BorderDecorator::BorderDecorator(IVisualComponent* component, int width)
    : Decorator(component), m_width(width) {
}

void BorderDecorator::Draw()
{
    std::cout << "Drawing border width = " << m_width << std::endl;
    Decorator::Draw();
}

void BorderDecorator::Resize()
{
    std::cout << "Border resize adjustments" <<std::endl;
    Decorator::Resize();
}

void BorderDecorator::SetBorderWidth(int w)
{
    m_width = w;
}

int BorderDecorator::GetBorderWidth() const
{
    return m_width;
}

ColoredDecorator::ColoredDecorator(IVisualComponent* component, const std::string& color)
    : Decorator(component), m_color(color) {
}

void ColoredDecorator::Draw()
{
    std::cout << "Applying color: " << m_color << std::endl;
    Decorator::Draw();
}

void ColoredDecorator::Resize()
{
    std::cout << "Color-related resize " << std::endl;
    Decorator::Resize();
}

void ColoredDecorator::SetColor(const std::string& c)
{
    m_color = c;
}

std::string ColoredDecorator::GetColor() const
{
    return m_color;
}


void RectangleComponent::Draw()
{
    std::cout << "Drawing Rectangle " <<std::endl;
}

void RectangleComponent::Resize()
{
    std::cout << "Resizing Rectangle " << std::endl;
}


int main()
{
    RectangleComponent rect;
    
    BorderDecorator bordered(&rect, 5);
    ColoredDecorator colored(&bordered, "Blue");

    colored.Draw();
    colored.Resize();

    return 0;
}
