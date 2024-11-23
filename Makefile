build: 
	mkdir build 

debug: build 
	gcc src/*.c -l sqlite3 -g -o build/ispdf
	
release: build
	gcc src/*.c -l sqlite3 -o build/ispdf

clean:
	rm build/*
