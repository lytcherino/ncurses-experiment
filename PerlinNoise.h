#ifndef PERLINNOISE_H
#define PERLINNOISE_H

#include <vector>

class PerlinNoise
{
  std::vector<int> p;

  double fade(double t);
  double lerp(double t, double a, double b);
  double grad(int hash, double x, double y, double z);

public:
  // Initialise with the reference values for the permutation value
  PerlinNoise();
  // Generate a new permutation vector based on the value of the seed
  PerlinNoise(unsigned int seed);
  // Get a noise value for 2D image, z can have any value
  double noise(double x, double y, double z);
};

#endif
