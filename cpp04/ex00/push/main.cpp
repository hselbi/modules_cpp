#include "Animal.hpp"

int main()
{
    std::cout << "/************************Animal*************************/" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* c = new Cat();
        const Animal* d = new Dog();

        std::cout << "this is the type of animal : " << d->getType() << " " << std::endl;
        std::cout << "this is the type of animal : " << c->getType() << " " << std::endl;

        d->makeSound();
        c->makeSound();
        meta->makeSound();
        delete d;
        delete c;
        delete meta;
    }

    std::cout << "/************************non-Animal*************************/" << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* wcat = new WrongCat();

        std::cout << "this is the type of animal : \t" << wcat->getType() << " " << std::endl;
        wcat->makeSound();
        meta->makeSound();
        
        delete wcat;
        delete meta;

    }

    return 0;
}