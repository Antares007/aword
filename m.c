#include <stdio.h>
#include <math.h>

int main() {
  float m[3][3], fTheta = -M_PI_2, out_x,out_y,in_x,in_y;
  m[0][0] = cosf(fTheta);  m[1][0] = sinf(fTheta); m[2][0] = 0.0f;
  m[0][1] = -sinf(fTheta); m[1][1] = cosf(fTheta); m[2][1] = 0.0f;
  m[0][2] = 0.0f;          m[1][2] = 0.0f;         m[2][2] = 1.0f;

  printf("%f\t%f\t%f\n", m[0][0], m[1][0], m[2][0]);
  printf("%f\t%f\t%f\n", m[0][1], m[1][1], m[2][1]);
  printf("%f\t%f\t%f\n", m[0][2], m[1][2], m[2][2]);

  in_x =0, in_y =-1;
  printf("f = %f\n", fTheta);
  printf("x' = x * %f + y * %f\n",m[0][0],m[1][0]);
  printf("y' = x * %f + y * %f\n",m[0][1],m[1][1]);
  out_x = in_x * m[0][0] + in_y * m[1][0] + m[2][0];
  out_y = in_x * m[0][1] + in_y * m[1][1] + m[2][1];
  printf("%f,%f\n", out_x, out_y);
}
