#include "mvc.h"
#include "primitives.h"
#include "version.h"

#include <iostream>
#include <map>

int main()
{
    std::cout << "Current version: " << version() << std::endl;
    Model model;
    View view;
    Controller controller(model, view);
    model.setController(controller);

    controller.createNewDocument();
    controller.addPrimitive(std::make_unique<Circle>(100, 50, 20));
    controller.addPrimitive(std::make_unique<Rectangle>(0, 10, 20, 80));
    model.refresh();
    controller.exportToFile("testfile.bin");
    return 0;
}
