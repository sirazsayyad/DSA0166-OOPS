#include<iostream>
#include <fstream>
using namespace std;
int main( )
{
struct employee
{
char name[ 20 ]; int age;
float basic; float gross;
} ;
employee e;
char ch = 'Y'; ofstream outfile;
outfile.open( "EMPLOYEE.DAT", ios::out | ios::binary ); while( ch == 'Y' )
{
cout << endl << "Enter a record";
cin >> e.name >> e.age >> e.basic >> e.gross; outfile.write( ( char * )&e, sizeof( e ) ); cout << endl << "Add Another Y/N";
cin >> ch;
}
outfile.close( ); ifstream infile;
infile.open( "EMPLOYEE.DAT", ios::in | ios::binary );
while( infile.read( ( char * )&e, sizeof( e ) ) )
{
cout << endl << e.name << "\t" << e.age << "\t" << e.basic << "\t"
<< e.gross;
}
}