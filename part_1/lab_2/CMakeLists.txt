cmake_minimum_required(VERSION 3.29)
project(MinimarketProject)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

add_executable(MinimarketProject main.cpp
        Person/Person.cpp
        Cashier/Cashier.cpp
        Staff/Staff.cpp
        Staff/Staff.h
        Person/Person.h
        Cashier/Cashier.h
        Manager/Manager.cpp
        Manager/Manager.h
        Minimarket/Minimarket.h
        Minimarket/Minimarket.cpp
        Product/Product.cpp
        Product/Product.h
        Grocery/Grocery.cpp
        Grocery/Grocery.h
        Cosmetics/Cosmetics.cpp
        Cosmetics/Cosmetics.h
        Homegoods/Homegoods.cpp
        Homegoods/Homegoods.h
        Stationary/Stationary.cpp
        Stationary/Stationary.h
        Bakery/Bakery.cpp
        Bakery/Bakery.h
        Dairy/Dairy.cpp
        Dairy/Dairy.h
        Canned/Canned.cpp
        Canned/Canned.h
        Kitchenware/Kitchenware.cpp
        Kitchenware/Kitchenware.h
        Textiles/Textiles.cpp
        Textiles/Textiles.h)

add_executable(mininarketTest
        Bakery/Bakery.cpp
        Bakery/Bakery.h
        tests/BakeryTest.cpp
        Canned/Canned.cpp
        Canned/Canned.h
        tests/CannedTest.cpp
        Cashier/Cashier.cpp
        Cashier/Cashier.h
        tests/CashierTest.cpp
        Cosmetics/Cosmetics.cpp
        Cosmetics/Cosmetics.h
        tests/CosmeticsTest.cpp
        Dairy/Dairy.cpp
        Dairy/Dairy.h
        tests/DairyTest.cpp
        Grocery/Grocery.cpp
        Grocery/Grocery.h
        tests/GroceryTest.cpp
        Homegoods/Homegoods.cpp
        Homegoods/Homegoods.h
        tests/HomegoodsTest.cpp
        Kitchenware/Kitchenware.cpp
        Kitchenware/Kitchenware.h
        tests/KitchenwareTest.cpp
        Manager/Manager.cpp
        Manager/Manager.h
        tests/ManagerTest.cpp
        Minimarket/Minimarket.cpp
        Minimarket/Minimarket.h
        tests/MinimarketTest.cpp
        Person/Person.cpp
        Person/Person.h
        tests/PersonTest.cpp
        Product/Product.cpp
        Product/Product.h
        tests/ProductTest.cpp
        Staff/Staff.cpp
        Staff/Staff.h
        tests/StaffTest.cpp
        Stationary/Stationary.cpp
        Stationary/Stationary.h
        tests/StationaryTest.cpp
        Textiles/Textiles.cpp
        Textiles/Textiles.h
        tests/TextilesTest.cpp

)

target_link_libraries(mininarketTest gtest gtest_main)

enable_testing()

add_test(NAME mininarketTest COMMAND mininarketTest)