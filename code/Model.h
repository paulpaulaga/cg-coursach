//
// Created by Pavel Cheklin on 16.02.2021.
//

#ifndef TEST_CODE__MODEL_H
#define TEST_CODE__MODEL_H

#include "Hittable.h"
#include <array>
#include <unordered_map>
#include <map>

using Face = std::array<int, 3>;

class Model : public HittableObject {
public:
  explicit Model(const std::string &filename);

  bool hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const override;
private:
  std::vector<Point3> vertices;
  std::vector<Face> faces;
};

#endif //TEST_CODE__MODEL_H

