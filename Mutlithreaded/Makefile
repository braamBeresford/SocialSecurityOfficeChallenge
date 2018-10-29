CC= g++ -std=c++17
exe_file = ssMulti 

$(exe_file): ssMulti.o
	$(CC) ssMulti.o -o $(exe_file)

clean:
		rm -f *.out *.o *~ $(exe_file) *.txt
run: $(exe_file)
	./$(exe_file)

ssMulti.o: ssMulti.cpp
	$(CC) -c ssMulti.cpp
