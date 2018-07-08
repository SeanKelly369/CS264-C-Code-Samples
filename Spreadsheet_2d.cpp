#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Cell
{
    string text;
    int number;
        // Will add in more..  float, double etc.
};

void print (const vector<vector<Cell>>& Spreadsheet)
{
    for (const auto & row : Spreadsheet)
    {
        for (const auto & cell : row)
        {
            cout << cell.number << ' ';
        }
        cout << '\n';
    }

}

void init(vector<vector<Cell>>& Spreadsheet)
{
    for (size_t i=0; i<Spreadsheet.size(); i++)
    {
        for (size_t j=0; j<Spreadsheet[i].size()  ; j++)
        {
            Spreadsheet[i][j].number = 7;
        }
    }

}

int main()
{
    const int Spreadsheet_Width  = 53;
    const int Spreadsheet_Height = 76;
    
    vector<vector<Cell>> Spreadsheet(Spreadsheet_Height, vector<Cell>(Spreadsheet_Width));  
        
    init(Spreadsheet);  
    print(Spreadsheet);     
}
