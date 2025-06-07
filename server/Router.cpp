#include "Router.h"
#include "controllers/LoginController.h"
#include "controllers/AdminController.h"
#include "controllers/UserController.h"

// Controller lỗi dùng cho các trường hợp trả về lỗi
class ErrorController : public Controller {
    Response resp_;
public:
    ErrorController(const Response& resp) : resp_(resp) {}
    Response handle(const Request&) override { return resp_; }
};

Controller *Router::getController(const Request &req)
{
    std::string token = (req.token == "None") ? "" : req.token;
    std::cout << "[Router] Path: " << req.path << ", Method: " << req.method << ", Token: '" << token << "'" << std::endl;

    if (req.path == "/login" && req.method == "POST")
    {
        return new LoginController();
    }

    if (req.path == "/admin" && req.method == "GET")
    {
        if (!TokenStore::instance().contains(token))
        {
            // Không có token hoặc token không hợp lệ
            return new ErrorController(Response::unauthorized());
        }
        if (TokenStore::instance().getRole(token) != Role::ADMIN)
        {
            // Có token nhưng không phải ADMIN
            return new ErrorController(Response::error());
        }
        return new AdminController();
    }

    if (req.path == "/user" && req.method == "GET")
    {
        if (!TokenStore::instance().contains(token))
        {
            // Không có token hoặc token không hợp lệ
            return new ErrorController(Response::unauthorized());
        }
        Role role = TokenStore::instance().getRole(token);
        if (role != Role::USER && role != Role::ADMIN)
        {
            // Có token nhưng không phải USER hoặc ADMIN
            return new ErrorController(Response::error());
        }
        return new UserController();
    }

    return new ErrorController(Response::error());
}