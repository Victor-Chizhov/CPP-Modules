#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {


    const Animal* i = new Cat();
    const Animal* j = new Dog();

    delete i;
    delete j; 

    Dog p;
    {
        Dog a = p;
    }


    const Animal *arr[4];

    for(int i = 0; i < 4; i++)
        i < 2 ? arr[i] = new Dog() : arr[i] = new Cat();

    for(int i = 0; i < 4; i++)
        delete arr[i];



    return 0;
}