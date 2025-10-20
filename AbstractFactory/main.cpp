#include "AbstractFactory.hpp"
#include <memory>

void clientCode(PresentationFactory* factory) {
    auto slide = factory->createSlide();
    auto textbox = factory->createTextBox();
    auto image = factory->createImage();
    auto shape = factory->createShape();

    slide->display();
    textbox->type();
    image->insert();
    shape->draw();
}

int main() {
    std::unique_ptr<PresentationFactory> factory = std::make_unique<CorporateFactory>();
    clientCode(factory.get());

    factory = std::make_unique<CreativeFactory>();
    clientCode(factory.get());

    return 0;
}
