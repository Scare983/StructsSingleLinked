#include "DataType.h"
using namespace std;
DataType::DataType(int value) {
	this->value = value; //explicit therefore when called in ListNode, automatically stores the data passed through.  
}

Comparison DataType::compareTo(DataType &item) {
	Comparison check;

	if ( getValue() < item.getValue() ) {
		
		return LESS;
	}

	else if (getValue() == item.getValue() ) {
		return EQUAL;
	}

	else {
		return GREATER;
	}
}

int DataType::getValue() const {
	return value;

}
