#pragma once
#include "Controller.h"

class UserController : public Controller
{
public:
    Response handle(const Request &req) override;
};