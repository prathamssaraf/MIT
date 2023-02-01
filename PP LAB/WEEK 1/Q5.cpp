#include<iostream>
#include<string>  
using namespace std;

int main()
{
	
	string a,b,c;
	cout<<"enter the str1:";
	cin>>a;
	cout<<"enter the str2:";
	cin>>b;	
	for(int i=0;i<a.length();i++){
		c = c + a[i] + b[i];	
	}
	cout<<c;
	return 0;
}


