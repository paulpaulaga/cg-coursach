#include "model.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Model::Model(const char *filename)
{
    ifstream in(filename);
    if (in.fail())
    {
        cerr << "File doesn't exist" << endl;;
        return;
    }
    string line;
    while(getline(in, line))
    {
        istringstream stream(line);
        char trash;
        if (!line.compare(0, 2, "v "))
        {
            stream >> trash;
            Vec3f v;

            stream >> v.x;
            stream >> v.y;
            stream >> v.z;

            verts_.push_back(v);
        }
        else if (!line.compare(0, 2, "f "))
        {
            int itrash, idx;
            vector<int> f;
            stream >> trash;
            while (stream >> idx >> trash >> itrash >> trash >> itrash)
            {
                idx--;
                f.push_back(idx);
            }
            faces_.push_back(f);
        }
    }
    cerr << "# v #" << verts_.size() << " f #" << faces_.size() << endl;
}

int Model::verts_count()
{
    return (int)verts_.size();
}

int Model::faces_count()
{
    return (int)faces_.size();
}

Vec3f Model::vert(int i)
{
    return verts_[i];
}

vector<int> Model::face(int i)
{
    return faces_[i];
}
