#include "LoginController.h"

Response LoginController::handle(const Request &req)
{
    auto json = req.body;
    std::string username = json["username"];
    std::string password = json["password"];

    if (username == "admin" && password == "123456")
    {
        // TODO
    }
    else if (username == "user" && password == "123456")
    {
        // TODO
    }
    return {200, "Fail login!!!"};
}