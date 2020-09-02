#include "view.h"

void View::clearView() const
{
    std::cout << "Canvas was cleared" << std::endl;
}

void View::drawPrimitives(const std::shared_ptr<Document>& primitives)
{
    clearView();
    for (auto& primitive : *primitives)
    {
        primitive->draw();
    }
}