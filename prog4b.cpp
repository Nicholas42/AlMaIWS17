#include <iostream>
#include <cmath>

int main()
{
  // a << b = a * 2^b
  float sum1 = 1;
  float sum2 = 1;

  std::cout << "Exp\tNaiv\tBesser\tGamma"<<std::endl;
  
  for(int i = 1; i <= 30; i++){
    std::cout << i << "\t" << sum1 << "\t" << sum2 << "\t" << sum2 -i*std::log((float)2) << std::endl;

    float tmp = 0;
    for(int j = (1<<i); j<(1<<(i+1)); j++){
      sum1 += 1/((float) j);
      tmp += 1/((float) j);
    }
    sum2 += tmp;
  }

  //γ = 0,5772156649
}
