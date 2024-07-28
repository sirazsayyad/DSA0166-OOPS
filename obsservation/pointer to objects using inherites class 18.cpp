#include<iostream> 
using namespace std;
class BC
{
public:
int b;
void show()
{
cout<<"b="<<b<<"\n";
}
};
class DC : public BC
{
public:
int d;
void show()
{
}
};
int main()
{
	int b,d;
cout<<"b="<<b<<"\n"
<<"d="<<d<<"\n";
BC *bptr;
BC base;
bptr = &base;
bptr->b = 100;
cout<<"bptr points to base object\n"; bptr->show ();
DC derived;
bptr = &derived; bptr->b = 200;
cout<<"bptr now points to derived object\n"; bptr->show ();
DC *dptr;
dptr = &derived; dptr->d = 300;
cout<<"dptr is derived type pointer\n"; dptr->show ();
cout<<"Using ((DC *)bptr)\n"; ((DC *)bptr)->d = 400;
((DC *)bptr)->show ();
return 0;
}