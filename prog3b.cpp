#include <iostream>
#include <math.h>
int main(){
	double sum = 0;
	double eps;
	std::cin >> eps;
	int i = 1;
	std::cout << eps << std::endl;
	while (1.0/(i*i) > eps){
		sum += 1.0/(i*i);
		i++;
	}
	double erg = (M_PI*M_PI)/6;
	
	std::cout << sum /erg <<std::endl;
	return 0;
}
