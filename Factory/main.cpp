#include "shapefactory.hpp"
#include <memory>
#include <array>

int main() {
    std::array<std::unique_ptr<ShapeFactory>, 4> factories = {
        std::make_unique<CircleFactory>(),
        std::make_unique<SquareFactory>(),
        std::make_unique<TriangleFactory>(),
        std::make_unique<RectangleFactory>()
    };

    for (auto& factory : factories)
        factory->drawShape();

    return 0;
}
