#include <iostream>

struct Stab{
  short *content;
  short k;
};

void print(Stab **Staebe){
  int m = 0;
  for(int i = 0; i < 3; i++){
    m += Staebe[i]->k + 1;
  }
  for(short i = m-1; i >= 0; i--){
    for(int j = 0; j < 3; j++){
      int con = Staebe[j]->content[i];
      if(con > 0){
	std::cout << std::string(m - con + 2, ' ')
		  << std::string(2*con - 1, '#')
		  << std::string(m - con + 2, ' ');
      }else{
	std::cout << std::string(m + 1, ' ')
		  << "|"
		  << std::string(m + 1, ' ');
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::string(m + 1, '_') << "A" << std::string(m + 1, '_')
	    << std::string(m + 1, '_') << "B" << std::string(m + 1, '_')
	    << std::string(m + 1, '_') << "C" << std::string(m + 1, '_')
	    << std::endl << std::endl;
}


void bewege(Stab *A, Stab *B, Stab *C, short n, Stab **Staebe){
  if (n>0){
    bewege(A, C, B, n-1, Staebe);
    C->k++;
    C->content[C->k] = A->content[A->k];
    A->content[A->k] = 0;
    A->k--;
    print(Staebe);
    bewege(B, A, C, n-1, Staebe);
  }
}


int main(){
  short n;
  std::cout << "n?";
  std::cin >> n;
  Stab *A = new Stab;
  Stab *B = new Stab;
  Stab *C = new Stab;
  A->content = new short[n];
  A->k = n-1;
  B->content = new short[n];
  B->k = -1;
  C->content = new short[n];
  C->k = -1;
  for(short i = 1; i <= n; i++){
    A->content[n-i] = i;
  }
  Stab *Staebe[3] = {A,B,C};
  print(Staebe);
  bewege(A, B, C, n, Staebe);
}
