#include <iostream>

struct Element{
  int wert;
  Element *next = nullptr;
  Element *prev = nullptr;
};

struct Liste{
  Element *first = nullptr;
  Element *last = nullptr;
};

void append(Element *e, Liste *l){
  e->next = nullptr;
  e->prev = nullptr;
  if(l->last == nullptr){
    l->first = e;
    l->last = e;
  }else{
    e->prev = l->last;
    l->last->next = e;
    l->last = e;
  }  
}

void push(Element *e, Liste *l){
  e->next = nullptr;
  e->prev = nullptr;
  if(l->first == nullptr){
    l->first = e;
    l->last = e;
  }else{
    e->next = l->first;
    l->first->prev = e;
    l->first = e;
  }  
}

void insertAfter(Element *e, Element *hinter, Liste *l){
  e->prev = nullptr;
  e->next = nullptr;
  if(hinter->next == nullptr){
    append(e, l);
  }else{
    e->next = hinter->next;
    e->prev = hinter;
    hinter->next->prev = e;
    hinter->next = e;
  }
}

void insertBefore(Element *e, Element *vor, Liste *l){
  e->next = nullptr;
  e->prev = nullptr;
  if(vor->prev == nullptr){
    push(e, l);
  }else{
    e->next = vor;
    e->prev = vor->prev;
    vor->prev->next = e;
    vor->prev = e;
  }
}

void print(Liste *l){
  for(Element *p = l->first; p; p = p->next){
    std::cout << p->wert << std::endl;
  }
}

Element *pop_front(Liste *l){
  Element *e = l->first;
  e->next->prev = nullptr;
  l->first = e->next;
  e->next = nullptr;
  return e;
}

Element *pop_back(Liste *l){
  Element *e = l->last;
  e->prev->next = nullptr;
  l->last = e->prev;
  e->prev = nullptr;
  return e;
}

void deleteElem(Element *e, Liste *l){
  if(e->prev == nullptr && e->next == nullptr){
    // e ist das einzige Element der Liste
    l->first = nullptr;
    l->last = nullptr;
    return;
  }
  if(e->prev == nullptr){
    pop_front(l);
    return;
  }
  if(e->next == nullptr){
    pop_back(l);
    return;
  }

  e->prev->next = e->next;
  e->next->prev = e->prev;
  e->prev = nullptr;
  e->next = nullptr;   
}

int main(){
  Liste list;
  Liste *l = &list;
  for (int i = 0; i < 10; i++){
    Element *tmp = new Element;
    tmp->wert = i;
    push(tmp, l);
  }
  print(l);
}
  

