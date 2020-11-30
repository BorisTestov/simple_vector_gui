#include "mvc.h"
#include "primitives.h"
#include "version.h"

#include <iostream>
#include <map>

int main()
{
    std::cout << "Current version: " << version() << std::endl;
    auto model = std::make_shared<Model>();
    auto view = std::make_shared<View>();
    auto controller = std::make_shared<Controller>(model, view);
    model->setController(controller);

    controller->createNewDocument();
    controller->addPrimitive(std::make_unique<Circle>(100, 50, 20));
    controller->addPrimitive(std::make_unique<Rectangle>(0, 10, 20, 80));
    model->refresh();
    controller->exportToFile("testfile.bin");
    return 0;
}
