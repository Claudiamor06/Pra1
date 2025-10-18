bin/testListArray: testListArray.cpp list/ListArray.h list/List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp list/ListArray.h

clean:
	rm -r *.o *.gch bin

bin/testNode: testNode.cpp list/Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp 
