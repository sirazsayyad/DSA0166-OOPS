#include<iostream>
#include <fstream> 
using namespace std;
int main( )
{
	string source;
char cource[ 67 ],
target[ 67 ]; char ch;
std::cout << std::endl << "Enter source filename"; 
std::cin >> source;
std::cout << endl << "Enter target filename"; 
std::cin >> target;
ifstream infile ( source ); ofstream outfile ( target );
while( infile )
{
infile.get( ch ); outfile.put( ch );
}
}