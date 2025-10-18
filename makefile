bin/testListArray: testListArray.cpp list/ListArray.h list/List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp list/ListArray.h

clean:
	rm -r *.o *.gch bin
