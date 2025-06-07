#include "AuthMiddleware.h"

bool AuthMiddleware::authorize(const Request &req)
{
    if (req.path == "/login")
        return true;

    return TokenStore::instance().contains(req.token);
}