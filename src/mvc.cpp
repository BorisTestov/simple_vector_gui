#include "mvc.h"

#include <utility>

// Model

Model::Model()
{
    _document = std::make_shared<Document>();
}

void Model::clearDocument()
{
    _document->clear();
}

void Model::setDocument(std::shared_ptr<Document> newDocument)
{
    _document = newDocument;
    refresh();
}

const std::shared_ptr<Document> Model::getDocument() const
{
    return _document;
}

void Model::addPrimitive(std::unique_ptr<AbstractPrimitive> primitive)
{
    _document->push_back(move(primitive));
}

void Model::removePrimitive(int eraseIndex)
{
    _document->erase(_document->begin() + eraseIndex);
    refresh();
}

void Model::setController(const Controller& newController)
{
    _controller = std::make_shared<Controller>(newController);
}

void Model::refresh()
{
    _controller->refreshCanvas();
}

// View

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

// Controller

Controller::Controller(const Model& model, const View& view)
{
    _model = std::make_shared<Model>(model);
    _view = std::make_shared<View>(view);
}

void Controller::createNewDocument()
{
    _model->clearDocument();
}

void Controller::exportToFile(const std::string& filename) const
{
    auto exportedDocument = _model->getDocument();
    std::cout << "Export to file: " << filename << std::endl;
}

void Controller::importFromFile(const std::string& filename) const
{
    auto importedFile = std::make_shared<Document>();
    _model->setDocument(importedFile);
    std::cout << "Imported from file: " << filename << std::endl;
}

void Controller::addPrimitive(std::unique_ptr<AbstractPrimitive> primitive)
{
    _model->addPrimitive(std::move(primitive));
}

void Controller::removePrimitive(int primitiveId)
{
    auto document = _model->getDocument();
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
        _model->removePrimitive(eraseIndex);
    }
}

void Controller::refreshCanvas()
{
    _view->drawPrimitives(_model->getDocument());
}