#ifndef PACKAGEINIT
#define PACKAGEINIT 1

#include <cstdint>

// Persistant so doesn't need thread safety
template <typename T>
class Package {
  public:
    virtual void writeTo(int fd);
    // readFrom
    uint32_t size;

    Package(T data, uint32_t size);
    Package();

    T getData();
    uint32_t getSize();

  protected:
    T m_data; // T&&?
};

#endif
