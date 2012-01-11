make: main.cpp
	g++ -o a.out main.cpp -I. && ./a.out http://user:password@www.google.com:80/path?search
