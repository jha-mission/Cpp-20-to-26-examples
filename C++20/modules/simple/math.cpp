// Each module must have a single file exporting this module.
// This file is called the
// module interface unit.

// the compiled module interface unit is
// the binary module interface (BMI), with g++ in
// gcm.cache/math.gcm

export module math;

export int add(int a, int b) {
  return a + b;
}
