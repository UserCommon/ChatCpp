#include "User.hpp"
User::User() : m_nickname("Unauthorized"){};
template <>
struct std::hash<User> {
    std::size_t operator()(const User &u) const {
        return std::hash<std::string>()(u.getNickname());
    }
};

User::User(std::string nickname) : m_nickname(nickname) {}

std::string User::getNickname() const { return m_nickname; }

std::size_t User::operator==(const User &other) {
    return this->m_nickname == other.getNickname();
}
