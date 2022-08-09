#include "xor.h"

// constructor, initialize class variables and pointers here if need.
Xor::Xor(){
  shared_ptr<node> top_ptr_ = nullptr;
  
}

//deconstructor,
Xor::~Xor(){}


shared_ptr<node> Xor::InitNode(int data){
  shared_ptr<node> ret(new node);
  ret->data=data;
  ret->next=nullptr;
  return ret;
}

string LinkedList::Report(){
  string ret;
  shared_ptr<node> curr=top_ptr_;
  while(curr!=nullptr)
  {
    ret.append(to_string(curr->data)+" ");
    curr=curr->next;
  }
  return ret;
}

void LinkedList::AppendData(int data){
  shared_ptr<node> new_node=InitNode(data);
  shared_ptr<node> curr=top_ptr_;
  if (top_ptr_){
    while(curr->next!=nullptr){
      curr=curr->next;
    }
    curr->next=new_node;
  }
  else{
    top_ptr_=new_node;
  }
}

void LinkedList::Append(shared_ptr<node> new_node){
  shared_ptr<node> curr=top_ptr_;
  if (top_ptr_){
    while(curr->next!=nullptr){
      curr=curr->next;
    }
    curr->next=new_node;
  }
  else{
    top_ptr_=new_node;
  }
}

void LinkedList::InsertData(int offset, int data){
  shared_ptr<node> new_node=InitNode(data);
  if(top_ptr_){
    if(offset==0){
        new_node->next=top_ptr_;
        SetTop(new_node);
        return;
    }  
    shared_ptr<node> curr=top_ptr_->next;
    shared_ptr<node> prev=top_ptr_;
    for(int i=0;i<offset-1;i++){
      curr=curr->next;
      prev=prev->next;
    }
    new_node->next=curr;
    prev->next=new_node;
  }
  else{top_ptr_=new_node;}
}

void LinkedList::Insert(int offset, shared_ptr<node> new_node){
    if(top_ptr_){
    if(offset==0){
        new_node->next=top_ptr_;
        SetTop(new_node);
        return;
    }  
    shared_ptr<node> curr=top_ptr_->next;
    shared_ptr<node> prev=top_ptr_;
    for(int i=0;i<offset-1;i++){
      curr=curr->next;
      prev=prev->next;
    }
    new_node->next=curr;
    prev->next=new_node;
  }
  else{top_ptr_=new_node;}
}


void LinkedList::Remove(int offset){
  shared_ptr<node> curr=top_ptr_->next;
  shared_ptr<node> prev=top_ptr_;
  if(offset==0){
    top_ptr_=top_ptr_->next;
  }
  for(int i=1;i<offset;i++){
      curr=curr->next;
      prev=prev->next;
    }
  prev->next=curr->next;
  }

int LinkedList::Size(){
  int ret=0;
  shared_ptr<node> curr=top_ptr_;
  while(curr!=nullptr){
    ret++;
    curr=curr->next;
  }

  return ret;
}

bool LinkedList::Contains(int data){
  bool ret;
  shared_ptr<node> curr=top_ptr_;
  while(curr!=nullptr){
    if(curr->data==data){
      return ret=true;
    }
    curr=curr->next;
  }
  return ret;
}

// This function is implemented for you
// It returns the top pointer
shared_ptr<node> LinkedList::GetTop(){
  return top_ptr_;
}

// This function is implemented for you
// It sets a given pointer as the top pointer
void LinkedList::SetTop(shared_ptr<node> top_ptr){
  top_ptr_ = top_ptr;
}
