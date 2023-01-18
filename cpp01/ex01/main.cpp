
#include "Zombie.h" // assumes there is a header file for the Zombie class

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N]; // single allocation of N Zombie objects
    for (int i = 0; i < N; i++) {
        horde[i].setName(name); // initializing each zombie with the given name
    }
    return horde;
}

void testZombieHorde() {
    int N = 5;
    std::string name = "Zombie";
    Zombie* horde = zombieHorde(N, name);
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    delete[] horde; // deallocating the memory for the horde
}

int main() {
    testZombieHorde();
    return 0;
}
