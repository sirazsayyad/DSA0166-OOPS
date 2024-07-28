#include <iostream>
 #include <stdlib.h>
#include <string.h>
using namespace std;
 class string
{
private:
char str[ 20 ]; public:
string( )
{
str[ 0 ] = '\0';
}
string( char * s )
{
strcpy( str, s );
}
string( int a )
{
itoa( a, str, 10 );
}
operator int( )
{
int i = 0, l,
ss = 0,
k = 1;
l = strlen( str ) - 1; while( l >= 0 )
{
ss = ss + ( str[ l ] - 48 ) * k; l--;
k *= 10;
}
return ( ss );
}
void displaydata( )
{
cout << str;
}
} ;
int main( )
{
string s1 = 123; cout << endl << "s1="; s1.displaydata( );
s1 = 150;
cout << endl << "s1="; s1.displaydata( ); string s2 ( "123" ); int i = int( s2 );
cout << endl << "i=" << i; string s3 ( "456" );
i = s3;
cout << endl << "i=" << i;
}