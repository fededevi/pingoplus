#pragma once

#include "math/vector.h"
#include "../mesh.h"
#include <array>

class Cube : public Mesh {

public:
    explicit Cube( Vec3d size = Vec3d{0.5,0.5,0.5} )
        : Mesh({{ ValueType::REAL, 3, "positions" },
                 { ValueType::INT, 1, "indices" } }),
        vertices{
            Vec3d{-size.x(), -size.y(), -size.z()},
            Vec3d{-size.x(), -size.y(),  size.z()},
            Vec3d{-size.x(),  size.y(), -size.z()},
            Vec3d{-size.x(),  size.y(),  size.z()},
            Vec3d{ size.x(), -size.y(), -size.z()},
            Vec3d{ size.x(), -size.y(),  size.z()},
            Vec3d{ size.x(),  size.y(), -size.z()},
            Vec3d{ size.x(),  size.y(),  size.z()}
        },
        indices{
            0, 1, 2, 1, 3, 2,
            1, 5, 3, 5, 7, 3,
            5, 4, 7, 4, 6, 7,
            4, 0, 6, 0, 2, 6,
            4, 5, 0, 5, 1, 0,
            2, 3, 6, 3, 7, 6
        }
    {
        attributes[0].data = &vertices;
        attributes[1].data = &indices;
    }

    std::array<Vec3d, 8> vertices;
    std::array<Vec3d, 36> indices;
};
