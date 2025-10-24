#include "Buffer.h"

// aloca memorie noua pentru un buffer de dim s (constructor)
Buffer::Buffer(size_t s) : size(s), data(new char[s]) {
    std::cout << "Constructor: am alocat " << size << " bytes.\n";
    data[0] = '\0';
}

// automat la final, pentru ca a fost initializat de tip buffer (destructor)
Buffer::~Buffer() {
    std::cout << "Destructor: eliberez memoria (" << size << " bytes).\n";
    delete[] data;
}

// aloca memorie noua si copiaza (copy)
Buffer::Buffer(const Buffer& other) : size(other.size), data(new char[other.size]) {
    std::memcpy(data, other.data, size);
    std::cout << "Copy constructor: copiez " << size << " bytes.\n";
}

// muta datele din vechiul buffer in unul nou (move)
Buffer::Buffer(Buffer&& other) noexcept : size(other.size), data(other.data) {
    other.data = nullptr;
    other.size = 0;
    std::cout << "Move constructor: am mutat resursa.\n";
}

// pentru incapsulare
void Buffer::setData(const char* text) {
    std::strncpy(data, text, size - 1);
    data[size - 1] = '\0';
}

//pentru incapsulare, pentru extract
const char* Buffer::getData() const {
    return data;
}

void Buffer::print() const {
    std::cout << "Buffer contine: " << data << "\n";
}
