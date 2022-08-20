#pragma once

#include "valuetype.h"
#include <string>
#include <sys/types.h>

class Parameter {

public:
    explicit Parameter( ValueType _type, const std::string & _name = "" ):
        name(_name),
        type(_type)
    {}

    u_int32_t count;
    ValueType type;
    std::string name;
    void * data;

};
