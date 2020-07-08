#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "geometry.h"

class Model
{
public:
    Model();
    Model(const char *filename);
    int verts_count();
    int faces_count();
    Vec3f vert(int i);
    std::vector<int> face(int i);
private:
    std::vector<Vec3f> verts_;
    std::vector<std::vector<int> > faces_;
};

#endif // MODEL_H
