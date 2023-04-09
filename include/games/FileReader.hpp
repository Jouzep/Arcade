/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** FileReader
*/

#ifndef FILEREADER_HPP_
    #define FILEREADER_HPP_
    #include <string>
    #include <vector>
    #include <fstream>

class FileReader {
    public:
        FileReader();
        FileReader(std::string filename);
        ~FileReader();

        void open(std::string filename);

        std::vector<std::string> getContent();

        class FileReaderError : public std::exception {
            public:
                FileReaderError(std::string message) {
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
        std::ifstream _file;
        std::vector<std::string> _content;
};

#endif /* !FILEREADER_HPP_ */
