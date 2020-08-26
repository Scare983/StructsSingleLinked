
#include "ListNode.h"
class SortedLinkedList {
public:
	int location;
	SortedLinkedList();
	~SortedLinkedList();
	int length() const;
	void insertItem(DataType &item);
	void deleteItem(DataType &item);
	int searchItem(DataType &item);
	void clear();
	void pairwiseSwap();
	bool isEmpty();
	void printList();
	void iterate();
	void resetIterate();
	void switchValue(int &item, int &item2);
private:
	int count;
	ListNode *head;
};