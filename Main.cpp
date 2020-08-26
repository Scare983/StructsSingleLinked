#include <iostream>
#include "SortedLinkedList.h"
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

void commandList() {  //basically the menu
	cout << "Commands:" << endl;
	cout << "(i) - Insert value" << endl;
	cout << "(d) - Delete value" << endl;
	cout << "(s) - Search value" << endl;
	cout << "(n) - Print next iterator value" << endl;
	cout << "(r) - Reset iterator" << endl;
	cout << "(p) - Print list" << endl;
	cout << "(l) - Print length" << endl;
	cout << "(b) - Pairwise function" << endl;
	cout << "(c) - Clear list" << endl;
	cout << "(q) - Quit Program" << endl;
}

int main(int argc, char *argv[]) {
	if(argc > 2 ) { //case for too many files ,exits
		cout << "Sorry! Too many files inputted, quitting..." << endl;
		return EXIT_SUCCESS;
	}
	if(argc == 1) { //checks if no files inputted, exit
		cout << "Sorry! Not file inputted, quitting..." << endl;
		return EXIT_SUCCESS;
	}
	ifstream workingFile; 
	workingFile.open(argv[1], ios::in); //opens file to read from
	commandList();
	int singleNumber;  //placeholder for getting each int in list
	SortedLinkedList currentList = SortedLinkedList(); //intilizes list
	while(workingFile >> singleNumber) {//iterates to null
		DataType allData = DataType(singleNumber);//creates object for values, can go out of scope after loop 
		currentList.insertItem(allData); //inputs data objects into the sortedLinkedList
	}
	
	bool keepLooping = true;  //inifinite menu screen until q
	
	while (keepLooping) {//only leave when q is inputted
		
		string command; //tried char, but couldn't figure out how to look at too long of input
		cout << "Enter a command: ";
		cin >> command;
		while(!cin.good()) {
					
					cin.ignore(2147483647, '\n');			//command = input
					cin.clear();
		}
		if(command.length() > 1) {
			cout << "Extracting first character in given string one moment..." << endl;
			int temp = time(NULL) + 1; //pause for 1 second, adds glitter to code.
			while(temp > time(NULL));  
		}
		switch(command.at(0)) { //takes the first character of the string, fixes the infinite loop when char more than 2 was inputted
			
			case 'i' : {
				currentList.printList();
				cout << "Enter a number: " ; 
				
				int number;
				cin >> number;
				
					DataType allData = DataType(number);
					currentList.insertItem(allData);
					
				
				cin.clear();
				currentList.printList();
			}
					break;
				
				
				
			
				break;
			case 'd' :	{
				currentList.printList();
				cout << "Enter a value to delete: ";
				
				int number;
				cin >> number;
					DataType allData = DataType(number);
					currentList.deleteItem(allData);
					currentList.printList();
					cin.clear();
			}
				break;
			case 's' : {
				cout << "Enter a value to search: ";
				int number;
				cin >> number;
					DataType allData = DataType(number);
					currentList.searchItem(allData);
					cin.clear();
			}
				break;
			case 'n' : {
				cout << "Next value is: " ;
				currentList.iterate();
				
			}
				break;
			case 'r' : {
				currentList.resetIterate();
				cout << "Iterator reset." << endl;
			}
				break;
			case 'p' : currentList.printList();
				break;
			case 'l' : {
				cout << "List length is: " << currentList.length();
				cout <<endl;
			}
				break;
			case 'b' : {
				cout << "Before pairwise swap: " << endl; 
				currentList.printList();
				cout << "After pairwise swap: " << endl;
				currentList.pairwiseSwap();
				currentList.printList();
				
			}
				break;
			case 'c' : {
				currentList.clear();
				cout << "List cleared" << endl;
			}
				break;
			case 'q' : {
				keepLooping = false; //quits
				cout << "Quitting program..."  << endl;
			}
				break;
				default: {
					cout << endl;
					cout << "Oops!  Input not valid.  Please try again!" <<  endl;
					commandList();
					cout << endl;
				}
				break;
		}
}
	return EXIT_SUCCESS;
}

