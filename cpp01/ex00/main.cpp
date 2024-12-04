#include "Zombie.hpp"

int main() {
	Zombie* heapZombie = newZombie("newZombie");
	heapZombie->announce();

	randomChump("randomChump");
	
	Zombie* heapZombie2 = newZombie("newZombie2");
	heapZombie2->announce();

	randomChump("randomChump2");
	
	delete(heapZombie);
	delete(heapZombie2);

	// system("leaks brainz");
	return 0;
}