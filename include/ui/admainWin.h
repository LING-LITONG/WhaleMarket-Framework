#ifndef ADMAIN_WIN
#define ADMAIN_WIN

#include <vector>
#include <iostream>
#include <string>
#include "UserStruct.h"

using product = struct product {
    std::string ID;
    std::string name;
    std::string price;
    std::string listingDate;
    std::string sellerID;
    std::string productStatus;
};

class AdmainWin {

public:
    AdmainWin(std::vector<User> *users, std::vector<Order> *orders);

    void mainShow();

    void viewAllProducts();

    void searchProduct();

    void viewAllOrders(); // Added method for viewing all orders

    void viewAllUsers(); // Added method for viewing all users

    void deleteUser(); // Added method for deleting a user

    void deleteProduct(); // Added method for deleting a product

    void close(); // Added method for closing the program

    void menuChoice(char choice);

private:
    std::vector<User> users;
    std::vector<Order> orders;

    std::vector<product> products = {
        {"M00001", "数据库", "10.0", "2021-03-14", "U00001", "已售出"},
        {"M00002", "算法分析", "20.0", "2021-03-14", "U00002", "销售中"},
        {"M00003", "编程语言", "30.0", "2021-03-14", "U00003", "已下架"},
        {"M00004", "高级程序设计", "40.0", "2021-03-14", "U00001", "销售中"},
        {"M00005", "C程序设计", "10.0", "2021-03-14", "U00003", "已售出"}};

    std::string divider = "======================================================================";
    std::string viewAllProductsIfo = "查看所有商品";
    std::string searchProductIfo = "搜索商品";
    std::string viewAllOrdersIfo = "查看所有订单"; // Added string for viewing all orders
    std::string viewAllUsersIfo = "查看所有用户";  // Added string for viewing all users
    std::string deleteUserIfo = "删除用户";        // Added string for deleting a user
    std::string deleteProductIfo = "下架商品";     // Added string for deleting a product
    std::string closeIfo = "关闭程序";             // Added string for closing the program

    std::vector<std::string> menuItems = {
        viewAllProductsIfo, searchProductIfo, viewAllOrdersIfo, viewAllUsersIfo,
        deleteUserIfo,      deleteProductIfo, closeIfo};
};

#endif