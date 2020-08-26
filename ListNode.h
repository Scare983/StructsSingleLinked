#include "DataType.h"

class ListNode {

public:
	DataType item;
	ListNode *next;
	explicit ListNode(DataType &item) : item(item) {};
	
};
