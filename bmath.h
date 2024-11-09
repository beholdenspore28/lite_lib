/*----------------------------------LEGAL--------------------------------------

MIT License

Copyright (c) 2023 Benjamin Joseph Brooks

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

-----------------------------------------------------------------------------*/

#pragma once

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FLOAT_EPSILON (1e-4)
#define PI 3.14159265358

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

static inline float rad2deg(const float n) { return n * (180.0f / PI); }

static inline float deg2rad(const float n) { return n * (PI / 180.0f); }

static inline float wrapAngle(float a) {
  a = fmod(a, 2 * PI);
  if (a < 0) {
    a += 2 * PI;
  }
  return a;
}

static inline float clamp(float n, const float min, const float max) {
  n = n < min ? min : n;
  return n > max ? max : n;
}

static inline float clamp01(float n) {
  n = n < 0 ? 0 : n;
  return n > 1 ? 1 : n;
}

static inline float lerp(float a, float b, float t) { return a + (b - a) * t; }

static inline float lerpclamped(float a, float b, float t) {
  return a + (b - a) * clamp01(t);
}

static inline float norm(float n, float min, float max) { return (n - min) / (max - min); }

static inline float map(float n, float fromMin, float fromMax, float toMin, float toMax) {
  //return lerp(norm(n, fromMin, fromMax), toMin, toMax);
  return (n - fromMin) * (toMax - toMin) / (fromMax - fromMin) + toMin;
}

static inline int aproxequal(float a, float b, float tolerance) {
  return (fabs(a - b) < tolerance);
}

static inline float cosInterpolate(float a, float b, float t) {
  float f = (1.0f - cos(t * PI)) * 0.5f;
  return a * (1.0 - f) + b * f;
}

static inline float sigmoid(float n) { return (1 / (1 + pow(2.71828182846, -n))); }

static inline float loop(float n, const float length) {
  return clamp(n - floor(n / length) * length, 0.0f, length);
}

static inline float pingpong(float n, const float length) {
  n = loop(n, length * 2.0f);
  return fabs(n - length);
}

static inline float angleDelta(const float a, const float b) {
  float delta = loop((b - a), 360.0f);
  if (delta > 180.0f) {
    delta -= 360.0f;
  }
  return delta;
}

static inline float fraction(float x) {
  return x - floorf(x);
}

// Single dimensional pseudo-random noise
static inline float noise1(int x) {
  float wave = sinf(x*53)*6151;
  return fraction(wave);
}

// Two dimensional pseudo-random noise
static inline float noise2(int x, int y) {
  float wave = sinf(x*53+y*97)*6151;
  return fraction(wave);
}

// Three dimensional pseudo-random noise
static inline float noise3(int x, int y, int z) {
  float wave = sinf(x*53+y*97+z*193)*6151;
  return fraction(wave);
}

// Three dimensional pseudo-random noise
#if 0
static inline float noise3_interpolated(float x, float y, float z) {
  float c = noise3(x, y, z);

  float fractX = fraction(x);
  float fractY = fraction(y);
  float fractZ = fraction(z);

  float floorX = floor(x);
  float floorY = floor(y);
  float floorZ = floor(z);

  float bbl = noise3(floorX, floorY, floorZ);
  float bbr = noise3(floorX + 1, floorY, floorZ);
  float bb = cosInterpolate(bbl, bbr, fractX);

  float btl = noise3(floorX, floorY + 1, floorZ);
  float btr = noise3(floorX + 1, floorY + 1, floorZ);
  float bt = lerp(btl, btr, fractX);

  float fbl = noise3(floorX, floorY, floorZ);
  float v6 = noise3(floorX + 1, floorY, floorZ);
  float fb = lerp(fbl, v6, fractX);

  float v7 = noise3(floorX, floorY + 1, floorZ);
  float v8 = noise3(floorX + 1, floorY + 1, floorZ);
  float ft = lerp(v7, v8, fractX);

  float fbt = lerp(fb, ft, fractY);
  float s2 = lerp(bb, bt, fractY);

  float fbts2 = lerp(fbt, s2, fractZ);
  return fbts2 / 50; 
}
#else
static inline float noise3_interpolated(float x, float y, float z) {
  float fractX = fraction(x),
        fractY = fraction(y),
        fractZ = fraction(z),

        floorX = floor(x),
        floorY = floor(y),
        floorZ = floor(z);

  // interpolate between adjacent noise values
  // ==================================================
  // two vertices 'v' make an edge 'e' 
  // two edges make a face 'f'
  // two faces make a cube.
  // ==================================================
  
  //===================================================
  float v1 = noise3( floorX,     floorY,     floorZ),
        v2 = noise3( floorX + 1, floorY,     floorZ),
        e1 = cosInterpolate(v1, v2, fractX), // rear bottom

        v3 = noise3( floorX,     floorY + 1, floorZ),
        v4 = noise3( floorX + 1, floorY + 1, floorZ),
        e2 = cosInterpolate(v3, v4, fractX), // rear top

        v5 = noise3( floorX,     floorY,     floorZ + 1),
        v6 = noise3( floorX + 1, floorY,     floorZ + 1),
        e3 = cosInterpolate(v5, v6, fractX), // front bottom

        v7 = noise3( floorX,     floorY + 1, floorZ + 1),
        v8 = noise3( floorX + 1, floorY + 1, floorZ + 1),
        e4 = cosInterpolate(v7, v8, fractX), // front top

        f1 = cosInterpolate(e1, e2, fractY),
        f2 = cosInterpolate(e3, e4, fractY),
        cube  = cosInterpolate(f1, f2, fractZ);

  return cube / 50; 
}
#endif

static inline float noise3_perlin(float x, float y, float z) {
  float total = 0.0;
  float freq = 1.0;
  float amplitude = 1.0;
  float persistance = 0.5;
  int octaves = 16;
  for (int i = 0; i < octaves; i++) {
    freq = pow(2, i);
    amplitude = pow(persistance, i);
    total += noise3_interpolated(x*freq, y*freq, z*freq) * amplitude; 
  }
  return total;
}

#ifdef __cplusplus
} // extern "C" {
#endif // __cplusplus
