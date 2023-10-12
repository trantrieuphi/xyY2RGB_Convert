#include "../include/conversions.h"
#include <math.h>

RGB_t xyBriToRgb(xyBri_t xyBri) {
  float X, Y, Z, z, r, g, b, maxValue;

  // Calculate the XYZ values from the xyBri values.
  z = 1.0 - xyBri.x - xyBri.y;
  Y = xyBri.bri / 255.0;
  X = (Y / xyBri.y) * xyBri.x;
  Z = (Y / xyBri.y) * z;

  // Apply gamma correction.
  r = X * 1.612 - Y * 0.203 - Z * 0.302;
  g = -X * 0.509 + Y * 1.412 + Z * 0.066;
  b = X * 0.026 - Y * 0.072 + Z * 0.962;

  // Clamp the RGB values to the range [0.0, 1.0].
  r = r <= 0.0031308 ? 12.92 * r : (1.0 + 0.055) * pow(r, (1.0 / 2.4)) - 0.055;
  g = g <= 0.0031308 ? 12.92 * g : (1.0 + 0.055) * pow(g, (1.0 / 2.4)) - 0.055;
  b = b <= 0.0031308 ? 12.92 * b : (1.0 + 0.055) * pow(b, (1.0 / 2.4)) - 0.055;

  // Find the maximum RGB value.
  maxValue = fmax(r, fmax(g, b));

  // Normalize the RGB values.
  r /= maxValue;
  g /= maxValue;
  b /= maxValue;

  // Scale the RGB values to the range [0, 255].
  r *= 255.0;
  if (r < 0.0) { r = 255.0; }
  g *= 255.0;
  if (g < 0.0) { g = 255.0; }
  b *= 255.0;
  if (b < 0.0) { b = 255.0; }

  // Return the RGB values.
  RGB_t rgb = {(uint8_t)r, (uint8_t) g, (uint8_t) b};
  return rgb;
}
