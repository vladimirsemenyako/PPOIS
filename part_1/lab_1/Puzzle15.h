#ifndef PUZZLE15_H
#define PUZZLE15_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // Для std::ranges::shuffle

class Puzzle15 {
public:
    Puzzle15(); // Конструктор
    std::vector<int>& operator[](std::size_t index); // Оператор индексации
    void makeField(); // Создает игровое поле
    void showMoves(); // Показывает доступные ходы
    bool moveCell(int user_move); // Перемещает клетку
    void showField(); // Показывает текущее состояние поля
    bool fieldIsCorrect(); // Проверяет правильность поля
    bool isGameFinished() const; // Проверяет, закончена ли игра

private:
    std::vector<std::vector<int>> field_; // Игровое поле
    int empty_row_; // Строка пустой клетки
    int empty_col_; // Столбец пустой клетки
    bool game_finished_; // Флаг завершения игры
};

#endif // PUZZLE15_H
