#pragma once

/*A small data structure for storing 2D positions, rotations, scales,
 * or lines.*/
typedef struct {
  float x;
  float y;
} vec2;

/*A small data structure for storing 3D positions, rotations, scales,
 * or lines.*/
typedef struct {
  float x;
  float y;
  float z;
} vec3;

/*A small data structure for storing 4D values*/
typedef struct {
  float x;
  float y;
  float z;
  float w;
} vec4;

/*A column major 4x4 matrix*/
typedef struct{
  float elements[16];
} mat4;


typedef struct {
	float x;
	float y;
	float z;
	float w;
} quat;

#define QUATERNION_IDENTITY (quat){0.0f, 0.0f, 0.0f, 1.0f}


#define VEC2_ZERO          					                                                 \
  (vec2) { 0.0f, 0.0f }
#define VEC2_ONE(scalar)   					                                                \
  (vec2) { scalar, scalar }
#define VEC2_UP(scalar)      					                                                 \
  (vec2) { 0.0f, scalar }
#define VEC2_DOWN(scalar)  					                                                 \
  (vec2) { 0.0f, -scalar }
#define VEC2_LEFT(scalar)                                                             \
  (vec2) { -scalar, 0.0f }
#define VEC2_RIGHT(scalar)                                                            \
  (vec2) { scalar, 0.0f }

#define VEC3_ZERO     				                                                        \
  (vec3) { 0.0f, 0.0f, 0.0f }
#define VEC3_ONE(scalar)                                                              \
  (vec3) { scalar, scalar, scalar }
#define VEC3_UP(scalar)                                                               \
  (vec3) { 0.0f, scalar, 0.0f }
#define VEC3_DOWN(scalar)                                                             \
  (vec3) { 0.0f, -scalar, 0.0f }
#define VEC3_LEFT(scalar)                                                             \
  (vec3) { -scalar, 0.0f, 0.0f }
#define VEC3_RIGHT(scalar)                                                            \
  (vec3) { scalar, 0.0f, 0.0f }
#define VEC3_FORWARD(scalar)                                                          \
  (vec3) { 0.0f, 0.0f, scalar }
#define VEC3_BACK(scalar)                                                             \
  (vec3) { 0.0f, 0.0f, -scalar }

#define VEC4_ZERO                                                             \
  (vec4) { 0.0f, 0.0f, 0.0f, 1.0f }
#define VEC4_ONE(scalar)                                                              \
  (vec4) { scalar, scalar, scalar, scalar }
#define VEC4_UP(scalar)                                                               \
  (vec4) { 0.0f, scalar, 0.0f, scalar }
#define VEC4_DOWN(scalar)                                                             \
  (vec4) { 0.0f, -scalar, 0.0f, scalar }
#define VEC4_LEFT(scalar)                                                             \
  (vec4) { -scalar, 0.0f, 0.0f, scalar }
#define VEC4_RIGHT(scalar)                                                            \
  (vec4) { scalar, 0.0f, 0.0f, scalar }
#define VEC4_FORWARD(scalar)                                                          \
  (vec4) { 0.0f, 0.0f, scalar, scalar }
#define VEC4_BACK(scalar)                                                             \
  (vec4) { 0.0f, 0.0f, -scalar, scalar }

/*Prints a vector "v" using printf*/
void vec2_printf (const vec2 v, const char *label);

/*Returns a vector that points in the opposite direction of the given vector
"v". The vector returned has a magnitude identical to the given vector "v"*/
vec2 vec2_negate (vec2 v);

/*Returns the actual length of a vector "v".
This uses a square root operation. Use vec2_sqrmagnitude()
to sacrifice accuracy and save on performance when comparing
distances.*/
float vec2_magnitude (vec2 v);

/*A more performant way of getting the relative length of a
vector "v". This saves a square root operation making it more
performant than vec2_magnitude(). If all you have to do is
compare a vectors length relatively, use this function instead of
vec2_magnitude()*/
float vec2_sqrmagnitude (vec2 v);

/*Returns a given vector "v" as a unit vector.
This means the magnitude(length) of the returned
vector will always be 1 unit. The returned vector always points
in the same direction as the given vector "v"*/
vec2 vec2_normalize (vec2 v);

/*Returns the distance between point a and point b
in units.*/
float vec2_distance (vec2 a, vec2 b);

/*Adds a vector "a" to another vector "b"*/
vec2 vec2_add (vec2 a, vec2 b);

/*Subtracts a vector "subtrahend" from another vector "minuend"*/
vec2 vec2_subtract (vec2 minuend, vec2 subtrahend);

/*Scales a vector "v" by "scalar".
increases the magnitude when "scalar" is greater than 1.
decreases the magnitude when "scalar" is less than 0.
The returned vector will point in the same direction as
the given vector "v".*/
vec2 vec2_scale (vec2 v, float scalar);

/*For normalized vectors Dot returns 1 if they point in
exactly the same direction, -1 if they point in completely opposite directions
and zero if the vectors are perpendicular.*/
float vec2_dot (vec2 a, vec2 b);

/*Linearly interpolates between "a" and "b" by "t".
If you want to make sure the returned value stays
between "a" and "b", use vec3_lerpclamped() instead.
Returns a point at "t"% of the way between "a" and "b".*/
vec2 vec2_lerp (vec2 a, vec2 b, float t);

/*Linearly interpolates between "a" and "b" by "t".
Returns a point at "t"% of the way between "a" and "b".*/
vec2 vec2_lerpclamped (vec2 a, vec2 b, float t);

/*Converts a 2 dimensional vector to a 3 dimensional one*/
vec3 vec2_toVec3 (vec2 v);

/*Converts a 2 dimensional vector to a 4 dimensional one*/
vec4 vec2_toVec4 (vec2 v);

/*Prints a vector "v" using printf*/
void vec3_printf (const vec3 v, const char *label);

/*Returns a vector that points in the opposite direction of the given vector
"v". The vector returned has a magnitude identical to the given vector "v"*/
vec3 vec3_negate (vec3 v);

/*Returns the actual length of a vector "v".
This uses a square root operation. Use vec3_sqrmagnitude()
to sacrifice accuracy and save on performance when comparing
distances.*/
float vec3_magnitude (vec3 v);

/*A more performant way of getting the relative length of a
vector "v". This saves a square root operation making it more
performant than vec3_magnitude(). If all you have to do is
compare a vectors length relatively, use this function instead of
vec3_magnitude()*/
float vec3_sqrmagnitude (vec3 v);

/*Returns a given vector "v" as a unit vector.
This means the magnitude(length) of the returned
vector will always be 1 unit. The returned vector always points
in the same direction as the given vector "v"*/
vec3 vec3_normalize (vec3 v);

/*Returns the distance between point a and point b
in units.*/
float vec3_distance (vec3 a, vec3 b);

/*Adds a vector "a" to another vector "b"*/
vec3 vec3_add (vec3 a, vec3 b);

/*Subtracts a vector "subtrahend" from another vector "minuend"*/
vec3 vec3_subtract (vec3 minuend, vec3 subtrahend);

/*Scales a vector "v" by "scalar".
increases the magnitude when "scalar" is greater than 1.
decreases the magnitude when "scalar" is less than 1.
The returned vector will point in the same direction as
the given vector "v".*/
vec3 vec3_scale (vec3 v, float scalar);

/*Returns a vector parallel to both "a" and "b".*/
vec3 vec3_cross (vec3 a, vec3 b);

/*For normalized vectors Dot returns 1 if they point in
exactly the same direction, -1 if they point in completely opposite directions
and zero if the vectors are perpendicular.*/
float vec3_dot (vec3 a, vec3 b);

/*Linearly interpolates between "a" and "b" by "t".
If you want to make sure the returned value stays
between "a" and "b", use vec2_lerpclamped() instead.
Returns a point at "t"% of the way between "a" and "b".*/
vec3 vec3_lerp (vec3 a, vec3 b, float t);

/*Linearly interpolates between "a" and "b" by "t".
Returns a point at "t"% of the way between "a" and "b".*/
vec3 vec3_lerpclamped (vec3 a, vec3 b, float t);

/*Returns a vector that is made from the largest components of two
vectors.*/
vec3 vec3_max (vec3 a, vec3 b);

/*Returns a vector that is made from the smallest components of two
vectors.*/
vec3 vec3_min (vec3 a, vec3 b);

/*Converts a 3 dimensional vector to a 2 dimensional one*/
vec2 vec3_toVec2 (vec3 v);

/*Converts a 3 dimensional vector to a 4 dimensional one*/
vec4 vec3_toVec4 (vec3 v);

/*Prints a vector "v" using printf*/
void vec4_printf (const vec4 v, const char *label);

/*Returns a vector that points in the opposite direction of the given vector
"v". The vector returned has a magnitude identical to the given vector "v"*/
vec4 vec4_negate (vec4 v);

/*Returns the actual length of a vector "v".
This uses a square root operation. Use vec4_sqrmagnitude()
to sacrifice accuracy and save on performance when comparing
distances.*/
float vec4_magnitude (vec4 v);

/*A more performant way of getting the relative length of a
vector "v". This saves a square root operation making it more
performant than vec4_magnitude(). If all you have to do is
compare a vectors length relatively, use this function instead of
vec4_magnitude()*/
float vec4_sqrmagnitude (vec4 v);

/*Returns a given vector "v" as a unit vector.
This means the magnitude(length) of the returned
vector will always be 1 unit. The returned vector always points
in the same direction as the given vector "v"*/
vec4 vec4_normalize (vec4 v);

/*Returns the distance between point a and point b
in units.*/
float vec4_distance (vec4 a, vec4 b);

/*Adds a vector "a" to another vector "b"*/
vec4 vec4_add (vec4 a, vec4 b);

/*Subtracts a vector "subtrahend" from another vector "minuend"*/
vec4 vec4_subtract (vec4 minuend, vec4 subtrahend);

/*Scales a vector "v" by "scalar".
increases the magnitude when "scalar" is greater than 1.
decreases the magnitude when "scalar" is less than 1.
The returned vector will point in the same direction as
the given vector "v".*/
vec4 vec4_scale (vec4 v, float scalar);

/*For normalized vectors Dot returns 1 if they point in
exactly the same direction, -1 if they point in completely opposite directions
and zero if the vectors are perpendicular.*/
float vec4_dot (vec4 a, vec4 b);

/*Linearly interpolates between "a" and "b" by "t".
If you want to make sure the returned value stays
between "a" and "b", use vec2_lerpclamped() instead.
Returns a point at "t"% of the way between "a" and "b".*/
vec4 vec4_lerp (vec4 a, vec4 b, float t);

/*Linearly interpolates between "a" and "b" by "t".
Returns a point at "t"% of the way between "a" and "b".*/
vec4 vec4_lerpclamped (vec4 a, vec4 b, float t);

/*Returns a vector that is made from the largest components of two
vectors.*/
vec4 vec4_max (vec4 a, vec4 b);

/*Returns a vector that is made from the smallest components of two
vectors.*/
vec4 vec4_min (vec4 a, vec4 b);

/*Converts a 4 dimensional vector to a 2 dimensional one*/
vec2 vec4_toVec2 (vec4 v);

/*Converts a 4 dimensional vector to a 3 dimensional one*/
vec3 vec4_toVec3 (vec4 v);

extern const mat4 MAT4_IDENTITY;

mat4 mat4_lookAt (vec3 eye, vec3 center, vec3 up);
/*Perspective transformation used for calculating depth*/
mat4 mat4_perspective (float fov, float aspect, float near, float far);
/*Adds a 4x4 matrix to another 4x4 matrix.*/
mat4 mat4_add (mat4 a, mat4 b);

/*Returns the difference between two 4x4 matrices.*/
mat4 mat4_subtract (mat4 min, mat4 sub);

/*Prints a formatted mat4 to the console.*/
void mat4_printf (mat4 m, const char *label);

/*Scales (multiplies) a 4x4 matrix by a scalar (number)*/
mat4 mat4_scale (const vec3 scale);

/*Returns a rotation matrix around "axis" by "angle"*/
mat4 mat4_rotate (const float angle, vec3 axis);

/*Translates a vector to a 4x4 matrix*/
mat4 mat4_translateVec3 (vec3 t);

/*Translates a vector to a 4x4 matrix*/
mat4 mat4_translateVec4 (vec4 t);

/*Multiplies a 4x4 matrix with another 4x4 matrix*/
mat4 mat4_multiply (const mat4 a, const mat4 b);

/*Multiplies a 4x4 matrix with a 4 dimensional vector*/
vec3 mat4_multiplyVec3(vec3 Left, mat4 Right);

/*Multiplies a 4x4 matrix with a 4 dimensional vector*/
vec4 mat4_multiplyVec4(vec4 Left, mat4 Right);

/*
Returns the quaternion t% from qa to qb
*/
quat quat_slerp(quat qa, quat qb, double t);

/*
The negative of a quaternion:
(-a, -b, -c, -d)
*/
quat quat_negate(quat q);

/*
The conjugate of a quaternion:
(-x, -y, -z, w)
*/
quat quat_conj(quat q);

/*
Addition of a real number   r   and a quaternion   q:
r + q = q + r = (a+r, b, c, d)
*/
quat quat_addReal(quat quat, float real);

/*
Addition of two quaternions:
q1 + q2 = (a1+a2, b1+b2, c1+c2, d1+d2)
*/
quat quat_add(quat q1, quat q2);

/*
Multiplication of a real number and a quaternion:
qr = rq = (ar, br, cr, dr)
*/
quat quat_scale(quat q, float scalar);

/*
Multiplication of two quaternions   q1   and   q2   is given by:
q1q2 ≠ q2q1
*/
quat quat_mult(quat q1, quat q2);

/*Dot product of two quaternions*/
float quat_dot(quat a, quat b);

/*
Returns 1 if q1 is equal to q2.
Returns 0 if q1 is not equal to q2.
*/
int quat_equal(quat q1, quat q2);

/*
Prints the given quaternion to standard out.
*/
void quat_print(quat q, const char* label);

/*
Returns the squared magnitude of a given quaternion
*/
float quat_sqrmag(quat q);

/*
Returns the magnitude of a given quaternion.
*/
float quat_mag(quat q);

/*
Returns the given euler angles converted to a quaternion.
*/
quat quat_fromEuler(vec3 eulerAngles);

/*
Returns the given quaternion converted to euler angles.
*/
vec3 quat_toEuler(quat q);

/*
Returns a quaternion representing the given rotation by 'angle' around 'axis'.
*/
quat quat_angleAxis(float angle, vec3 axis);

quat quat_set(float x, float y, float z, float w);

mat4 quat_toMat4(quat q);
