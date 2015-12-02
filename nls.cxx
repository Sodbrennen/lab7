#include <iostream>
#include <cmath>

using namespace std;

void f(const double* const y, double* k, double eta,double zw){
//   zw = y[0];  
  k[0] = y[1];
  k[1] = (eta - y[0]*y[0])*y[0];
//   return y;
}

int main(){
  double y[2];
  double zw;
  double dx = 0.1;
  double eta = 0.5;
  double k1[2];
  double k2[2];
  double k3[2];
  double ys[2];

  y[0] = 0.00001;
  y[1] = sqrt(eta)*y[0];
  
  
  for(int i=0;i*dx < 100; i++){
     f(y,k1,eta,zw);
     
     ys[0] = y[0] + dx*0.5*k1[0];
     ys[1] = y[1] + dx*0.5*k1[1];
     
     
     f(ys,k2, eta, zw);
     
     ys[0] = y[0] - dx*k1[0] + dx*(2)*k2[0];
     ys[1] = y[1] - dx*k1[1] + dx*(2)*k2[1];
     
     f(ys,k3, eta, zw);
     
     y[0] = y[0] + (1./6)*dx*(k1[0] + 4*k2[0] + k3[0]);
     y[1] = y[1] + (1./6)*dx*(k1[1] + 4*k2[1] + k3[1]);
     
     cout << i*dx << "\t" << y[0] << "\t" << sqrt(2*eta)/cosh(sqrt(eta)*(i*dx-17.2)) <<  endl;
  }
  //  cout << k1[0] << endl;
  //  cout << k2[0] << endl;
  //  cout << k3[0] << endl;
    
  
}
