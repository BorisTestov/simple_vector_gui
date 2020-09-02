#pragma once
#include "primitives.h"

#include <memory>
#include <vector>

using Document = std::vector<std::unique_ptr<IShape>>;

class View
{
public:
    void clearView() const;
    void drawPrimitives(const std::shared_ptr<Document>& primitives);
};