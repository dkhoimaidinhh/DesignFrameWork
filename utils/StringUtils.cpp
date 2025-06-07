#include "StringUtils.h"

std::string StringUtils::trim(const std::string &s)
{
    // TODO
    auto start = s.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) return ""; // String is all whitespace
    auto end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}

std::vector<std::string> StringUtils::split(const std::string &s, char delimiter)
{
    // TODO
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter))
    {
        if (!token.empty())
        {
            tokens.push_back(trim(token));
        }
    }
    return tokens;
}

std::map<std::string, std::string> StringUtils::parseJSON(const std::string &json)
{
    // TODO
    std::map<std::string, std::string> result;
    std::string trimmedJson = trim(json);
    if (trimmedJson.empty() || trimmedJson.front() != '{' || trimmedJson.back() != '}')
    {
        std::cerr << "Invalid JSON format: " << trimmedJson << std::endl;
        return result;
    }
    std::string content = trimmedJson.substr(1, trimmedJson.size() - 2); 
    std::vector<std::string> pairs = split(content, ',');
    for (const auto &pair : pairs)
    {
        std::vector<std::string> keyValue = split(pair, ':');
        if (keyValue.size() == 2)
        {
            std::string key = trim(keyValue[0]);
            std::string value = trim(keyValue[1]);
            if (key.front() == '"' && key.back() == '"')
                key = key.substr(1, key.size() - 2);
            if (value.front() == '"' && value.back() == '"')
                value = value.substr(1, value.size() - 2);
            result[key] = value;
        }
    }
    return result;
}
