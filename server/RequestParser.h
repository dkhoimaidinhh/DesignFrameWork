#pragma once
#include "core/Request.h"
#include "utils/StringUtils.h"

class RequestParser
{
public:
    static Request parse(const std::string &rawInput);
};