#include <iostream>
#include <string>

class Zombie {
public:
  Zombie(const std::string& name) : name_(name) {}
  ~Zombie() { std::cout << name_ << ": destroyed!" << std::endl; }

  void announce() {
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
  }

private:
  std::string name_;
};

Zombie* newZombie(std::string name) {
  // Create a new zombie on the heap
  return new Zombie(name);
}

void randomChump(std::string name) {
  // Create a new zombie on the stack
  Zombie zombie(name);
  zombie.announce();
}

int main() {
  Zombie* foo = newZombie("Foo");
  randomChump("Bar");

  // Don't forget to delete the zombie when you're done with it
  delete foo;

  return 0;
}


/*
This code defines a Zombie class with a single private string attribute name_ and two member functions: announce and the destructor. The announce function prints a message with the name of the zombie, and the destructor prints a message when the zombie is destroyed.

The newZombie function creates a new zombie on the heap using the new operator and returns a pointer to it. The randomChump function creates a new zombie on the stack and immediately calls its announce function.

In the main function, we create a zombie on the heap using the newZombie function and a zombie on the stack using the randomChump function. When you are done with a zombie that was created on the heap, you must delete it to free the memory it occupies, using the delete operator. Zombies created on the stack are automatically destroyed when they go out of scope.

The actual point of this exercise is to understand the difference between allocating objects on the stack and the heap, and the implications of each choice. Allocating an object on the stack is generally faster and more efficient, because the memory is automatically managed by the compiler. However, objects on the stack have a fixed size and can only be accessed within the scope in which they were created. Allocating an object on the heap allows you to create objects of any size and access them from anywhere in your code, but it requires manual memory management and can be slower.

I hope this helps! Let me know if you have any questions.
*/