#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

    Animal *myAnimal = new Animal();
    Animal *myDog = new Dog();
    Animal *myCat = new Cat();
    std::cout << "/************************Animal*************************/" << std::endl;

    std::cout << "this is the type of animal : " << myAnimal->getType() << std::endl;
    std::cout << "this is the type of animal : " << myDog->getType() << std::endl;
    std::cout << "this is the type of animal : " << myCat->getType() << std::endl;

    myAnimal->makeSound();
    std::cout << std::endl;
    myDog->makeSound();
    std::cout << std::endl;
    myCat->makeSound();
    std::cout << std::endl;

    delete myAnimal;
    delete myCat;
    delete myDog;
   
    // std::cout << "/************************non-Animal*************************/" << std::endl;
    // {
    //     const WrongAnimal* meta = new WrongAnimal();
    //     const WrongAnimal* wcat = new WrongCat();

    //     std::cout << "this is the type of animal : \t" << wcat->getType() << " " << std::endl;
    //     wcat->makeSound();
    //     meta->makeSound();
        
    //     delete wcat;
    //     delete meta;

    // }

    return 0;
}