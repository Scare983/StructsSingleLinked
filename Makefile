OBJS		= Main.o DataType.o SortedLinkedList.o
COMPILE		= g++ -g -c -std=gnu++0x -o $@

# the main target
main: $(OBJS)
	g++ -o $@ $(OBJS)
	
# dependencies
Main.o: Main.cpp
	$(COMPILE) Main.cpp
	
DataType.o: DataType.h DataType.cpp
	$(COMPILE) DataType.cpp
	
SortedLinkedList.o: SortedLinkedList.h ListNode.h SortedLinkedList.cpp
	$(COMPILE) SortedLinkedList.cpp
	
clean:
	$(RM) $(OBJS)
	
cleanall: clean
	$(RM) main
