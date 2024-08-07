#ifndef USER_STRUCT_H // 如果没有定义 USER_STRUCT_H
#define USER_STRUCT_H // 那么定义 USER_STRUCT_H

#include <string>

struct User {
    std::string ID;
    std::string username;
    std::string password;
    std::string contactInfo;
    std::string address;
    std::string walletBalance;

    auto operator==(const User &other) const -> bool {
        return ID == other.ID && username == other.username && password == other.password
               && contactInfo == other.contactInfo && address == other.address
               && walletBalance == other.walletBalance;
    }
};

struct Order {
    std::string orderID;
    std::string productID;
    std::string transactionAmount;
    std::string transactionTime;
    std::string buyerID;
    std::string sellerID;
};

#endif // 结束 USER_STRUCT_H
