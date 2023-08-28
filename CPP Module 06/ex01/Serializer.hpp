#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

struct Data { std::string s1; int n; std::string s2; };

class Serializer {

    private:
        Serializer();
        Serializer(Serializer const &src);
        Serializer& operator=(Serializer const &copy);
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);


};


#endif