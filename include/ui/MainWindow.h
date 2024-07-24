#ifndef MAINWINDOW__auto_type
#define MAINWINDOW__auto_type

#include <iostream>
#include <vector>
#include <string> // Add this line to include the <string> header file

typedef struct Users {
    std::string username;
    std::string password;
} User;

class MainWindow {
public:
    MainWindow();
    ~MainWindow();

    void mainShow();

    void userLogin();

    void adminLogin();

    void userRegister();

    void userExit();

    void menuChoice(char choice);

private:
    User admain = {"admin", "123456"};
    User user = {"user", "123456"};
    std::vector<User> users = {user};

    std::string divider = "==================================================";
    std::string adminUsernameLogIfo = "管理员登录";
    std::string userLogIfo = "用户登录";
    std::string userRegisterIfo = "用户注册";
    std::string userExitIfo = "退出程序";

    std::vector<std::string> menuItems = {userLogIfo, userRegisterIfo, adminUsernameLogIfo,
                                          userExitIfo};
};

#endif