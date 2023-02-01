#include<iostream>
#include<string>  
using namespace std;

int main()
{
    string a[2][4]={{ "p","c","a","p"},{"e","x","a","m"}};
    int b[2][4]={{ 1,2,4,3},{2,4,3,2}};
   string p;
   
   for(int i=0;i<2;i++){
   	for(int j=0;j<4;j++){
   		for(int k=0;k<b[i][j];k++){
   			p = p + a[i][j];
		   }
	   }
   }
	cout<<p;
	

	return 0;
}


