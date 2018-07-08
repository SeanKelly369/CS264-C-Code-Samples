/**
 * file: animals.cpp
 * project: b
 * author: gregcousin (gregcousin126@gmail.com)
 * created: Wednesday, 27th December 2017 6:12:04 pm
 * modified: Saturday, 30th December 2017 3:27:40 pm
 * filepath: /Users/gregcousin/Library/Mobile Documents/com~apple~CloudDocs/iCloud/csclass/muquentin/anifight/b
 * comment: comment
 */

#include <iostream>
#include <time.h>
using namespace std;

time_t t;

srand((unsigned) time(&t));

class Animal; // this is needed since it is declaired in our weapon class!!!!!

class Weapon {
public:
  Weapon(); // does nothing; default 
  Weapon(int damage);
  // Taking parametre animal from class
  // Animal and adding variable enemy
  void hit(Animal& enemy); // it was looking for animal class
private:
  int damage;
};

class Animal {
public:
  Animal(int health, Weapon weapon);
  bool isAlive();
  void animAttach(Animal& hitenemy); 
  void looseHealth(int damage);
private:
  int health;
  Weapon weapon;
};

// Animal constructor
Animal::Animal(int health, Weapon weapon) {
  this->health = health;
  this->weapon = weapon;
  }

Weapon::Weapon() { damage = 0; } // Default damage
void Animal::animAttach(Animal& hitenemy) {
  this->weapon.hit(hitenemy);
}

bool Animal::isAlive() {
  if (health > 0) {
    return true;
  } else {
    return false;
  }
}

Weapon::Weapon(int damage) { 
  this->damage = damage; 
  }

void Weapon::hit(Animal& enemy) {
  if (rand() % 2 == 0) {
    enemy.looseHealth(damage);
    cout << "enemy has been hit" << endl;
  } else {
    cout << "you missed the enemy" << endl;
  }
}

void Animal::looseHealth(int damage) {
  health = health - damage;
  cout << "you've been hit, health status: " << health << endl;
}

int main() {
  srand(time(NULL));
  Weapon bigWeapon(10);
  Animal Monkey(200, bigWeapon);
  Weapon LazerWeapon(20);
  Animal Baboone(200, LazerWeapon); 
  Monkey.animAttach(Baboone); 
  Monkey.animAttach(Baboone); // creating copys keep the same value of health
  Monkey.animAttach(Baboone); // adding pass by refference keeps the count of the health without calling it again
  Monkey.animAttach(Baboone); 
}

// 27.50
// when passing an object by 
// value you create a copy of this object
