#pragma once
#include "core/Request.h"
#include "core/Response.h"
#include "utils/StringUtils.h"

class Controller
{
public:
    virtual Response handle(const Request &req) = 0;
    virtual ~Controller() = default;
};