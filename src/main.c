#include <stdlib.h>
#include <stdio.h>
#include "../include/conversions.h"

int main() {
  float x = 0x52ad;
  float y = 0x3acb;
  
  xyBri_t xyBri;
  xyBri.x = x/65536;
  xyBri.y = y/65536;
  xyBri.bri = 55;
  RGB_t rgb = xyBriToRgb(xyBri);

  printf("R = %d\n", rgb.R);
  printf("G = %d\n", rgb.G);
  printf("B = %d\n", rgb.B);

  return 0;
}
