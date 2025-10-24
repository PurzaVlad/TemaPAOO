#include "Buffer.h"

// Constructor cu inițializare
Buffer::Buffer(size_t s) : size(s), data(new char[s]) {
    std::cout << "Constructor: am alocat " << size << " bytes.\n";
    data[0] = '\0';
}

// Destructor
Buffer::~Buffer() {
    std::cout << "Destructor: eliberez memoria (" << size << " bytes).\n";
    delete[] data;
}

// Copy constructor (copie profundă)
Buffer::Buffer(const Buffer& other) : size(other.size), data(new char[other.size]) {
    std::memcpy(data, other.data, size);
    std::cout << "Copy constructor: copiez " << size << " bytes.\n";
}

// Move constructor
Buffer::Buffer(Buffer&& other) noexcept : size(other.size), data(other.data) {
    other.data = nullptr;
    other.size = 0;
    std::cout << "Move constructor: am mutat resursa.\n";
}

// Încapsulare - metode
void Buffer::setData(const char* text) {
    std::strncpy(data, text, size - 1);
    data[size - 1] = '\0';
}

const char* Buffer::getData() const {
    return data;
}

void Buffer::print() const {
    std::cout << "Buffer conține: " << data << "\n";
}
