#include "CopyFile.hpp"

void CopyFile::openSourceFile(std::string fileName) {
    sourceFile.open(fileName);
    if(!sourceFile) {
        std::cerr << "Error opening file." << std::endl;
        exit(1);
    }
}

void CopyFile::copyArguments(char *str1, char *str2, char *str3) {
    fileName = str1;
    string1 = str2;
    string2 = str3;
}

std::string CopyFile::getFileName() { return fileName; }   

void CopyFile::createDestFile() {
    destFile.open(fileName + ".replace");
    if(!destFile) {
        std::cerr << "Error opening destination file." << std::endl;
        exit(1);
    }
    destFile << newString;
    destFile.close();
}

void CopyFile::copyFromSourceInString() {
    
    char ch;

    while (sourceFile.get(ch)) {
        destString += ch;
    }
    sourceFile.close();
}

void CopyFile::replaceStringInString() {
    
    size_t pos = 0;
    size_t lastPos = 0;

    while ((pos = destString.find(string1, lastPos)) != std::string::npos) {
        newString.append(destString, lastPos, pos - lastPos);
        newString.append(string2);
        lastPos = pos + string1.length();
    }

    newString.append(destString, lastPos);
}