/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** ConfHandler
*/

#ifndef CONFHANDLER_HPP_
    #define CONFHANDLER_HPP_
    #include <string>
    #include <fstream>
    #include <iostream>
    #include <sstream>
    #include <map>

class ConfHandler {
    public:
        ConfHandler();
        ConfHandler(std::string configFile);
        ~ConfHandler();

        void setConfigFile(std::string configFile);

        std::string getConfigFileName();
        std::map<std::string, std::string> getConfigData();

        class ConfHandlerError : public std::exception {
            public:
                ConfHandlerError(std::string message) {
                    _message = message;
                }
                virtual const char* what() const noexcept {
                    return _message.c_str();
            }
            private:
                std::string _message;
        };
    protected:
    private:
        void storeConfigToMap();
        std::string _configFile;
        std::ifstream _file;
        std::map<std::string, std::string> _configs;
};

#endif /* !CONFHANDLER_HPP_ */
