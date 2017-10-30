#include <iostream>

void teilA (){
  double x,y;
  std::cout << "x: ";
  std::cin >> x;
  std::cout << "y: ";
  std::cin >> y;
  if(x > y){
    std::cout << "Das Maximum ist "<< x<<std::endl;
  }
  if(y > x){ // Bei x=y wird nichts ausgegeben.
      std::cout << "Das Maximum ist " << y << std::endl;
  }
  // man muss hier kein else benutzen, weil die Fälle
  // sich gegenseitig ausschließen
  
  if(x*y > 100){
    std::cout << "Die Summe ist " << (x+y) << std::endl;
  }
  if(-2 < (x-y) && (x-y) < 2){ // entspricht |x-y| < 2
    if(x < y){
      std::cout << "Das Minimum ist " << x << std::endl;
    }
    else{
      std::cout << "Das Minimum ist " << y << std::endl;
    }
  }
}


void teilB(){
  unsigned int m,n;
  std::cout << "m: ";
  std::cin >> m;
  std::cout << "n: ";
  std::cin >> n;
  if(m%n == 0){
    std::cout << "n teilt m." << std::endl;
  }
  if(n%m == 0){
    std::cout << "m teilt n." << std::endl;
  }
  unsigned int q,r;
  if(n > m){
    r = n%m;
    q = n/m;
    std::cout << "Es gilt " << n << " = " << q << " * " << m << " + " << r << std::endl;
  }
  else{
    r = m%n;
    q = m/n;
    std::cout << "Es gilt " << m << " = " << q << " * " << n << " + " << r << std::endl;
  }
}


void teilC(){
  int n,b;
  std::cout << "n: ";
  std::cin >> n;
  std::cout << "b: ";
  std::cin >> b;
  int tmp = 1;
  int size = 0;
  while(tmp <= n){
    tmp *= b;
    size++;
  }
  int y[size]; // Das ist böse und wirft eine Warnung
  // ABER: Das ist mir egal. Es geht.
  for(int i = size-1; i >= 0; i--){
    y[i] = n%b;
    n /= b;
  }
  for( int i = 0; i < size; i++){
    std::cout << y[i];
  }

}


int main(){

  std::cout << "Teil a):" << std::endl;  
  teilA();

  std::cout << "Teil b):" << std::endl;  
  teilB();

  std::cout << "Teil c):" << std::endl;  
  teilC();

  return 0;
}
