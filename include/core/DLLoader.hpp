/*
** EPITECH PROJECT, 2023
** bs
** File description:
** DLLoader
*/

#include <dlfcn.h>
#include <string>
#include "Error.hpp"
template <typename T>
class DLLoader
{
public:
    DLLoader() = default;
    DLLoader(std::string path)
    {
        _path = path;
    };
    ~DLLoader()
    {
        closeInstance();
    };
    void setLib(std::string path)
    {
        _path = path;
    };
    std::string getLibName() { return _path; }
    void loadInstance()
    {
        _handle = dlopen(_path.c_str(), RTLD_LAZY);
        if (!_handle)
        {
            std::cout << "Error open" << std::endl;
            std::cout << dlerror() << std::endl;
            throw Error(dlerror(), _path);
        }
        void *(*tmp)() = (void *(*)())dlsym(_handle, "entryPoint");
        if (!tmp) {
            throw Error(dlerror(), _path);
        }
        _lib = static_cast<T *>(tmp());
        // std::cout << "Instance Loaded" << std::endl;
    };
    T *getInstance(void) const
    {
        return _lib;
    };
    void closeInstance(void)
    {
        if (_lib)
            delete (_lib);
        if (_handle)
            dlclose(_handle);
        _handle = nullptr;
        _lib = nullptr;
        // std::cout << "destroyed" << std::endl;
    }

private:
    void *_handle;
    T *_lib;
    std::string _path;
};