#include <new>
#include <iostream>
using namespace std;

class Rectangle{
	
	int width;
	int height;
	
public:
	Rectangle(int w, int h){
		
		width = w;
		height = h;
		cout << "Constructing " << width <<
		" by " << height << " rectangle.\n";
	}
		
	~Rectangle(){
		cout << "Destructing " << width <<
			" by " << height << " rectangle.\n";
	}
	
	int area(){
		return width * height;
	}
};

int main(int argc, char** argv)
{
	Rectangle *p = new Rectangle(10, 8);
	
	cout << "Area is " << p-> area();
	
	cout << "\n";
	
	delete p;
	
	return 0;
}







