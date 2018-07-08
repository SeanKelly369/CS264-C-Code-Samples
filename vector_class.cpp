#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class customer{
public:
	customer(string n, int a):name(n), age (a){};
	string name; int age;
};

class compare_cust{
public:
	bool operator()
	(const customer& cl, const customer& c2)
	{
		return c1.age > c2.age;
	};
};

int main(){
	vector<customer> c;
	c.push_back(customer("Jean", 34));
	c.push_back(customer("John", 22));
	c.push_back(customer("Pat", 50));
	sort(c.begin(), c.end(), compare_cust());
	for(vector<customer>::iterator i=c.begin(); i!=c.end(); ++i)
		cout << i->name << ' ' << i->age << endl;
}
