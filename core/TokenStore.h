#pragma once
#include <map>
#include <string>
#include <ostream>

enum class Role
{
    UNKNOWN,
    USER,
    ADMIN
};

class TokenStore
{
private:
    std::map<std::string, Role> tokenRoleMap;

    TokenStore() = default;

public:
    static TokenStore &instance();

    void store(const std::string &token, Role role);
    Role getRole(const std::string &token);
    bool contains(const std::string &token);

    friend std::ostream &operator<<(std::ostream &os, const TokenStore &store);
};

inline std::ostream &operator<<(std::ostream &os, Role role)
{
    switch (role)
    {
    case Role::USER:
        return os << "USER";
    case Role::ADMIN:
        return os << "ADMIN";
    default:
        return os << "UNKNOWN";
    }
}

inline std::ostream &operator<<(std::ostream &os, const TokenStore &store)
{
    for (const auto &entry : store.tokenRoleMap)
    {
        os << entry.first << " => " << entry.second << '\n';
    }
    return os;
}