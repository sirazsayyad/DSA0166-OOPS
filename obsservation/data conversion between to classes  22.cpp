#include <iostream> 
#include <stdlib.h>
#include <string.h>
using namespace std;
class date
{
private:
char dt[ 9 ]; public:
date( )
{
dt[ 0 ] = '\0';
}
date( char * s )
{
strcpy( dt, s );
}
void displaydata( )
{
cout << dt;
}
} ;
class dmy
{
private:
int day,
mth, yr;
public:
dmy( )
{
day = mth = yr = 0;
}
dmy( int d, int m, int y )
{
day = d; mth = m; yr = y;
} ;
operator date( )
{
char temp[ 3 ], str[ 9 ]; itoa( day, str, 10 ); strcat( str, "/" ); itoa( mth, temp, 10 );

strcat( str, temp ); strcat( str, "/" ); itoa( yr, temp, 10 ); strcat( str, temp ); return ( date( str ) );
}
void displaydata( )
{
cout << day << "\t" << mth << "\t" << yr;
}
} ;
int main( )
{
date d1;
dmy d2 ( 17, 11, 94 );
d1 = d2;
cout<<endl<<"d1="; d1.displaydata( );
cout << endl << "d2="; d2.displaydata( );
}