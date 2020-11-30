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

void Model::setDocument(DocumentPtr newDocument)
{
    _document = newDocument;
    refresh();
}

const DocumentPtr Model::getDocument() const
{
    return _document;
}

void Model::addPrimitive(AbstractPrimitiveUptr primitive)
{
    _document->push_back(move(primitive));
}

void Model::removePrimitive(int eraseIndex)
{
    _document->erase(_document->begin() + eraseIndex);
    refresh();
}

void Model::setController(ControllerPtr controller)
{
    _controller = controller;
}

void Model::refresh()
{
    ControllerPtr _controller_lock = _controller.lock();
    if (_controller_lock)
    {
        _controller_lock->refreshCanvas();
    }
}

// View

void View::clearView() const
{
    std::cout << "Canvas was cleared" << std::endl;
}

void View::drawPrimitives(const DocumentPtr& primitives) const
{
    clearView();
    for (auto& primitive : *primitives)
    {
        primitive->draw();
    }
}

// Controller

Controller::Controller(const ModelPtr& model, const ViewPtr& view)
{
    _model = model;
    _view = view;
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

void Controller::addPrimitive(AbstractPrimitiveUptr primitive)
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