#include <iostream>
using namespace std;

class Spreadsheet
{
	public:
		Spreadsheet(int inWidth, int inHeight);
		virtual ~Spreadsheet();
		void setCellAt(int x, int y, const Spreadsheet &cell);
		Spreadsheet getCellAt(int x, int y);
		
	protected:
		bool inRange(int val, int upper);
		void copyFrom(const Spreadsheet &src);
		
		int mWidth, mHeight;
		Spreadsheet** mCells;
		
	private:
		Spreadsheet(const Spreadsheet &src);
		Spreadsheet & operator=(const Spreadsheet &rhs);
	
};

int main(int argc, char** argv)
{
	Spreadsheet sc;
	sc.setCellAt(3,4);
	
	cout << sc << endl;
	return 0;
}



