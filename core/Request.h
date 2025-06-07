#pragma once
#include <string>
#include <map>
#include <iostream>
#include <sstream>

struct Request
{
    std::string method;
    std::string path;
    std::string token;
    std::map<std::string, std::string> body;
};

inline std::ostream &operator<<(std::ostream &os, const Request &req)
{
    std::ostringstream oss;
    oss << "METHOD: " << req.method << "\n";
    oss << "PATH: " << req.path << "\n";
    oss << "token: " << req.token << "\n";
    oss << "BODY :\n{\n";

    for (auto it = req.body.begin(); it != req.body.end(); ++it)
    {
        oss << "  \"" << it->first << "\": \"" << it->second << "\"";
        if (std::next(it) != req.body.end())
            oss << ",";
        oss << "\n";
    }

    oss << "}";
    return os << oss.str();
}