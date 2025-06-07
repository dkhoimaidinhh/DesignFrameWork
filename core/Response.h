#pragma once
#include <string>
#include <map>

struct Response
{
    int status_code;
    std::string status_text;

    static Response unauthorized();
    static Response error();
    std::string toCS23Format() const;
};
