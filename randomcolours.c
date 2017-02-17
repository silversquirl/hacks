#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <MiniFB.h>
#include <string.h>
#include <stdint.h>

#define WIDTH 800
#define HEIGHT 600

int tr, tg, tb;
int r, g, b;

int paint() {
  uint32_t buf[WIDTH * HEIGHT];
  for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
    buf[i] = MFB_RGB(r, g, b);
  }
  return mfb_update(buf);
}

void newtarget() {
  tr = random() % 255;
  tg = random() % 255;
  tb = random() % 255;
}

void step() {
  if (r > tr) r--;
  else if (r < tr) r++;

  if (g > tg) g--;
  else if (g < tg) g++;

  if (b > tb) b--;
  else if (b < tb) b++;
}

int main(int argc, char *argv[]) {
  mfb_open("Random Colour Generator", WIDTH, HEIGHT);

  newtarget();
  while (!paint()) {
    usleep(10000);
    step();
    // int i = r, j = g, k = b;
    // newtarget();
    if (r == tr && g == tg && b == tb) {
      paint();
      // step();
      newtarget();
    }
  }

  mfb_close();

  return EXIT_SUCCESS;
}

