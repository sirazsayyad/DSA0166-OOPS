#include<iostream>
 #include<conio.h>
  class employee
{
char name [30]; 
float age;
public:
void getdata(void); 
void putdata(void);
};
void employee :: getdata(void)
{
std::cout<<"Enter Name:"; 
std::cin>>name; 
std::cout<<"Enter Age:";
 std::cin>>age;
}
void employee :: putdata(void)
{
std::cout<<"Name:"<<name<<"\n";
std:: cout<<"Age: "<<age<<"\n";
}
const int size=3; int main()
{
employee manager[size];
 for(int i=0; i<size; i++)
{
std::cout<<"\n Details of manager"<<i+1<<"\n"; 
manager[i].getdata();
}
std::cout<<"\n";
for(int i=0; i<size; i++)
{
std::cout<<"\n Manager"<<i+1<<"\n";
 manager[i].putdata();
}
return 0;
}