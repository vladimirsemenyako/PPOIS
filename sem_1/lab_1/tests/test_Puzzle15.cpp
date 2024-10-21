#include "../Puzzle15.h"
#include <gtest/gtest.h>

TEST(Puzzle15, ConstructorInitializesField) {
    Puzzle15 puzzle;
    EXPECT_EQ(puzzle[0].size(), 4);
    EXPECT_EQ(puzzle[1].size(), 4);
}

TEST(Puzzle15, MakeFieldGeneratesCorrectField) {
    Puzzle15 puzzle;
    bool has_zero = false;
    bool has_fifteen = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (puzzle[i][j] == 0) has_zero = true;
            if (puzzle[i][j] == 15) has_fifteen = true;
        }
    }
    EXPECT_TRUE(has_zero);
    EXPECT_TRUE(has_fifteen);
}

TEST(Puzzle15, MoveCellUpdatesField) {
    Puzzle15 puzzle;
    int initial_value = -1;
    int empty_row = -1, empty_col = -1;
    
    // Находим пустую клетку и соседнюю с ней
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (puzzle[i][j] == 0) {
                empty_row = i;
                empty_col = j;
                if (j < 3) initial_value = puzzle[i][j+1];
                else if (j > 0) initial_value = puzzle[i][j-1];
                else if (i < 3) initial_value = puzzle[i+1][j];
                else if (i > 0) initial_value = puzzle[i-1][j];
                break;
            }
        }
        if (empty_row != -1) break;
    }
    
    ASSERT_NE(initial_value, -1);
    EXPECT_TRUE(puzzle.moveCell(initial_value));
    EXPECT_EQ(puzzle[empty_row][empty_col], initial_value);
}

TEST(Puzzle15, FieldIsCorrectReturnsFalseForIncorrectField) {
    Puzzle15 puzzle;
    EXPECT_FALSE(puzzle.fieldIsCorrect());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}