#include<iostream> 
#include<conio.h> 
class code
{
int id; public:
code(){} code(int a)
{
id = a;
}
code(code & x)
{
id = x.id;
}
void display(void)
{
std::cout<<id;
}
};
int main()
{
code A(100); 
code B(A); 
code C = A; 
code D;
D = A;
std::cout<<"\n id of A:";
 A.display();
 std::cout<<"\n id of B:"; 
 B.display(); 
std:: cout<<"\n id of C:"; 
 C.display(); 
 std::cout<<"\n id of D:";
  D.display();
return 0;
}