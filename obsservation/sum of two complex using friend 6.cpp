#include<iostream>
 #include<conio.h> 
 class complex
{
float x; float y;
public:
void input(float real, float img)
{
x=real; y=img;
}
friend complex sum(complex, complex);
 void show(complex);
};
complex sum(complex c1, complex c2)
{
complex c3;
c3.x = c1.x + c2.x; c3.y = c1.y + c2.y;
 return (c3);
}
void complex :: show(complex c)
{
std::cout<<c.x<<"+i"<<c.y<<"\n";
}
int main()
{
complex A,B,C; A.input(3.1, 5.65);
B.input(2.75, 1.2);
C=sum(A,B);
std::cout<<"A="; 
A.show(A);
std:: cout<<"B="; 
 B.show(B); 
std:: cout<<"C="; C.show(C);
return 0;
}