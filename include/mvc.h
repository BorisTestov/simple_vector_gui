#include "primitives.h"

#include <memory>
#include <vector>

using Document = std::vector<std::unique_ptr<AbstractPrimitive>>;

class Controller;

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
    void setDocument(std::shared_ptr<Document> newDocument);
    /**
     * @brief Получить текущий документ
     * @return std::shared_ptr<Document> поинтер на документ
     */
    [[nodiscard]] const std::shared_ptr<Document> getDocument() const;
    /**
     * @brief Добавить примитив в документ
     * @param primitive Примитив для добавления
     */
    void addPrimitive(std::unique_ptr<AbstractPrimitive>&& primitive);
    /**
     * @brief Удалить примитив из документа
     * @param eraseIndex индек примитива для удаления
     */
    void removePrimitive(int eraseIndex);
    /**
     * @brief Задать контроллер
     * @param newController новый контроллер
     */
    void setController(Controller& newController);
    /**
     * @brief Обновить содержимое
     */
    void refresh();

private:
    std::shared_ptr<Document> document;
    Controller* controller;
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
    void drawPrimitives(const std::shared_ptr<Document>& primitives) const;
};

/**
 * @brief Контроллер
 */
class Controller
{
public:
    Controller(Model& model, const View& view);
    /**
     * @brief Создать новый документ
     */
    void createNewDocument();
    /**
     * @brief Экспорт в файл
     * @param filename Имя файла
     */
    void exportToFile(const std::string& filename);
    /**
     * @brief Импорт из файла
     * @param filename имя файла
     */
    void importFromFile(const std::string& filename);
    /**
     * @brief Добавить примитив
     * @param primitive Примитив для добавления
     */
    void addPrimitive(std::unique_ptr<AbstractPrimitive> primitive);
    /**
     * @brief Удалить примитив
     * @param primitiveId id Примитива для удаления
     */
    void removePrimitive(int primitiveId);
    /**
     * @brief Обновить холст
     */
    void refreshCanvas();

private:
    Model* model;
    const View* view;
};