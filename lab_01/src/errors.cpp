#include <QMessageBox>

#include "errors.h"

void error_handle(const error_t &code)
{
    switch (code)
    {
        case ERROR_FILE_OPEN:
            QMessageBox::critical(NULL, "Ошибка!",
                                  "При открытии файла произошла ошибка.");
            break;
        case ERROR_MEMORY_ALLOCATION:
            QMessageBox::critical(NULL, "Ошибка!",
                                  "При выделении памяти произошла ошибка.");
            break;
        case ERROR_FILE_READING:
            QMessageBox::critical(NULL, "Ошибка!",
                                  "При чтении файла произошла ошибка.");
            break;
        case ERROR_EDGES_ARRAY_SIZE:
            QMessageBox::critical(NULL,
                                  "Ошибка!", "Некорректное количество ребер фигуры.");
            break;
        case ERROR_POINTS_ARRAY_SIZE:
            QMessageBox::critical(NULL,
                                  "Ошибка!", "Некорректное количество вершин фигуры.");
            break;
        case ERROR_MEMORY_TROUBLE:
            QMessageBox::critical(NULL,
                                  "Ошибка!", "Ошибка при обращении к данным.");
            break;
        default:
            QMessageBox::critical(NULL,
                                  "Ошибка!", "Несуществующий запрос.");
    }
}
