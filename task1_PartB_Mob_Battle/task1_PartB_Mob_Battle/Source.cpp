#include <iostream>
#include <chrono>


//define a structure called mob with 4 variables (string for name and attack_Skill and integer for health and damage_Rating)
struct mob {
	std::string name;
	int health;
	int damage_Rating;
	std::string attack_Skill;
};

void battle(mob &one, mob &two); //define the void battle with two parameters (mob (one) and mob (two))

//main body
int main() {

	srand((unsigned)time(NULL)); //set the seed for randomly generating numbers to the current time

	//create a mob called skeleton with its unique stats
	mob skeleton;
	skeleton.name = "skeleton";
	skeleton.health = 100;
	skeleton.damage_Rating = 6;
	skeleton.attack_Skill = "bash";

	//create a mob called slime with its unique stats
	mob slime;
	slime.name = "slime";
	slime.health = 150;
	slime.damage_Rating = 4;
	slime.attack_Skill = "bounce";

	//loop until one or more mobs are dead
	while ((skeleton.health > 0) && (slime.health > 0)) {
		battle(skeleton, slime); //call the function battle with the two mobs slime and skeleton
	}
	
}

//main body of function battle
void battle(mob &one, mob &two) {
	//set damage and round vaiables
	int damage = 0;
	static int round = 1;

	std::cout << "round: " << round << "\n"; //print the current round
	damage = one.damage_Rating * (1 + rand() % 5); //randomly generate the damage (still influenced by the damage_Rating of that mob)
	std::cout << one.name << " uses " << one.attack_Skill << " and hits " << two.name << " for " << damage << " damage" << "\n"; //print the outcome of the attack
	two.health -= damage; //adjust the health of the attacked mob

	//if the health of the attacked mob is leass than 0 than set it to 0
	if (two.health < 0) {
		two.health = 0;
	}

	std::cout << one.name << "s health: " << one.health << "\n" << two.name << "s health: " << two.health << "\n"; //print the health of both mobs
	//std::cout << "\n----------------------------------\n\n";
	std::cout << "\n";
	damage = two.damage_Rating * (1 + rand() % 5); //randomly generate the damage (still influenced by the damage_Rating of that mob)
	std::cout << two.name << " uses " << two.attack_Skill << " and hits " << one.name << " for " << damage << " damage" << "\n"; //print the outcome of the attack
	one.health -= damage; //adjust the health of the attacked mob

	//if the health of the attacked mob is leass than 0 than set it to 0
	if (one.health < 0) {
		one.health = 0;
	}

	std::cout << one.name << "s health: " << one.health << "\n" << two.name << "s health: " << two.health << "\n"; //print the health of both mobs
	std::cout << "\n----------------------------------\n\n"; //seperate the current round from the next one
	round++; //add one to the variable round

	//if at least one mob has died then print the outcome of the battle
	if ((one.health <= 0) || (two.health <= 0)) {
		if (one.health == two.health) {
			std::cout << "draw\n";
		}
		else if (one.health > 0) {
			std::cout << "skeleton wins\n";
		}
		else {
			std::cout << "slime wins\n";
		}
	}
}
