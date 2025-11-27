
testListArray: praF_Array.cpp ListArray.h List.h
	g++ -o testListArray praF_Array.cpp

testListLinked: praF_Linked.cpp ListLinked.h Node.h List.h
	g++ -o testListLinked praF_Linked.cpp

clean:
	rm -f testListArray testListLinked *.o *.gch

