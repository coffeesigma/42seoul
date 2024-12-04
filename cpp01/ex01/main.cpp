#include "Zombie.hpp"

const int ZOMBIE_NUM = 10;

int main() {
	Zombie* zombies = zombieHorde(ZOMBIE_NUM, "zombie");

	for (int i = 0; i < ZOMBIE_NUM; i++) {
		std::cout << "[" << i << "]: ";
		zombies[i].announce();
	}
	delete[] zombies;

	// system("leaks moarbrainz");
	return 0;
}