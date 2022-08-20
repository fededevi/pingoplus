#pragma once

#include "attribute.h"
#include "parameter.h"
#include <vector>

class Mesh {

public:
    explicit Mesh(const std::vector<Attribute> & _attributes,
         const std::vector<Parameter> & _parameter = {}) :
        attributes(_attributes),
        parameters(_parameter)
    {

    }

    std::vector<Attribute> attributes;
    std::vector<Parameter> parameters;
};
