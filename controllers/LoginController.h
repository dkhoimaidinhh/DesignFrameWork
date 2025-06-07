#pragma once
#include "Controller.h"
#include "utils/TokenGenerator.h"
#include "core/TokenStore.h"

class LoginController : public Controller
{
public:
    Response handle(const Request &req) override;
};