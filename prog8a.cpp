#include <iostream>

struct  Student {
  long  matnr;
  short  geb [3];
  short  studienfach;
  short  fachsemester;
};


void randStudent(Student *s){
  s->matnr = rand()%900000+100000;
  s->geb[0] = rand();
  s->geb[1] = rand();
  s->geb[2] = rand();
  s->studienfach = rand()%100+1;
  s->fachsemester = rand()%100+1;
}

bool leq1(Student *array, int i, int j){
  return array[i].matnr <= array[j].matnr;
}

bool leq2(Student *array, int i, int j){
  if(array[i].geb[0] < array[j].geb[0]){
    return true;
  }
  if(array[i].geb[0] > array[j].geb[0]){
    return false;
  }
  if(array[i].geb[1] < array[j].geb[1]){
    return true;
  }
  if(array[i].geb[1] > array[j].geb[1]){
    return false;
  }
  return array[i].geb[2] <= array[j].geb[2];
    
}


void print(Student *array, int N){
  std::cout << "mat\tDD\tMM\tYY\tFach\tSem" << std::endl;
  for (int i = 0; i < N; i++){
    std::cout << array[i].matnr << "\t" << array[i].geb[0] << "\t" << array[i].geb[1] << "\t" << array[i].geb[2] << "\t" <<  array[i].studienfach  << "\t" << array[i].fachsemester << std::endl;
  }
}

void mergesort(Student *array, Student *help, int N){
  if(N < 2){
    return;
  }
  mergesort(array, help, N/2);
  mergesort(array + N/2, help +N/2, N-N/2);
  int i = 0;
  int j = 0;
  while(i < N/2 && j < N-N/2){
    if(leq1(array, i, j+N/2)){
      help[i+j] = array[i];
      i++;
    }else{
      help[i+j] = array[j+N/2];
      j++;
    }
  }
  while(i < N/2){
    help[i+j] = array[i];
    i++;
  }
  while(j < N-N/2){
    help[i+j] = array[j+N/2];
    j++;
  }
  for(int k = 0; k < N; k++){
    array[k] = help[k];
  }
}

void mergesort1(Student *array, Student *help, int N){
  if(N < 2){
    return;
  }
  mergesort(array, help, N/2);
  mergesort(array + N/2, help +N/2, N-N/2);
  int i = 0;
  int j = 0;
  while(i < N/2 && j < N-N/2){
    if(leq2(array, i, j+N/2)){
      help[i+j] = array[i];
      i++;
    }else{
      help[i+j] = array[j+N/2];
      j++;
    }
  }
  while(i < N/2){
    help[i+j] = array[i];
    i++;
  }
  while(j < N-N/2){
    help[i+j] = array[j+N/2];
    j++;
  }
  for(int k = 0; k < N; k++){
    array[k] = help[k];
  }
}


int main(){
  int N = 16;
  Student *array = new Student[N];
  for(int i = 0; i < N; i++){
    randStudent(&array[i]);
  }
  print(array, 10);
  Student *help = new Student[N];
  mergesort(array, help, N);
  print(array,10);
}
