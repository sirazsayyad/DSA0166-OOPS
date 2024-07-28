#include<iostream>
using namespace std;
class base1{
	public:
		void show(){
			cout<<"base1 show function"<<endl;
		}
};
class base2{
	public:
		void display(){
			cout<<"base2 display funtion"<<endl;
		}
};
class derived:public base1,public base2{	
};
int main(){
	derived d;
	d.show();
	d.display();
	return 0;
	}