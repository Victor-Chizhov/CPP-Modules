#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
}

Base* generate(void) {
    srand(time(NULL));
    int i = rand() % 3;
    switch(i) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "Object pointer type: A" << std::endl;
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "Object pointer type: B" << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "Object pointer type: C" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "Object reference type: A" << std::endl;
        (void)a;
    }
    catch (std::bad_cast& e) {
        try {
            B& b = dynamic_cast<B&>(p);
            std::cout << "Object reference type: B" << std::endl;
            (void)b;
        }
        catch (std::bad_cast& e) {
            try {
                C& c = dynamic_cast<C&>(p);
                std::cout << "Object reference type: C" << std::endl;
                (void)c;
            }
            catch (std::bad_cast& e) {
                std::cout << "Object reference type: unknown" << std::endl;
            }
        }
    }
}

