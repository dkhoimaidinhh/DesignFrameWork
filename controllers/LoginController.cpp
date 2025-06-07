#include "LoginController.h"
#include <random>

std::string generateRandomToken(size_t length = 16) {
    static const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    static std::mt19937 rng(std::random_device{}());
    static std::uniform_int_distribution<> dist(0, sizeof(charset) - 2);

    std::string token;
    for (size_t i = 0; i < length; ++i) {
        token += charset[dist(rng)];
    }
    return token;
}

Response LoginController::handle(const Request &req)
{
    auto json = req.body;
    std::string username = json["username"];
    std::string password = json["password"];

    if (username == "admin" && password == "123456")
    {
        // TODO
        std::string token = generateRandomToken();
        TokenStore::instance().store(token, Role::ADMIN);
        return {200, token};  
    }
    else if (username == "user" && password == "123456")
    {
        // TODO
        std::string token = generateRandomToken();
        TokenStore::instance().store(token, Role::USER);
        return {200, token};
    }
    return {200, "Fail login!!!"};
}