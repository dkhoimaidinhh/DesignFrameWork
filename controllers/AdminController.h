#pragma once
#include "Controller.h"

class AdminController : public Controller
{
public:
    Response handle(const Request &req) override;
};