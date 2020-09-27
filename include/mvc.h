#pragma once

#include "primitives.h"

#include <memory>
#include <vector>

class Model;
class View;
class Controller;

using AbstractPrimitiveUptr = std::unique_ptr<AbstractPrimitive>;
using Document = std::vector<AbstractPrimitiveUptr>;
using DocumentPtr = std::shared_ptr<Document>;
using ModelPtr = std::shared_ptr<Model>;
using ViewPtr = std::shared_ptr<View>;
using ControllerPtr = std::shared_ptr<Controller>;
using ControllerWptr = std::weak_ptr<Controller>;

/**
 * @brief Класс Model для хранения данных
 */
class Model
{
public:
    Model();
    /**
     * @brief Очистить документ
     */
    void clearDocument();
    /**
     * @brief задать новый документ
     * @param newDocument новый документ
     */
    void setDocument(DocumentPtr newDocument);
    /**
     * @brief Получить текущий документ
     * @return std::shared_ptr<Document> поинтер на документ
     */
    [[nodiscard]] const DocumentPtr getDocument() const;
    /**
     * @brief Добавить примитив в документ
     * @param primitive Примитив для добавления
     */
    void addPrimitive(AbstractPrimitiveUptr primitive);
    /**
     * @brief Удалить примитив из документа
     * @param eraseIndex индек примитива для удаления
     */
    void removePrimitive(int eraseIndex);
    /**
     * @brief Задать контроллер
     * @param controller новый контроллер
     */
    void setController(ControllerPtr controller);
    /**
     * @brief Обновить содержимое
     */
    void refresh();

private:
    DocumentPtr _document;
    ControllerWptr _controller;
};

/**
 * @brief Класс для отображения данных
 */
class View
{
public:
    /**
     * @brief Очистить вид
     */
    void clearView() const;
    /**
     * @brief Отобразить примитивы
     * @param primitives Примитивы для отображения
     */
    void drawPrimitives(const DocumentPtr& primitives) const;
};

/**
 * @brief Контроллер
 */
class Controller
{
public:
    Controller(const ModelPtr& model, const ViewPtr& view);
    /**
     * @brief Создать новый документ
     */
    void createNewDocument();
    /**
     * @brief Экспорт в файл
     * @param filename Имя файла
     */
    void exportToFile(const std::string& filename) const;
    /**
     * @brief Импорт из файла
     * @param filename имя файла
     */
    [[maybe_unused]] void importFromFile(const std::string& filename) const;
    /**
     * @brief Добавить примитив
     * @param primitive Примитив для добавления
     */
    void addPrimitive(AbstractPrimitiveUptr primitive);
    /**
     * @brief Удалить примитив
     * @param primitiveId id Примитива для удаления
     */
    [[maybe_unused]] void removePrimitive(int primitiveId);
    /**
     * @brief Обновить холст
     */
    void refreshCanvas();

private:
    ModelPtr _model;
    ViewPtr _view;
};