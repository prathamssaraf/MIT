#include<iostream>
#include<string>  
#include<cmath>
using namespace std;

int findComplementint(int n) {
   int bit_count = floor(log2(n))+1;
   int ones = ((1 << bit_count) - 1);
   return ones ^ n;
}
int findComplement(int n) {
	int decimal, binary = 0, remainder, product = 1;
	decimal = n;
   while (decimal != 0) {
    remainder = decimal % 2;
    binary = binary + (remainder * product);
    decimal = decimal / 2;
    product *= 10;
  }
  return binary;
}


int main()
{
	int a[4][4]={{1,2,3,4},{6,5,8,3},{ 2,4,10,1},{9,1,2,5}};
	int b[4][4]={{1,2,3,4},{6,5,8,3},{ 2,4,10,1},{9,1,2,5}};
	int c[4][4]={{1,2,3,4},{6,5,8,3},{ 2,4,10,1},{9,1,2,5}};
	
	   
	   for(int i=1;i<3;i++){
	   	for(int j=1;j<3;j++){
	   		 int n = a[i][j];
	   		 c[i][j] = findComplementint(n);
	   		 
		   }
	   }
	   for(int i=1;i<3;i++){
	   	for(int j=1;j<3;j++){
	   		 int n = c[i][j];
	   		 b[i][j] = findComplement(n);
	   		 
		   }
	   }
	   
	   for(int i=0;i<4;i++){
	   	for(int j=0;j<4;j++){
	   		cout<<b[i][j]<<"  ";
		   }
			cout<<endl;
	   }
	   cout<<endl;
	   for(int i=0;i<4;i++){
	   	for(int j=0;j<4;j++){
	   		cout<<c[i][j]<< "  ";
		   }
			cout<<endl;
	   }
	return 0;
}


