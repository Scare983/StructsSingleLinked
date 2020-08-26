#include "SortedLinkedList.h"
#include <iostream>
using namespace std;
ListNode* workingNode;
SortedLinkedList::SortedLinkedList() {
	head = NULL;
	count = 0;
	location = 0;
}
SortedLinkedList::~SortedLinkedList() {
	delete workingNode;
}
int SortedLinkedList::length() const {
	return count;
}
void SortedLinkedList::insertItem(DataType &item) {
		
	  workingNode = new ListNode(item);
		//workingNode->item = item; //changed
			ListNode* temp = head;
	while(temp != NULL) {
	 if(item.compareTo(temp->item) == EQUAL ) {
		goto label;
		
		}
		temp = temp->next;
	}
	if (this->isEmpty()) {
		this->head = workingNode; //do this if nothing in set
		
	}

	 else if (item.compareTo(head->item) == LESS) { //checks the first item 
		workingNode->next = head;
		this->head = workingNode;
	}
	
	else { //established there are multiple components, now checking
		ListNode* after = head->next; //
		ListNode* before = head; 
		while(after != NULL) { //makes sure we don't surpass the end
			if(item.compareTo(after->item) == LESS) {
				break;
			}
		before = after;
		after = after->next;
		}
		//now that we found the location we insert 
		workingNode->next = before->next;
		before->next = workingNode;
	}
	
	workingNode = this->head;
	count++; //increase length
	label:
	int i;

}
void SortedLinkedList::deleteItem(DataType &item) {
	int pos = 0;
	bool found = false;


if(isEmpty()){
	cout << "List is empty" << endl;
	}
else {
	ListNode* temp = head;
	while(temp != NULL) {
			pos++;
				if((temp->item).getValue() == item.getValue()) {
					found = true;
					break;
				}
				temp = temp->next;
	}
	temp = NULL;
	if(found) {
		workingNode = head;
		if(pos == 1) {
			workingNode = head->next;
			head = workingNode;
			count--;
			
		}
		//lines 63 to 80 copied from searchItem(); 
		else {
			
				workingNode = head; //workingNode is essentially a temp, figured halfway didn't need it.
					for(int i = 1; i < pos; i++) { // normal for loop to get to location to delete
						temp = workingNode; //change node networking 
						workingNode = workingNode->next; //change node networking
					}
					temp->next = workingNode->next; //eqaulizes temp and workingNode
				
			count--; //deleted, therfore length goes down
		}
	
	}
	else {
	cout << "Inputted value is not in list!" << endl;
	}
}
	
}
int SortedLinkedList::searchItem(DataType &item) {
	int pos = 0;
	bool found = false; //observer  checks if found


if(isEmpty()){ //handles empty case
	cout << "List is empty" << endl;
	}
else { 
	ListNode* temp = this->head;
	while(temp != NULL) { //iterate through temp which is equal to head
			pos++; //kind of like iterate, where checks where at in nodes 
				if((temp->item).getValue() == item.getValue()) { //could use compareTo method, but essentially same thing to if both are equal
					found = true; // found what we are looking for and have the position
					break; //leave while
				}
				temp = temp->next; //continue the while
	}
	if(found) { //found case
	cout << "Index of the item is: " << pos << endl;
	}
	else { //not found case
	cout << "Value not in list!" << endl;
	}
}
	
}
void SortedLinkedList::clear() {
	ListNode* temp = this->head;
	
	while(temp != NULL) { //iterate throuugh temp, changing value of temp to head's next.  Delete the this head, making it null, change location
		temp = head->next;
		delete [] head;
		head = temp;
		
	}
resetIterate();
	count = 0; //length becomes 0
}
void SortedLinkedList::pairwiseSwap() {
	
	/*if(isEmpty()) {
	cout << "List is empty." << endl; //probablity shouldve put this in isEmpty function, but almost done so we good	
	}
	else {
		ListNode* temp = this->head;
		
		int number = length() % 2; 
		
		for(int i = 0; i < number; i++) {
		
			
		temp = temp->next->next;
		}
		
		
	//	this->head = temp;  
	} */
	
}


bool SortedLinkedList::isEmpty() { //call whenever want to check if Head is null
	if(this->head == NULL) {
		return true;
	}
	else {
		return false;
	}
}
void SortedLinkedList::printList() {
	
ListNode* temp = this->head;

  while(temp){
       cout << ((temp->item).getValue()) << " "; //just printing value of a temp ListNode equal to the head
        temp = (temp->next);
       
    } 
	cout << endl;
}

void SortedLinkedList::iterate() {
	location++; //increase to check 
	ListNode* temp = this->head;
	
	if(isEmpty()) {
		resetIterate(); // we don't iterate b/c we can't
		cout << "Empty List." << endl;
	}
	else if (location > length()) {
		location--;  //we don't iterate b/c we can't
		cout << "Iterator surpasses length of list, please reset or add to the list before continuing. " << endl;
	}
	else {
		
		for(int i = 0; i < location -1; i++) {
			if(temp != NULL)
			temp = (temp->next); //just getting copy of a location
		
		}
		cout << (temp->item).getValue() << endl; //outputting data of the copy
	}
	
	
}
	
void SortedLinkedList::resetIterate() {
	location = 0; //start reading at begginining of list , works with iterate()
	
}