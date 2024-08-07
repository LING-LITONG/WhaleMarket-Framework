#include "ui/admainWin.h"
#include "UserStruct.h"
#include <iostream>
#include <string>
#include <vector>

AdmainWin::AdmainWin(std::vector<User> *users, std::vector<Order> *orders) {
    this->users = *users;
    this->orders = *orders;
}

void AdmainWin::mainShow() {
    while (true) {
        std::cout << "\033c";
        std::cout << divider << std::endl;
        int i = 1;
        for (const std::string &item : menuItems) {
            std::cout << i << "." << item << "  ";
            i++;
        }
        std::cout << std::endl;
        std::cout << divider << std::endl;

        std::cout << "请输入您的选择：";

        std::string choice;
        std::cin >> choice;
        menuChoice(choice.at(0));
        std::cout << "按q退出，按c继续,按e返回主菜单" << std::endl;
        std::cin >> choice;
        if (choice == "q") {
            exit(0);
        } else if (choice == "e") {
            break;
        } else if (choice == "c") {
            continue;
        }
    }
}

void AdmainWin::menuChoice(char choice) {
    switch (choice) {
        case '1':
            viewAllProducts();
            break;
        case '2':
            searchProduct();
            break;
        case '3':
            viewAllOrders(); // Added case for viewing all orders
            break;
        case '4':
            viewAllUsers(); // Added case for viewing all users
            break;
        case '5':
            deleteUser(); // Added case for deleting a user
            break;
        case '6':
            deleteProduct(); // Added case for deleting a product
            break;
        case '7':
            close(); // Added case for closing the program
            break;
        default:
            std::cout << "输入错误，请重新输入" << std::endl;
            mainShow();
            break;
    }
}

void AdmainWin::viewAllProducts() {
    std::cout << "*************************************************************" << std::endl;
    std::cout << "商品ID\t商品名称\t价格\t上架日期\t卖家ID\t商品状态" << std::endl;
    for (const product &p : products) {
        std::cout << p.ID << "\t" << p.name << "\t" << p.price << "\t" << p.listingDate << "\t"
                  << p.sellerID << "\t" << p.productStatus << std::endl;
    }
    std::cout << "*************************************************************" << std::endl;
}

void AdmainWin::searchProduct() {
    std::cout << "请输入商品名称：";
    std::string name;
    std::cin >> name;

    bool isSearched = false;
    for (const product &p : products) {
        if (p.name.find(name) != std::string::npos) {
            isSearched = true;
            std::cout << "*************************************************************"
                      << std::endl;
            std::cout << "商品ID\t商品名称\t价格\t上架日期\t卖家ID\t商品状态" << std::endl;
            std::cout << p.ID << "\t" << p.name << "\t" << p.price << "\t" << p.listingDate << "\t"
                      << p.sellerID << "\t" << p.productStatus << std::endl;
            std::cout << "*************************************************************"
                      << std::endl;
        }
    }
    if (!isSearched) {
        std::cout << "*************" << std::endl;
        std::cout << "未找到相关商品" << std::endl;
        std::cout << "*************" << std::endl;
    }
}

void AdmainWin::viewAllOrders() {
    std::cout << "***************************************************************\n";
    std::cout << "ID       商品ID   交易金额   交易时间     买家ID    卖家ID\n";
    std::cout << "***************************************************************\n";

    for (const auto &order : orders) {
        std::cout << order.orderID << "   " << order.productID << "   " << order.transactionAmount
                  << "   " << order.transactionTime << "   " << order.buyerID << "   "
                  << order.sellerID << "\n";
    }

    std::cout << "***************************************************************\n";
}

void AdmainWin::viewAllUsers() {
    std::cout << "*************************************************************" << std::endl;
    std::cout << "用户ID\t\t用户名\t\t联系方式\t\t地址\t\t\t钱包余额" << std::endl;

    for (const auto &user : users) {
        std::cout << user.ID << "\t" << user.username << "\t\t" << user.contactInfo << "\t\t"
                  << user.address << "\t" << user.walletBalance << std::endl;
    }

    std::cout << "*************************************************************" << std::endl;
}

void AdmainWin::deleteUser() {
    std::cout << "请输入要删除的用户ID：";
    std::string ID;
    std::cin >> ID;
    int i = 0;
    for (User &user : users) {
        if (user.ID == ID) {
            std::cout << "你确定要删除该用户吗！" << std::endl;
            std::cout << "***********************" << std::endl;
            std::cout << "用户ID" << user.ID << std::endl;
            std::cout << "用户名" << user.username << std::endl;
            std::cout << "联系方式" << user.contactInfo << std::endl;
            std::cout << "***********************" << std::endl;

            std::cout << "请选择（y/n）";
            std::string choice;
            std::cin >> choice;
            if (choice == "y") {
                users.erase(users.begin() + i);
                std::cout << "用户删除成功" << std::endl;
                break;
            } else {
                std::cout << "取消删除" << std::endl;
                break;
            }
        }
        i++;
    }
    std::cout << "未找到该用户" << std::endl;
}

void AdmainWin::deleteProduct() {

    std::string ID;
    product *deleteP = nullptr;
    std::cout << "请输入商品ID：";
    std::cin >> ID;
    for (product &p : products) {
        if (p.ID == ID) {
            deleteP = &p;
        }
    }

    std::cout << "你确定要下架该商品吗！" << std::endl;

    std::cout << "***********************" << std::endl;
    std::cout << "商品ID" << deleteP->ID << std::endl;
    std::cout << "商品名称" << deleteP->name << std::endl;
    std::cout << "商品价格" << deleteP->price << std::endl;
    std::cout << "***********************" << std::endl;

    std::cout << "请选择（y/n）";
    std::string choice;
    std::cin >> choice;

    if (choice == "y") {
        deleteP->productStatus = "已下架";
        std::cout << "商品下架成功" << std::endl;
    } else {
        std::cout << "取消下架" << std::endl;
    }
}

void AdmainWin::close() {
    exit(0);
}
