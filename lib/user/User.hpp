#ifndef USER_H
#define USER_H
#include <string>

class User {
  public:
    User();
    User(std::string &&m_nickname);

    std::string getNickname();

  private:
    std::string m_nickname;
};

#endif
