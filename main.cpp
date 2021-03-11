#include<iostream>
#include<cmath>
#define _USE_MATH_DEFINES
using namespace std;
const double pi=M_PI;
int main()
{
const double a1=0.319381530, a2=-0.356563782, a3=1.781477937,
a4=-1.821255978, a5=1.330274429; // define all constants a(i)
double X=0, x=0; // X is the random variable, & x its absolute value
double k=0;
double N, CDF, n;
cout<<M_PI<<"PI";
cout<< "Enter the value of the random variable X"<<endl;
/* upper limit of integral*/
cin>>X;
x=abs(X); //we set x to be the absolute value of the R.V. X
k=1/(1+0.2316419*x);
n=(1/sqrt(2*pi))*exp(-0.5*x*x);
N=1-n*(a1*k+a2*k*k+a3*pow(k,3)+a4*pow(k,4)+a5*pow(k,5));
CDF=N;
if (X<0) /* we calculate for +ve X and then use the symmetry property
of the distribution to obtain the CDF for –ve values*/
CDF=1-N;
cout<< CDF <<endl; //output value of N(x)
return 0;
}