#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;





int main(){

const int N=50;  
const double lambda = -0.5;
double yF[N], yB[N], yM[N];
yF[0]= 1;
yB[0]= 1;
yM[0]=1;
const double dt=5*log(1./2)/(lambda*(N-1));                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           


for(int i=0; i<N-1; i++) {
  
  yF[i+1]=yF[i]+dt*yF[i]*lambda;
  
  yB[i+1]=yB[i]/(1-dt*lambda);
  
  yM[i+1]=(yM[i]+lambda*dt*yM[i]/2)/(1-lambda*dt/2);
  
}



ofstream Euler ("Euler.dat");
for(int i=0; i<N; i++) {

  Euler<<dt*i<<"\t"<<yF[i]<<"\t" <<yB[i]<< "\t"<< yM[i]<< endl; 
}
Euler.close();


return 0;
}