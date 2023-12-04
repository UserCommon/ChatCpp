#include "User.hpp"

User::User() : m_nickname("Unauthorized") {}

User::User(std::string &&nickname) : m_nickname(nickname) {}

std::string User::getNickname() { return m_nickname; }
