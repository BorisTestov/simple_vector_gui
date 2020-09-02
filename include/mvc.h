#include "primitives.h"

#include <memory>
#include <vector>

using Document = std::vector<std::unique_ptr<AbstractPrimitive>>;

class Controller;

class Model
{
public:
    Model();
    void clearDocument();
    void setDocument(std::shared_ptr<Document> newDocument);
    [[nodiscard]] const std::shared_ptr<Document> getDocument() const;
    void addPrimitive(std::unique_ptr<AbstractPrimitive>&& primitive);
    void removePrimitive(int eraseIndex);
    void setController(Controller& newController);
    void refresh();

private:
    std::shared_ptr<Document> document;
    Controller* controller;
};

class View
{
public:
    void clearView() const;
    void drawPrimitives(const std::shared_ptr<Document>& primitives) const;
};

class Controller
{
public:
    Controller(Model& model, const View& view);
    void createNewDocument();
    void exportToFile(const std::string& filename);
    void importFromFile(const std::string& filename);
    void addPrimitive(std::unique_ptr<AbstractPrimitive> primitive);
    void removePrimitive(int primitiveId);
    void refreshCanvas();

private:
    Model* model;
    const View* view;
};