#include "Package.hpp"
#include <utility>

template <typename T>
Package<T>::Package(T &&data, uint32_t size) : m_data(data), size(size) {}

template <typename T>
Package<T>::Package() {
    m_data = std::declval<T>();
    size = 0;
};

template <typename T>
T Package<T>::getData() {
    return m_data;
}

template <typename T>
uint32_t Package<T>::getSize() {
    return size;
}
