#include "Buffer.h"

Buffer createTemporaryBuffer() {
    Buffer temp(20);
    temp.setData("Salut din move!");
    return temp; // declanșează move constructor
}

int main() {
    std::cout << "=== Demonstrație tema ===\n";

    Buffer b1(15);
    b1.setData("Salut lume");
    b1.print();

    std::cout << "\n--- Test Copy Constructor ---\n";
    Buffer b2 = b1;  // declanșează copy constructor
    b2.print();

    std::cout << "\n--- Test Move Constructor ---\n";
    Buffer b3 = createTemporaryBuffer();  // declanșează move constructor
    b3.print();

    std::cout << "\n--- Sfârșit program ---\n";
    return 0;
}
