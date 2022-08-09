#ifndef xor_H__
#define xor_H__

#include <iostream>
#include <memory>

using namespace std;

struct node {
  int MRN;                //medical record number of patient is unique identifier
  int dose;               // dose in grams
  node* link;  // pointer to next and previous node through the power OF XOR!
};


class Xor {
public:
  Xor();

 ~Xor();

//This will create a node with the above data
  node* InitNode(int MRN, int dose);

// This will add a node to the end of the list by traversing the nodes starting
// with the head. Although it might make more sense to
// start with the tail.
  void Insert(node* new_node);

// This will remove the first patient in the list which is the next patient needing drug
  void Remove();

//This will be called before removal of a node and will print the patient’s data
  void printNode(node* node);

// This will traverse the list in chronological order and call the PrintNode function
// followed by the Remove function on the appropriate nodes
  void dispense(int gramsReceived);

//This will provide the user with a list of patients currently awaiting infusions.
  void printList();
//outputs the size of list
  int size();

  node* GetTop();

  void SetTop(node* top_ptr);

  node* XOR(node* prev, node* next);


private:
  node* top_ptr_ =nullptr;
  node* prev=nullptr;
  node* next=nullptr;
  node* curr=nullptr;
  
};

#endif  // Xor_H__