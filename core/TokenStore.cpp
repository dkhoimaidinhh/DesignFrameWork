#include "TokenStore.h"

TokenStore* TokenStore::s_instance = nullptr;

// TODO

TokenStore &TokenStore::instance() {
    if (!s_instance) {
        s_instance = new TokenStore();
    }
    return *s_instance;
}

void TokenStore::store(const std::string &token, Role role) {
    tokenRoleMap[token] = role;
}

Role TokenStore::getRole(const std::string &token) {
    auto it = tokenRoleMap.find(token);
    if (it != tokenRoleMap.end()) {
        return it->second;
    }
    return Role::UNKNOWN;
}

bool TokenStore::contains(const std::string &token) {
    return tokenRoleMap.find(token) != tokenRoleMap.end();
}
