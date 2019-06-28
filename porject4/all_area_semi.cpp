//include necessary libraries
#include <iostream> //standard library for i/o
#include <string>   // always include this when you use the string class
#include <vector>
#include <math.h>       /* pow */
using namespace std;
bool correctInput(double a,double  b,double c){
    if(a+b <= c){
        return false;
    }
    if(a+ c <= b){
        return false;
    }
    if(b+c <= a){
        return false;
    }
    return true;
    
}
void Compute(double a,double b,double c,double *area,double *s )
{
    *s =  (a + b + c) / 2;
    *area = ( *s - a) * (*s-b) * (*s - c);
    *area = pow(*s * *area,0.5);
}
int main( )
{
    //declare variables a, b, c,area, and semiperimeter
    double a,b,c,area = 1.0, semiperimeter = 0.0;
    string yesNo = "y";
    //convert all cout doubles to the nearest hundred
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.setf(ios::fixed);
    //begin while loop
    while (yesNo == "y")
    {   cout<<"enter side a: "<<endl;
        cin>> a;
        cout<<"enter side b: "<<endl;
        cin>> b;
        cout<<"enter side c: "<<endl;
        cin>> c;
        if(correctInput( a, b, c) == 0){    
        cout<<"The data entered is not valid"<<endl;
        cout<<"Do you wish to repeat the process? y/n"<<endl;
        cin>> yesNo;
        if(yesNo == "y"){
            continue;
        }
        break;
        }
        //call Computer   
        Compute( a, b, c, &area, &semiperimeter );

        cout<<" Area: "<<endl;
        cout<<area<<endl;
        cout<<" semiperimeter: "<<endl;
        cout<<semiperimeter<<endl;
        cout<<"Do you wish to repeat the process? y/n"<<endl;

        cin>> yesNo;
    }
    //end while loop

    return 0;
}