/*
** EPITECH PROJECT, 2023
** bs
** File description:
** DLLoader
*/

#include <dlfcn.h>
#include <string>

template <typename T>
class DLLoader
{
public:
    DLLoader(std::string path)
    {
        loadInstance(path);
    };
    ~DLLoader()
    {
        closeInstance();
    };
    void loadInstance(std::string path)
    {
        _handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!_handle) {
            std::cout << dlerror() << std::endl;
            std::cout << "Error open" << std::endl;
        }
        void *(*tmp)() = (void *(*)())dlsym(_handle, "entryPoint");
        if (!tmp)
            std::cout << "Error find entryPoint" << std::endl;
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
};