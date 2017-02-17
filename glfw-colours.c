/* Playing around with GLFW */
#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

#define WIDTH 600
#define HEIGHT 800

void report_error(int errno, const char *desc) {
  fprintf(stderr, "Error: %s\n", desc);
}

void handle_key(GLFWwindow *win, int key, int scancode, int action, int mods) {
  static int bg = 0;

  if (action == GLFW_PRESS) {
    if (key == GLFW_KEY_ESCAPE) {
      glfwSetWindowShouldClose(win, 1);
    } else if (key == GLFW_KEY_SPACE) {
      bg ^= 1;
      if (bg) {
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f); /* Fully opaque green */
      } else {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f); /* Fully opaque blue */
      }
    }
  }
}

int main(int argc, char *argv[]) {
  if (!glfwInit()) {
    return EXIT_FAILURE;
  }

  glfwSetErrorCallback(report_error);

  GLFWwindow *win = glfwCreateWindow(WIDTH, HEIGHT, "GLFW Solid Colour", NULL, NULL);
  if (!win) {
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwSetKeyCallback(win, handle_key);

  glfwMakeContextCurrent(win);
  glfwSwapInterval(1);

  while (!glfwWindowShouldClose(win)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(win);
    glfwPollEvents();
  }

  glfwTerminate();
  return EXIT_SUCCESS;
}

