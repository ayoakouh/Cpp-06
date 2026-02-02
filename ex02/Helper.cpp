#include "Helper.hpp"

Base * generate(void)
{
    std::srand(time(NULL));
    int  i;
    i = std::rand();
    if(i % 2 == 0)
    {
        std::cout<<"We Generated an object of type C"<<std::endl;
        return new C();
    }
    else if(i % 3)
    {
        std::cout<<"We Generated an object of type A"<<std::endl;
        return new A();
    }
    else
    {
        std::cout<<"we Generated an object of type B"<<std::endl;
        return new B();
    }
    return NULL;
}

void identify(Base* p)
{
    if(dynamic_cast<C*>(p) != NULL)
        std::cout<< "this type of the object is: C"<<std::endl;
    else if(dynamic_cast<A*>(p) != NULL)
        std::cout<< "this type of the object is: A"<<std::endl;
    else if(dynamic_cast<B*>(p) != NULL)
        std::cout<< "this type of the object is: B"<<std::endl;
    else
        std::cout << "Unknown Type" <<std::endl;
}


void identify(Base& p)