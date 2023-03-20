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
    void setLib(std::string path) {
        _path = path;
    };
    void loadInstance()
    {
<<<<<<< HEAD
        _handle = dlopen(_path.c_str(), RTLD_LAZY);
        if (!_handle) {
            std::cout << dlerror() << std::endl;
            std::cout << "Error open" << std::endl;
=======
        _handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!_handle)
        {
            // std::cout << dlerror() << std::endl;
            // std::cout << "Error open" << std::endl;
            throw Error(dlerror(), path);
>>>>>>> 6435120 (21 : feat : adding throw error on DLLib)
        }
        void *(*tmp)() = (void *(*)())dlsym(_handle, "entryPoint");
        if (!tmp)
            throw Error(dlerror(), path);
        _lib = static_cast<T *>(tmp());
        std::cout << "Instance Loaded" << std::endl;
    };
    T *getInstance(void) const
    {
        return _lib;
    };
    void closeInstance(void)
    {
        if (_handle)
            dlclose(_handle);
        // if (_lib)
        //     delete (_lib);
        _handle = nullptr;
        _lib = nullptr;
    }

private:
    void *_handle;
    T *_lib;
    std::string _path;
};