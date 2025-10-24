#include "Buffer.h"

Buffer createTemporaryBuffer() {
    Buffer temp(20);
    temp.setData("in move");
    return temp; // declanșează move constructor
}

int main() {

    Buffer b1(15);
    b1.setData("test");
    b1.print();

    std::cout << "\nCopy Constructor\n";
    Buffer b2 = b1;  // declanseaza copy constructor
    b2.print();

    std::cout << "\nMove Constructor\n";
    Buffer b3 = createTemporaryBuffer();  // declanseaza move constructor
    b3.print();

    std::cout << "\nSfarsit\n";
    return 0;
}
