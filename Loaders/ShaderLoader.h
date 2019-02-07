#ifndef COMP_371_A1_SHADERLOADER_H
#define COMP_371_A1_SHADERLOADER_H
#endif
#include <glew.h>
#include <GLFW/glfw3.h>
//this contains static function definitions for the shader loader class

/*
 * This method is used to load a vertex shader and a fragment shader into a usable program and return its reference.
 */
GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);