#include <iostream>
#include <cmath>

void printv(double *x, int n){
  for(int i = 0; i<n; i++){
    std::cout << x[i] << std::endl;
  }
}

void SCALPR(double *beta, double *x, double *y, int n){
  for(int i = 0; i<n; i++){
    (*beta) += x[i]*y[i];
  }
}

void NORM(double *l, double *x, int n){
  SCALPR(l, x, x, n);
  (*l) = std::sqrt(*l);
}

void MULTZAHL(double *z, double *x, double alpha, int n){
  for(int i = 0; i<n; i++){
    z[i] = alpha*x[i];
  }
}

void PLUS(double *z, double *x, double *y, int n){
  for(int i = 0; i<n; i++){
    z[i] = x[i] + y[i];
  }
}

void MULTVEKTOR(double *z, double *x, double *y, int n){
  for(int i = 0; i<n; i++){
    z[i] = x[i] * y[i];
  }
}

void VDMAX(double *z, double *x, double *y, int n){
  for(int i = 0; i<n; i++){
    z[i] = std::max(x[i], y[i]);
  }
}

void DIVVEKTOR(double *z, double *x, double *y, int n){
  for(int i = 0; i<n; i++){
    if(y[i] == 0){
      z[i] = 0;
    }
    else{
      z[i] = x[i]/y[i];
    }
  }
}

void randVektor(double *x, int n){
  for(int i = 0; i < n; i++){
    x[i] = std::rand()/((double) RAND_MAX);
  }
}


int main(){
  int n;
  double alpha;
  std::cout << "Länge der Vektoren?" << std::endl;
  std::cin >> n;
  std::cout << "Alpha?" << std::endl;
  std::cin >> alpha;

  double *x = new double[n];
  double *y = new double[n];
  randVektor(x, n);
  randVektor(y, n);

  double *max = new double[n];
  VDMAX(max, x, y, n);
  
  double *plus = new double[n];
  PLUS(plus, x, y, n);
  
  double *mult = new double[n];
  MULTVEKTOR(mult, x, y, n);
  
  double *multzahl = new double[n];
  MULTZAHL(multzahl, x, alpha, n);
  
  double *div = new double[n];
  DIVVEKTOR(div, x, y, n);
  
  double scalpr = 0;
  SCALPR(&scalpr, x, y, n);

  double norm = 0;
  NORM(&norm, x, n);

  std::cout << "Skalaprodukt: \t" << scalpr << std::endl;
  std::cout << "Norm: \t" << norm << std::endl;
  std::cout << "x\t\ty\t\tMAX\t\tADD\t\tMULT\t\tMULTZAHL \tDIV" << std::endl;
  for(int i = 0; i < n; i++){
    std::cout << x[i] << "  \t" << y[i] << "  \t" << max[i] << "  \t" << plus[i] << "  \t" << mult[i] << "  \t" << multzahl[i] << "  \t" << div[i] <<std::endl;
  }

  int m;
  std::cout << "Anzahl der Versuche?" << std::endl;
  std::cin >> m;

  int maxdim = 20;
  
  double *v = new double[maxdim];
  int good;
  
  for(int i = 1; i < maxdim; i++){
    good = 0;
    for(int j = 0; j < m; j++){
      randVektor(v, i);
      norm = 0;
      NORM(&norm , v, i);
      if(norm <= 1){
	good++;
      }      
    }
    std::cout << i << "\t" << good/((double) m) << std::endl;
  }
  
}

