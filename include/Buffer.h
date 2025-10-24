#pragma once
#include <iostream>
#include <cstring>

class Buffer {
private:
    char* data;   // zonă alocată dinamic pe heap
    size_t size;

public:
    // Constructor cu inițializare a membrilor
    Buffer(size_t s);

    // Destructor - eliberează memoria
    ~Buffer();

    // Copy constructor (copie profundă)
    Buffer(const Buffer& other);

    // Move constructor
    Buffer(Buffer&& other) noexcept;

    // Încapsulare: metode de acces și modificare
    void setData(const char* text);
    const char* getData() const;

    void print() const;
};
