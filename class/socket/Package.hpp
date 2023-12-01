#ifndef PACKAGEINIT
#define PACKAGEINIT 1

#include <cstdint>

// Persistant so doesn't need thread safety
template <typename T>
class Package {
  public:
    uint32_t size;

    Package(T &&data, uint32_t size);
    Package();

    T getData();
    uint32_t getSize();

  private:
    T &&m_data;
};

#endif
