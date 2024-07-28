#include<iostream> 
const int m=50;
class ITEMS
{
int itemCode[m];
 float itemPrice[m]; 
 int count;
public:
void CNT(void){count=0;}
 void getitem(void);
void displaySum(void); 
void remove(void);
void displayItems(void);
};
void ITEMS :: getitem(void)
{
std::cout<<"Enter item code:"; 
std::cin>>itemCode[count]; 
std::cout<<"Enter Item cost:"; 
std::cin>>itemPrice[count]; 
count++;
}
void ITEMS :: displaySum(void)
{
float sum=0;
for(int i=0;i<count;i++) 
sum=sum+itemPrice[i];
std::cout<<"\n Total Value:"<<sum<<"\n";
}
void ITEMS :: remove(void)
{
int a;
std::cout<<"Enter Item Code:"; 
std::cin>>a;
for(int i=0;i<count;i++) 
if(itemCode[i] == a)
itemPrice[i]=0;
}
void ITEMS :: displayItems(void)
{
std::cout<<"\n Code Price:\n";
for(int i=0;i<count;i++)
{
std::cout<<"\n"<<itemCode[i]; 
std::cout<<" "<<itemPrice[i];
}
std::cout<<"\n";
}
int main()
{
ITEMS order;
 order.CNT();
  int x;
do
{
std::cout<<"\n You can do the following:";
std::cout<<"Enter appropriate number:\n"; 
std::cout<<"\n1 : Add an Item";
std::cout<<"\n2 : Display Total Value"; 
std::cout<<"\n3 : Delete an Item"; 
std::cout<<"\n4 : Display all items";
std:: cout<<"\n5 : Quit";
std::cout<<"\n\n What is your option?  ";
std:: cin>>x;
switch(x)
{
case 1 : order.getitem(); 
break;
case 2 : order.displaySum();
 break;
case 3 : order.remove(); 
break;
case 4 : order.displayItems(); 
break;
default : std::cout<<"Error in input";
}
}while(x!=5); return 0;
}