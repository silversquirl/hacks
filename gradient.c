#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <MiniFB.h>

#define WIDTH 800
#define HEIGHT 600
#define PI 3.141592653589793238264623

int main(int argc, char *argv[]) {
  uint32_t buf[WIDTH * HEIGHT];

  for (size_t y = 0; y < HEIGHT; y++) {
    for (size_t x = 0; x < WIDTH; x++) {
      buf[x+(y*WIDTH)] = MFB_RGB(
          (uint8_t)(256 * sin(x/(double)WIDTH)),
          (uint8_t)(256 * sin(1-x/(double)WIDTH)),
          (uint8_t)(256 * sin(y/(double)HEIGHT))
        );
    }
  }

  mfb_open("Gradient", WIDTH, HEIGHT);
  while (!mfb_update(buf)) {
    usleep(10000);
  }

  return EXIT_SUCCESS;
}

