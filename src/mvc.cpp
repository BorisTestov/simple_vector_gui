#include "mvc.h"

#include <utility>

Model::Model()
{
    this->document = std::make_shared<Document>();
}

void Model::clearDocument()
{
    document->clear();
}

void Model::setDocument(std::shared_ptr<Document> newDocument)
{
    this->document = std::move(newDocument);
    refresh();
}

const std::shared_ptr<Document> Model::getDocument() const
{
    return document;
}

void Model::addPrimitive(std::unique_ptr<AbstractPrimitive>&& primitive)
{
    document->push_back(move(primitive));
}

void Model::removePrimitive(int eraseIndex)
{
    document->erase(document->begin() + eraseIndex);
    refresh();
}

void Model::setController(Controller& newController)
{
    this->controller = &newController;
}

void Model::refresh()
{
    controller->refreshCanvas();
}

void View::clearView() const
{
    std::cout << "Canvas was cleared" << std::endl;
}

void View::drawPrimitives(const std::shared_ptr<Document>& primitives) const
{
    clearView();
    for (auto& primitive : *primitives)
    {
        primitive->draw();
    }
}

Controller::Controller(Model& model, const View& view)
{
    this->model = &model;
    this->view = &view;
}

void Controller::createNewDocument()
{
    model->clearDocument();
}

void Controller::exportToFile(const std::string& filename)
{
    auto exportedDocument = model->getDocument();
    std::cout << "Export to file: " << filename << std::endl;
}

void Controller::importFromFile(const std::string& filename)
{
    auto importedFile = std::make_shared<Document>();
    model->setDocument(importedFile);
    std::cout << "Imported from file: " << filename << std::endl;
}

void Controller::addPrimitive(std::unique_ptr<AbstractPrimitive> primitive)
{
    model->addPrimitive(std::move(primitive));
}

void Controller::removePrimitive(int primitiveId)
{
    auto document = model->getDocument();
    int eraseIndex = -1;
    for (unsigned long i = 0; i < document->size(); i++)
    {
        if (document->at(i)->getId() == primitiveId)
        {
            eraseIndex = i;
            break;
        }
    }
    if (eraseIndex > -1)
    {
        model->removePrimitive(eraseIndex);
    }
}

void Controller::refreshCanvas()
{
    view->drawPrimitives(model->getDocument());
}