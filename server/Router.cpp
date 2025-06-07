#include "Router.h"
#include "controllers/LoginController.h"
#include "controllers/AdminController.h"
#include "controllers/UserController.h"

Controller *Router::getController(const Request &req)
{

    if (req.path == "/login" && req.method == "POST")
    {
        return new LoginController();
    }

    // TODO
    return nullptr;
}
