#include <stdlib.h>
#include <stdio.h>
#include "../include/conversions.h"

int main() {  
    xyBri_t xyBri;
    xyBri.x = 0x69E1;
    xyBri.y = 0x6F3E;
    xyBri.bri = 254;
    RGB_t rgb = xyBriToRgb(xyBri);

    printf("R = %d\n", rgb.R);
    printf("G = %d\n", rgb.G);
    printf("B = %d\n", rgb.B);
  

  return 0;
}
