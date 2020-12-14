#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
void CreateBIN(const char* fname)
{
    ofstream f(fname, ios::binary);

    int x;

    for (int i = 0; i < 20; i++)
    {
        x = (2 * (20 * 1.)) * rand() / RAND_MAX - (20 * 1.);
        f.write((char*)&x, sizeof(x));
    }
}

void PrintBIN(char* fname) 
{
    cout << "file: ";
    ifstream fin(fname, ios::binary); 
    char c; 
    while (fin.read((char*)&c, sizeof(c))) 
    {
        cout << c << endl; 
    }
    cout << endl;
}
void ProcessBIN1(char* fname, char* gname) 
{ 
    ifstream f(fname, ios::binary); 
    ofstream g(gname, ios::binary); 
    char c; 
    while (f.read((char*)&c, sizeof(c))) 
    {
        if (c%2!=0 && c>(c-1))
            g.write((char*)&c, sizeof(c)); 
        if (c%2==0 && c<(c-1))
            g.write((char*)&c, sizeof(c));
    }
}
int main()
{
    srand((unsigned)time(NULL));
    char fname[100];
    cout << "enter file name 1: "; cin >> fname;
    CreateBIN(fname);
    PrintBIN(fname); 
    char gname[100]; 
    cout << "enter file name 2: "; cin >> gname;
    ProcessBIN1(fname, gname);
    PrintBIN(gname);
    return 0;
}