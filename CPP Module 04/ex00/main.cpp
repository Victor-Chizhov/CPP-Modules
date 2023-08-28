#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;

    std::cout << std::endl;

    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* j2 = new WrongCat();

    std::cout << std::endl;

    std::cout << meta2->getType() << std::endl;
    std::cout << j2->getType() << std::endl;

    std::cout << std::endl;

    meta2->makeSound();
    j2->makeSound();

    std::cout << std::endl;

    delete meta2;
    delete j2;

    return 0;
}