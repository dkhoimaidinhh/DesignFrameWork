#include "RequestParser.h"
#include <regex>
Request RequestParser::parse(const std::string &rawInput)
{
    Request req;

    std::istringstream iss(rawInput);
    std::string bodyJson;

    if (!(iss >> req.method >> req.path >> req.token))
    {
        throw std::invalid_argument("Invalid input format (missing method/path/token)");
    }

    std::getline(iss, bodyJson);

    if (!bodyJson.empty())
    {
        req.body = StringUtils::parseJSON(StringUtils::trim(bodyJson));
    }

    return req;
}
