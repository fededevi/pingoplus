#pragma once

#include "parameter.h"
#include <sys/types.h>

class Attribute : public Parameter {

public:
    Attribute( ValueType _type, u_int8_t _size, const std::string & _name = "" ) :
        Parameter(_type, _name),
        size(_size)
    {}

    u_int8_t size;

};

