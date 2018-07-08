#include <iostream>
using namespace std;

class Enemy
{
	public:
		virtual void attack()
		{			
		}
};

class Ninja: public Enemy
{
	public:
		void attack()
		{
			cout << "Ninja attack!" << endl;
		}
};

class Monster: public Enemy
{
	public:
		void attack()
		{
			cout << "Monster attack!" << endl;	
		}	
};



int main (int argc, char** argv)
{
	Ninja n;
	Monster m;
	Enemy *enemy1 = &n;				//When ninja is of type enemy, this is valid
	Enemy *enemy2 = &m;				//Anything that an enemy can do the monster can do
	enemy1 -> attack ();			//Ninja is just a more specific type of enemy
	enemy2 -> attack ();			//Every enemy has setAttackPower
	
	
	return 0;
}

