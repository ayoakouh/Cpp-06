#include "Serializer.hpp"


int main()
{
    Data *ptr1 = new Data();
    Data *ptr2;

    ptr1->x = 42;
    ptr1->y = 'a';
    uintptr_t raw = Serializer::serialize(ptr1);
    std::cout << "raw: " << raw << std::endl;
    std::cout << "---------PTR1!---------" << std::endl;
    std::cout << "x: " << ptr1->x << std::endl;
    std::cout << "c: " << ptr1->y << std::endl;
    ptr2 = Serializer::deserialize(raw);
    std::cout << "---------PTR2!---------" << std::endl;
    std::cout << "x: " << ptr2->x << std::endl;
    std::cout << "c: " << ptr2->y << std::endl;
    delete ptr1;
    return 0;
}