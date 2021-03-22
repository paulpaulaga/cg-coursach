#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include "Model.h"

using namespace std;
// fills verts and faces arrays, supposes .obj file to have "f " entries without slashes
Model::Model(const string &filename) {
  std::ifstream in(filename);
  if (in.fail()) {
    std::cerr << "Failed to open " << filename << std::endl;
    return;
  }

  std::string line;
  while (!in.eof()) {
    std::getline(in, line);
    std::istringstream iss(line);
    char trash;
    if (!line.compare(0, 2, "vertices ")) {
      iss >> trash;
      Vec3 v;
      for (int i = 0; i < 3; i++)
        iss >> v[i];
      vertices.push_back(v);
    } else if (!line.compare(0, 2, "f ")) {
      Face f;
      int idx, cnt = 0;
      iss >> trash;
      while (iss >> idx) {
        idx--; // in wavefront obj all indices start at 1, not zero
        f[cnt++] = idx;
      }
      if (3 == cnt)
        faces.push_back(f);
    }
  }
  std::cerr << "# vertices# " << vertices.size() << " f# " << faces.size() << std::endl;
}

bool Model::hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const {
  return true;
}
