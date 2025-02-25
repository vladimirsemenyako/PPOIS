#include "Puzzle15.h"

Puzzle15::Puzzle15() : game_finished_(false) {
    makeField();
    showField();
    showMoves();
}

std::vector<int>& Puzzle15::operator[](std::size_t index) {
    return field_[index];
}

void Puzzle15::makeField() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    std::random_device rd;
    std::mt19937 g(rd());
    std::ranges::shuffle(nums, g);
    field_.resize(4, std::vector<int>(4));

    int t = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            field_[i][j] = nums[t++];
            if (field_[i][j] == 0) {
                empty_row_ = i;
                empty_col_ = j;
            }
        }
    }
}

void Puzzle15::showMoves() {
    std::vector<int> available_moves;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (field_[row][col] == 0) {
                if (col < 3) available_moves.push_back(field_[row][col + 1]);
                if (col > 0) available_moves.push_back(field_[row][col - 1]);
                if (row < 3) available_moves.push_back(field_[row + 1][col]);
                if (row > 0) available_moves.push_back(field_[row - 1][col]);
            }
        }
    }
    std::cout << "Доступные ходы: ";
    for (const int move : available_moves) {
        std::cout << move << " ";
    }
    std::cout << std::endl;
}

bool Puzzle15::moveCell(int user_move) {
    bool move_found = false;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (field_[row][col] == user_move) {
                if ((row == empty_row_ && (col == empty_col_ + 1 || col == empty_col_ - 1)) ||
                    (col == empty_col_ && (row == empty_row_ + 1 || row == empty_row_ - 1))) {
                    std::swap(field_[row][col], field_[empty_row_][empty_col_]);
                    empty_row_ = row;
                    empty_col_ = col;
                    move_found = true;
                }
                break;
            }
        }
        if (move_found) break;
    }

    if (move_found) {
        showField();
        showMoves();
        if (fieldIsCorrect()) {
            game_finished_ = true;
        }
    }
    return move_found;
}

void Puzzle15::showField() {
    std::cout << "------------------------------------------------------------------" << std::endl;
    for (const auto& row : field_) {
        std::cout << "|";
        for (const auto& cell : row) {
            std::cout << "\t" << cell << "\t";
        }
        std::cout << "|" << std::endl << "------------------------------------------------------------------" << std::endl;
    }
}

bool Puzzle15::fieldIsCorrect() {
    int correct_counter = 0;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            int expected_val = row * 4 + col + 1;
            if ((field_[row][col] == expected_val) && field_[3][3] == 0) {
                correct_counter++;
            }
        }
    }
    return correct_counter == 16;
}

bool Puzzle15::isGameFinished() const {
    return game_finished_;
}