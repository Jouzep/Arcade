g++ -c -fPIC Foo.cpp
g++ -shared -o FooLib.so Foo.o
g++ main.cpp -ldl -g