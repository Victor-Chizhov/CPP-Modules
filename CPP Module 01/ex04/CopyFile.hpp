#ifndef COPYFILE_HPP
#define COPYFILE_HPP

#include <iostream>
#include <fstream>

class CopyFile {

    private:
        std::ifstream sourceFile;
        std::ofstream destFile;
        std::string fileName;
        std::string string1;
        std::string string2;
        std::string destString;
        std::string newString;

    
    public:
        void copyArguments(char *str1, char *str2, char *str3);
        void openSourceFile(std::string fileName);
        void createDestFile();
        void copyFromSourceInString();
        void replaceStringInString();
        std::string getFileName();

};


#endif