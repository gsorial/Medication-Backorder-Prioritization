

#include <gtest/gtest.h>
#include "../code/xor.cpp"

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

class test_xor : public ::testing::Test {

};
	

/////////////////////////////////////////
// Test Helper Functions
/////////////////////////////////////////


/////////////////////////////////////////
// Tests start here
/////////////////////////////////////////


TEST_F(test_xor, TestInitialization){ 
	Xor testList;
	ASSERT_EQ(NULL,testList.GetTop());
	node* root = testList.InitNode(1,25);
	ASSERT_TRUE(root);
	ASSERT_EQ(25, root->dose);
	ASSERT_FALSE(root->link);
}


TEST_F(test_xor, TestInsert){
	Xor testList;  //tried to make this into a helper function but using 'testList' caused problems...
	node* a=testList.InitNode(1,20);
	node* b=testList.InitNode(2,20);
	node* c=testList.InitNode(3,20);
	testList.Insert(a);
	testList.Insert(b);
	testList.Insert(c);

	node* top = a;
	testList.SetTop(top);
	node* curr=testList.GetTop();
	ASSERT_EQ(1, curr->MRN);
	node* prev=nullptr;
	curr=testList.XOR(prev,curr->link);
	prev=testList.GetTop();
	ASSERT_EQ(2, curr->MRN);
	curr=testList.XOR(prev,curr->link);
	ASSERT_EQ(3, curr->MRN);
}

TEST_F(test_xor, TestRemove){
	Xor testList;
	node* a=testList.InitNode(1,20);
	node* b=testList.InitNode(2,20);
	node* c=testList.InitNode(3,20);
	testList.Insert(a);
	testList.Insert(b);
	testList.Insert(c);
	
	node* top = a;			//will remove and check which node is at the top of the list
	testList.SetTop(top);
	node* curr=testList.GetTop();
	testList.Remove();
	curr=testList.GetTop();
	ASSERT_EQ(2, curr->MRN);
	testList.Remove();
	curr=testList.GetTop();
	ASSERT_EQ(3, curr->MRN);
	testList.Remove();
	curr=testList.GetTop();
	ASSERT_EQ(NULL, curr);
}

TEST_F(test_xor, TestDispense){
	Xor testList;
	node* a=testList.InitNode(1,20);
	node* b=testList.InitNode(2,20);
	node* c=testList.InitNode(3,20);
	testList.Insert(a);
	testList.Insert(b);
	testList.Insert(c);

	node* top = a;
	testList.SetTop(top);
	node* curr=testList.GetTop();
	testList.dispense(45); //only patient 3 should be remaining in the list
	curr=testList.GetTop();
	ASSERT_EQ(3,curr->MRN);
	testList.dispense(20); //dispense the final patient's medication
	ASSERT_EQ(NULL,testList.GetTop());
}

TEST_F(test_xor, TestSize){
	Xor testList;
	node* a=testList.InitNode(1,20);
	node* b=testList.InitNode(2,20);
	node* c=testList.InitNode(3,20);
	testList.Insert(a);
	testList.Insert(b);
	testList.Insert(c);
		
						
	ASSERT_EQ(3, testList.size()); 
	testList.Remove();
	ASSERT_EQ(2, testList.size()); 
	testList.Remove();
	ASSERT_EQ(1, testList.size()); 
	testList.Remove();
	ASSERT_EQ(0, testList.size()); 
	
	
}//size should be 3-2-1-0