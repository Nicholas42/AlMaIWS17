#include <iostream>

struct element{
  int ziffer;
  element* next = nullptr;
};



element* einlesen(std::string zahl){
  element *first = new element;
  int len = zahl.length();
  for(int i = 0; i < len; i++){
    element *tmp = new element;
    tmp->ziffer = zahl[i] - '0';
    // die Ziffer 'z' ist als ascii-zeichen z hinter '0', also gibt mit 'z'-'0' = z
    tmp->next = first;
    first = tmp;
  }
  return first;
}

element* summe(element *l1, element *l2){
  element *first = new element;
  int carry = 0; // Der Übertrag
  while(l1->next && l2->next){
    element *tmp = new element;
    tmp->next = first;
    tmp->ziffer = (l1->ziffer + l2->ziffer + carry)%10;
    carry = (l1->ziffer + l2->ziffer + carry)/10;
    first = tmp;
    l1 = l1->next;
    l2 = l2->next;
  }
  while(l1->next){
    element *tmp = new element;
    tmp->next = first;
    tmp->ziffer = (l1->ziffer + carry)%10;
    carry = (l1->ziffer + carry)/10;
    first = tmp;
    l1 = l1->next;
  }
  while(l2->next){
    element *tmp = new element;
    tmp->next = first;
    tmp->ziffer = (l2->ziffer + carry)%10;
    carry = (l2->ziffer + carry)/10;
    first = tmp;
    l2 = l2->next;
  }
  if(carry){
    element *tmp = new element;
    tmp->next = first;
    tmp->ziffer = carry;
    first = tmp;
  }
  
  return first;
}

int main(){
  element *l1 = new element;
  element *l2 = new element;
  l1 = einlesen("18446744073709551615");
  l2 = einlesen("9223372036854775807");
  element *res;
  res = summe(l1,l2);
  element* it = res;
  while(it->next){
    std::cout << it->ziffer;
    it = it->next;
  }
}
