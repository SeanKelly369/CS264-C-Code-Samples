#include <iostream>
using namespace std;

class Alan{
public:
    Alan() { cout << "Alan creation \n";}
    virtual ~Alan() { cout << "Alan destruction\n";}
};

class Barry: public Alan{
public:
    Barry() { cout << "Barry creation\n";}    
    virtual ~Barry(){ cout << "Barry destruction\n";}
};

class Carl: public Alan{
public:
    Carl() { cout << "Carl creation\n";}    
    virtual ~Carl(){ cout << "Carl destruction\n";}
};

int main()
{
    Alan a;
    Barry b;
    Carl c;
    
    cout << "Hello world\n";
}




