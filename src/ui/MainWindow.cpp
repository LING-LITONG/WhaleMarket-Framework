#include "ui/MainWindow.h"
#include "ui/admainWin.h"
#include <string>

MainWindow::MainWindow() = default;

void MainWindow::mainShow() {
    while (true) {
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
    }
}

void MainWindow::menuChoice(char choice) {
    switch (choice) {
        case '1':
            userLogin();
            break;
        case '2':
            userRegister();
            break;
        case '3':
            adminLogin();
            break;
        case '4':
            userExit();
            break;
        default:
            std::cout << "输入错误，请重新输入" << std::endl;
            mainShow();
            break;
    }
}

void MainWindow::userLogin() {
    std::cout << "请输入用户名：";
    std::string username;
    std::cin >> username;
    std::cout << "请输入密码：";
    std::string password;
    std::cin >> password;

    for (const User &user : users) {
        if (user.username == username && user.password == password) {
            std::cout << "登录成功" << std::endl;
            return;
        }
    }
    std::cout << "\033c";
}

void MainWindow::adminLogin() {
    std::cout << "请输入管理员用户名：";
    std::string adminUsername;
    std::cin >> adminUsername;
    std::cout << "请输入管理员密码：";
    std::string adminPassword;
    std::cin >> adminPassword;

    if (admain.username == adminUsername && admain.password == adminPassword) {
        admainWin->mainShow();
    } else {
        std::cout << "管理员登录失败" << std::endl;
    }
    std::cout << "\033c";
}

void MainWindow::userRegister() {
    std::cout << "请输入用户名：";
    std::string username;
    std::cin >> username;
    std::cout << "请输入密码：";
    std::string password;
    std::cin >> password;

    //TODO(ling): Add more user information
    User user;
    user.username = username;
    user.password = password;
    users.push_back(user);
    std::cout << "\033c";
}

void MainWindow::userExit() {
    std::cout << "--------" << std::endl;
    std::cout << "程序退出" << std::endl;
    std::cout << "--------" << std::endl;
}