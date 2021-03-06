#include "dnode.h"
//using namespace std;

std::size_t length( const dnode* head_ptr)
{
    const dnode *cursor;
    size_t answer = 0;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->next())
        ++answer;
    return answer;
}
void head_insert(dnode*& head_ptr, const dnode::value_type& entry)
{
    dnode *new_ptr;
    new_ptr = new dnode(entry, head_ptr, NULL); //1) making new node, back points to NULL (since its new head) and next points to current nex tnode
    if (head_ptr -> prev() != NULL){
        head_ptr -> set_prev(new_ptr); //2) linking the old head to the new head if need be
    }
    head_ptr = new_ptr; //3) setting the head_ptr
}
void insert(dnode* prev_ptr, const dnode::value_type& entry)
{
    dnode *insert_ptr;
    insert_ptr = new dnode(entry, prev_ptr->next(), prev_ptr ); //1) new node linked to back and front nodes
    prev_ptr->next()->set_prev(insert_ptr); //2) linking front node to new node
    prev_ptr->set_next(insert_ptr);//3) linking back node to new node
}
dnode* search(dnode* head_ptr, const dnode::value_type& target)
{
	dnode *cursor;
	for (cursor = head_ptr; cursor->next() != head_ptr; cursor = cursor->next())
	    if (target == cursor->data())
		    return cursor;
	return NULL;
}
const dnode* search(const dnode* head_ptr, const dnode::value_type& target)
{
	const dnode *cursor;
	for (cursor = head_ptr; cursor->next() != head_ptr; cursor = cursor->next())
	    if (target == cursor->data())
		    return cursor;
	return NULL;
}
dnode* locate(dnode* head_ptr, std::size_t position)
{
    dnode *cursor;
    size_t i;
    assert (0 < position);
    cursor = head_ptr;
    for (i = 1; (i < position) && (cursor->next() != head_ptr); i++)
        cursor = cursor->next();
    return cursor;
}
const dnode* locate(const dnode* head_ptr, std::size_t position)
{
    const dnode *cursor;
    size_t i;
    assert (0 < position);
    cursor = head_ptr;
    for (i = 1; (i < position) && (cursor->next() != head_ptr); i++)
        cursor = cursor->next();
    return cursor;
}
void list_head_remove(dnode*& head_ptr){
    dnode *remove_ptr;
    remove_ptr = head_ptr; //1) mark the head node for deletion
    head_ptr = head_ptr->next(); //2) move the head_ptr to the new head node
    if (head_ptr != NULL){
        head_ptr->set_prev(NULL); //3) setting the new head prev link to NULL if can
    }
    delete remove_ptr; //4) deleted the old head dnode
}

void list_remove(dnode* prev_ptr){
    dnode *remove_ptr;
    remove_ptr = prev_ptr->next(); //1) marking node for deletion
    if (remove_ptr->next() != NULL){
        remove_ptr->next()->set_prev(prev_ptr);//2) linking front node to back node if can
        prev_ptr->set_next( remove_ptr->next() );//3) linking back node to front node if can 
    }
    delete remove_ptr; //4) deleting the node
    prev_ptr->set_next(NULL);//5)settign to null
}
void list_clear(dnode*& head_ptr){
	while (head_ptr != NULL)	
	    list_head_remove(head_ptr);
}

void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr){//finish
	//A) SET HEAD AND TAIL POINTERS TO null
    head_ptr = NULL;
    tail_ptr = NULL;
    //B) SPACEIAL CASE: When List Empty.
    if (source_ptr == NULL)
        return; 
    //C) Make the head node for the newly created list, and put data in it.
    head_insert(head_ptr, source_ptr->data());
    tail_ptr = head_ptr;
    //D) Copy the rest of the nodes one at a time, adding at the tail of new list.
    source_ptr = source_ptr->next(); //(1) TRANSVERSING THRU ORIG LIST: addr of source_ptr = addr of next node
    while (source_ptr != NULL) //(1) TRANSVERSING THRU ORIG LIST:
    {
        insert(tail_ptr, source_ptr->data()); //(2) list_insert(ptr to node that we will insert after, value in the new node)
        tail_ptr = tail_ptr->next(); //(3) addr of tail_ptr = addr tail_ptr points to
        source_ptr = source_ptr->next(); //(4) addr of source_ptr = addr of next node
    } 
}
bool has_cycle(dnode*& head_ptr){ 
    if (head_ptr==NULL)
        return false;
    dnode *fast, *slow;
    fast = head_ptr->next(); //fast ptr starts on next node
    slow = head_ptr;//slow ptr starts one node behind
    while(fast!=NULL && slow!=NULL)
    {
        if (fast == slow) //they meet up, then there is a loop
            return true;
        fast = fast->next()->next();//fast increments by 2 nodes
        slow = slow->next(); //slow increments by one node
    }
    return false; //if i found no loops, return false
}

dnode* find_cycle(dnode*& head_ptr){
    dnode *fast, *slow;
    fast = head_ptr->next(); //fast ptr starts on next node
    slow = head_ptr;//slow ptr starts one node behind
    while(fast!=NULL && slow!=NULL)
    {
        if (fast == slow) //they meet up, then there is a loop
            return fast;//return the node
        fast = fast->next()->next();//fast increments by 2 nodes
        slow = slow->next(); //slow increments by one node
    }
}



    
                                                                                                                                                                                                                                                                                                                                                                                                