#include <iostream>
#include <cstdlib>
#include "dnode.h"
using namespace std;
int main()
{
    dnode *head_ptr, *tail_ptr;
    dnode *p, *q, *r, *s, *t;  
    p = new dnode(1.0, NULL, NULL);
    q = new dnode(2.0, NULL, p);
    p -> set_next(q);
    r = new dnode(3.0, NULL, q);
    q -> set_next(r);
    s = new dnode(4.0, NULL, r);
    r->set_next(s);
    head_ptr = p;
    tail_ptr = s;

//TESTING NEXT AND PREV MEMBERFUCNTIONS:
    // cout<<p<<endl;
    // cout<<p->next()        <<endl;
    // dnode* t = p->next();
    // cout<<t       <<endl;
    // cout<<p->next()->next()->next()->prev()->data()<<endl;

//TESTING REMOVES:
    // cout<<length(head_ptr)<<endl;//4
    // list_remove(tail_ptr->prev());
    // cout<<length(head_ptr)<<endl;//3

    // list_head_remove(head_ptr);
    // cout<<length(head_ptr)<<endl<<endl;//2

//TESTING CLEAR LIST:
    // cout<<length(head_ptr)<<endl;
    // list_clear(head_ptr);
    // cout<<length(head_ptr)<<endl;//0
//TESTING LOOPS IN THE LINKED LIST 
   //  t = new dnode(5.0, r, s); //loop
   //  s->set_next(t);
   //  tail_ptr = t;
   //  cout<<"loop?: "<< has_cycle(head_ptr)<<endl; //should return true
   //  cout<<find_cycle(head_ptr)->data(); //should return 3.0


}