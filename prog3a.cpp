#include <iostream>


int main(){
	double eps = 1;
	double prev = eps;
	while (eps +1 != 1){
		prev = eps;
		eps = eps/2;
	}
	std::cout << prev << std::endl;
	return 0;
}
