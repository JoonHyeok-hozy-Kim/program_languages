#include "04_03_copy_costruuctor_and_destructor.h"
#include <iostream>
#include <string.h>

class Marine {

	int hp;							// the health of the marine unit
	int coord_x, coord_y;			// x and y coordinates of the marine unit
	int damage;						// the damage that the marine can give
	bool is_dead;
	char* name;						// Added for Destructor test! (Possible memory leak if not destructed)

public:
	Marine();						// Default constructor
	Marine(int x, int y);			// Create Marine at (x, y)
	Marine(int x, int y, const char* marine_name);

	~Marine();						// Destructor

	int attack();					// Return damage value
	void get_damaged(int received_damamge);
	void move(int x, int y);

	void show_status();				// Show current status of the marine

};

Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	std::cout << "You wanna piece of me, boy?" << std::endl;
}

Marine::Marine(int x, int y) {
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
	std::cout << "You wanna piece of me, boy?" << std::endl;
}

Marine::Marine(int x, int y, const char* marine_name) {
	name = new char[strlen(marine_name) + 1];
	strcpy(name, marine_name);
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
	std::cout << name << " : You wanna piece of me, boy?" << std::endl;
}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::attack() {
	return damage;
}

void Marine::get_damaged(int received_damage) {
	if (hp < received_damage) {
		hp = 0;
		is_dead = true;
		return;
	}
	else hp -= received_damage;
}

void Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : (" << coord_x << ", " << coord_y << ") " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

Marine::~Marine() {
	std::cout << name << "'s Destructor called!" << std::endl;
	if (name != NULL) {
		delete[] name;		// delete in order to prevent memory leak.
	}
}



void destructor_test() {

	Marine* squad[12];
	const char* temp_prefix = "marine";
	char suffix = 'A';

	for (int i = 0; i < 12; i++) {
		//squad[i] = new Marine(i, 0);

		char temp_name[10];
		strcpy(temp_name, temp_prefix);
		strcat(temp_name, &suffix);
		squad[i] = new Marine(i, 0, temp_name);
		suffix++;
	}

	std::cout << "----------------------------------" << std::endl;
	for (int i = 0; i < 12; i++) {
		squad[i]->show_status();
	}
	std::cout << "----------------------------------" << std::endl;

	for (int i = 0; i < 6; i++) {
		squad[i]->move(10, 10);
	}

	squad[11]->get_damaged(squad[10]->attack());

	std::cout << "----------------------------------" << std::endl;
	for (int i = 0; i < 12; i++) {
		squad[i]->show_status();
	}
	std::cout << "----------------------------------" << std::endl;

	
	for (int i = 0; i < 12; i++) {
		delete squad[i];		// free memory!
	}
}


class PhotonCannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;
	char* name;

public:
	PhotonCannon(int x, int y);
	PhotonCannon(const PhotonCannon& pc);
	PhotonCannon(int x, int y, const char* cannon_name);
	~PhotonCannon();

	void show_status();
};

PhotonCannon::PhotonCannon(int x, int y) {
	std::cout << "Normal Constructor called." << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
	name = NULL;
}

/* Copy Constructor starts */
PhotonCannon::PhotonCannon(const PhotonCannon& pc) {		// constant reference of a class
	std::cout << "Copy Constructor called." << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;

	/* character should be hard copied! */
	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);
}
/* Copy Constructor ends */

PhotonCannon::PhotonCannon(int x, int y, const char* cannon_name) {
	std::cout << "Normal Constructor called." << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = new char[strlen(cannon_name) + 1];
	strcpy(name, cannon_name);
}

PhotonCannon::~PhotonCannon() {
	if (name) delete[] name;
}

void PhotonCannon::show_status() {
	std::cout << "---------------\n" << "Photon Cannon " << std::endl;
	std::cout << " Name : " << name << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}


void copy_constructor_test() {

	PhotonCannon base_cannon(2, 3, "ccc");
	PhotonCannon* cannons[10];

	base_cannon.show_status();

	for (int i = 0; i < 10; i++) {
		cannons[i] = new PhotonCannon(base_cannon);
	}

	for (int i = 0; i < 10; i++) {
		cannons[i]->show_status();
	}
}