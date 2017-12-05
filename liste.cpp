#include <iostream>

struct Element{
    int val;
    Element *next = nullptr;
};

Element *vorne(Element *e, Element *first){
    e->next = first;
    first = e;
    return first;
}

void einfuegen(Element *e, Element *f){
    e->next = f->next;
    f->next = e;
}

Element *deleteFirst(Element *first){
    Element *tmp = first;
    first = first->next;
    tmp->next = nullptr;
    //delete tmp;
    return first;
}

Element *deleteAfter(Element *e){
    Element *tmp = e->next;
    e->next = tmp->next;
    tmp->next = nullptr;
    return tmp;
}

int main(){}
