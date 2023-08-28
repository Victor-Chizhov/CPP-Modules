#include "Serializer.hpp"

int main() {
    int value = 42;
    int* ptr = &value;

    uintptr_t uintptr = reinterpret_cast<uintptr_t>(ptr);

    int* newPtr = reinterpret_cast<int*>(uintptr);

    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "uintptr_t value: " << uintptr << std::endl;
    std::cout << "Restored pointer: " << newPtr << std::endl;

    std::cout << std::endl;

    Data a;
    a.s1 = "Hello";
    Data* ptr1 = &a;
    uintptr_t serialized = Serializer::serialize(ptr1);
    Data* ptr2 = Serializer::deserialize(serialized);

    std::cout << "Original pointer: " << ptr1 << std::endl;
    std::cout << "uintptr_t value: " << serialized << std::endl;
    std::cout << "Restored pointer: " << ptr2 << std::endl;
    std::cout << "s1: " << ptr2->s1 << std::endl;

    return 0;
}