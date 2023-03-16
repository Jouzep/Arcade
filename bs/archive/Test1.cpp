#include <string>
#include <iostream>
extern "C"
{
int entryPoint ()
{
    std::cout << "entryPoint" << std::endl;
    return 1;
}
}