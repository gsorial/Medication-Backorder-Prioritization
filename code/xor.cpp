#include "xor.h"

Xor::Xor(){
  
  
}

Xor::~Xor(){
  if(top_ptr_){
    curr=top_ptr_;
    prev=nullptr;
    while(curr){
      next=XOR(prev,curr->link);
      prev=curr;
      delete curr;
      curr=next;
    }
  }
}

node* Xor::InitNode(int MRN, int dose){
  node* ret = new node;
  ret->MRN=MRN;
  ret->dose=dose;
  ret->link=nullptr;
  return ret;
}

void Xor::Insert(node* new_node){
  if (top_ptr_){
    curr=top_ptr_;
    next=XOR(prev,curr->link);
    while(next){  //if there's more than 1 node in the list, go to the end
      prev=curr;
      curr=next;
      next=XOR(prev,curr->link);
    }
    new_node->link=XOR(curr,next);   //accidentally had this at prev,next for the longest time, thank you VS debug!
    curr->link=XOR(prev,new_node);    
  }
  else{
    top_ptr_=new_node;
  }
}


void Xor::Remove(){     //removes the first node in the list
  if(top_ptr_){
    if(top_ptr_->link==nullptr){    //if only head, set to null ptr, deleting node...would this be a memory leak otherwise? Deleting top_ptr_ directly gives error
      node* temp=top_ptr_;
      delete temp;
      top_ptr_=nullptr;
    }
    else{
      node* new_head =nullptr;       
      new_head=XOR(nullptr,top_ptr_->link); //new head=next
      next=XOR(top_ptr_,new_head->link);    //the following node is assigned to next
      new_head->link=XOR(nullptr,next);     //new head's link needs to be updated
      delete top_ptr_;
      top_ptr_=new_head;                 
    }
  }
  else{cout<<"There are no patients remaining in this list\n";}
}


void Xor::printNode(node* node){
  cout<<"MRN: "<<node->MRN<<"\n";
  cout<<"Dose: "<<node->dose<<" Grams\n";
}

void Xor::dispense(int gramsReceived){ //wow recursion
  int gramsRemaining=gramsReceived;
  if(top_ptr_){
    curr=top_ptr_;
    prev=nullptr;
    if(gramsRemaining>0 && gramsRemaining-curr->dose>=0){
      gramsRemaining=gramsRemaining-curr->dose;
      printNode(curr);
      Remove();
      curr=GetTop();
      dispense(gramsRemaining);
      }
     
  }
  else{cout<<"There are no patients remaining in this list\n";}
}

void Xor::printList(){
  if(top_ptr_){
    curr=top_ptr_;
    prev=nullptr;
    next=XOR(prev,curr->link);
    while(next!=nullptr){
      printNode(curr);
      next=XOR(prev,curr->link);
      prev=curr;
      curr=next;
    }  
  }
  else{cout<<"There are no patients in this list";}
}

int Xor::size(){
  int i=0;
  curr=top_ptr_;
  prev=nullptr;
  while(curr){
    i++;
    next=XOR(prev,curr->link);
    prev=curr;
    curr=next;
  }
  if(i==0){
    cout<<"There are no patients in this list\n";
    return 0;
  }
  return i;
  }


node* Xor::XOR(node* prev, node* next){
  return reinterpret_cast<node*>(reinterpret_cast<uintptr_t>(prev)^reinterpret_cast<uintptr_t>(next));
}

node* Xor::GetTop(){
  return top_ptr_;
}

void Xor::SetTop(node* top_ptr){
  top_ptr_ = top_ptr;
}