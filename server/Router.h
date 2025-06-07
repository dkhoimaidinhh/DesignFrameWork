#pragma once
#include "core/Request.h"
#include "controllers/Controller.h"

class Router
{
public:
    static Controller *getController(const Request &req);
};