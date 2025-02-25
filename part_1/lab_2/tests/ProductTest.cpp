#include <gtest/gtest.h>
#include "../Product/Product.h"
#include "../Grocery/Grocery.h"
#include "../Cosmetics/Cosmetics.h"
#include "../Homegoods/Homegoods.h"
#include "../Stationary/Stationary.h"

// Тест конструктора
TEST(ProductTest, ConstructorTest) {
    Product product("Apple", 0.99, 100, "Fruit");

    EXPECT_EQ(product.getName(), "Apple");
    EXPECT_FLOAT_EQ(product.getPrice(), 0.99);
    EXPECT_EQ(product.getQuantity(), 100);
    EXPECT_EQ(product.getCategory(), "Fruit");
}

// Тест установки и получения цены
TEST(ProductTest, SetAndGetPrice) {
    Product product("Banana", 0.59, 50, "Fruit");

    product.setPrice(0.75);
    EXPECT_FLOAT_EQ(product.getPrice(), 0.75);
}

// Тест установки и получения количества
TEST(ProductTest, SetAndGetQuantity) {
    Product product("Carrot", 1.20, 30, "Vegetable");

    product.setQuantity(40);
    EXPECT_EQ(product.getQuantity(), 40);
}

// Тест установки и получения категории
TEST(ProductTest, SetAndGetCategory) {
    Product product("Toothpaste", 2.50, 20, "Cosmetics");

    product.setCategory("Personal Care");
    EXPECT_EQ(product.getCategory(), "Personal Care");
}

// Тест отображения информации о продукте
TEST(ProductTest, DisplayInfo) {
    Product product("Soap", 1.99, 25, "Cosmetics");

    testing::internal::CaptureStdout();
    product.displayInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Product Name: Soap"), std::string::npos);
    EXPECT_NE(output.find("Category: Cosmetics"), std::string::npos);
    EXPECT_NE(output.find("Price: $1.99"), std::string::npos);
    EXPECT_NE(output.find("Available Quantity: 25"), std::string::npos);
}

// Тест покупки продукта
TEST(ProductTest, PurchaseSuccess) {
    Product product("Notebook", 3.50, 10, "Stationary");

    testing::internal::CaptureStdout();
    product.purchase(5);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("5 units of Notebook purchased."), std::string::npos);
    EXPECT_EQ(product.getQuantity(), 5);
}

// Тест покупки при недостаточном количестве
TEST(ProductTest, PurchaseNotEnoughStock) {
    Product product("Pen", 1.00, 2, "Stationary");

    testing::internal::CaptureStdout();
    product.purchase(3);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Not enough stock for Pen. Available: 2"), std::string::npos);
}

// Тест добавления продуктов в разные категории
TEST(ProductTest, AddCategories) {
    Product product("Grocery Item", 1.50, 50, "Grocery");

    // Создание объектов с использованием конструктора с параметрами
    Grocery groceryItem("Fruits", 2.0, 10, "10.10.2024");  // Пример параметров, замените на актуальные
    Cosmetics cosmeticItem("Lipstick", 10.0, 5, "Neutral");  // Пример параметров
    Homegoods homegoodsItem("Table", 100.0, 3, "Leather");  // Пример параметров
    Stationary stationaryItem("Notebook", 5.0, 20, "Erich Krause");  // Пример параметров

    product.addGrocery(&groceryItem);
    product.addCosmetics(&cosmeticItem);
    product.addHomegoods(&homegoodsItem);
    product.addStationary(&stationaryItem);

    EXPECT_EQ(product.groceries_.size(), 1); // Проверяем, что один элемент добавлен
    EXPECT_EQ(product.cosmetics_.size(), 1);
    EXPECT_EQ(product.homegoods_.size(), 1);
    EXPECT_EQ(product.stationaries_.size(), 1);
}