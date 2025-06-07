#include "Response.h"
#include <sstream>

Response Response::unauthorized()
{
    return {403, "Forbidden"};
}

Response Response::error()
{
    return {500, "Internal Server Error"};
}

std::string Response::toCS23Format() const
{
    std::ostringstream oss;
    oss << status_code << " " << status_text;
    return oss.str();
}