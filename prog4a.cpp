#include <iostream>
#include <cmath>

int main()
{
  int k = 30;
  double e = std::exp(1.0);
  double *vr = new double[31];
  vr[0] = (e-1)/e;
  double b = 0.5*( 1/(e*(k+1)) + 1/(e*k));
  double c = 10E6;

  std::cout << "Index \tVorwärts \tRückwärts(gut)\tRückwärts(schlecht)" << std::endl;
  for(int i = 1; i <= k; i++){
    vr[i] = 1-i*vr[i-1];
  }

  for(int i = k; i >= 0; i--){
    b = (1-b)/(i+1);
    c = (1-c)/(i+1);
    std::cout << i << "\t" << vr[i] << "  \t" << b << "  \t" << c << std::endl;
  }
  
  return 0;
}
