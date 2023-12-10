#ifndef USER_H
#define USER_H
#include <cstddef>
#include <string>

class User {
  public:
    User();
    User(std::string m_nickname);

    std::string getNickname() const;
    std::size_t operator==(const User &other);

  private:
    std::string m_nickname;
};

#endif
