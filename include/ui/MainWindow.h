#ifndef MAINWINDOW__auto_type
#define MAINWINDOW__auto_type

#include <iostream>
#include <vector>
#include <string> // Add this line to include the <string> header file
#include "admainWin.h"
#include "UserStruct.h"

class MainWindow {
public:
    MainWindow();

    void mainShow();

    void userLogin();

    void adminLogin();

    void userRegister();

    void userExit();

    void menuChoice(char choice);

private:
    User admain = {"U00000", "admin", "123456"};
    // User user = {"U0001", "user", "123456"};
    std::vector<User> users = {{"U00001", "user1", "123456", "12333", "江苏省南京市南大", "10.0"},
                               {"U00002", "user2", "123456", "12334", "江苏省南京市南大", "100.0"}};

    std::vector<Order> orders = {
        {"T000001", "M00001", "10.0", "2021-03-14", "U00001", "U00002"},
        {"T000002", "M00002", "20.0", "2021-03-14", "U00003", "U00001"},
        // 其他订单信息...
    };

    AdmainWin *admainWin = new AdmainWin(&users, &orders);

    std::string divider = "==================================================";
    std::string adminUsernameLogIfo = "管理员登录";
    std::string userLogIfo = "用户登录";
    std::string userRegisterIfo = "用户注册";
    std::string userExitIfo = "退出程序";

    std::vector<std::string> menuItems = {userLogIfo, userRegisterIfo, adminUsernameLogIfo,
                                          userExitIfo};
};

#endif