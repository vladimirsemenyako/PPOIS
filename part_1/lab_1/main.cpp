#include "Puzzle15.h"
#include <iostream>

int main() {
    Puzzle15 puzzle;

    while (!puzzle.isGameFinished()) {
        int user_move;
        std::cout << "Ваш ход: ";
        std::cin >> user_move;

        if (!puzzle.moveCell(user_move)) {
            std::cout << "Неверный ход. Попробуйте снова." << std::endl;
        }
    }

    std::cout << "Поздравляем! Вы решили головоломку." << std::endl;
    return 0;
}
