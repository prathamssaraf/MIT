#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int main()
{
    clock_t start = clock();

    int a,b,c,d;
    int m = 0;

    cout<<"Enter the number A:";
    cin>>a;
    cout<<"Enter the number B:";
    cin>>b;
    cout<<"Enter the operation to be performed : 1 - addition , 2 - subtraction, 3 - multiplication, 4 - division";
    cin>>c;

    if(c==1){
        d = a+ b;
    }else if(c == 2){
        d = a-b;
    }else if(c == 3){
        d = a*b;
    }else if(c == 4){
        d = a/b;
    }

    cout<<d<<endl;

    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout<<"Time taken by function: "<<time_taken<<" seconds"<<endl;

    return 0;
}
