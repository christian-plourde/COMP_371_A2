#ifndef COMP_371_A1_OBJECTLOADER_H
#define COMP_371_A1_OBJECTLOADER_H
#endif

#include "glm.hpp"
#include <vector>

//this contains the definition for the object file loader function

/*
 *This function takes in a filepath and three vectors by reference that will be filled with the data in the passed
 * obj file.
 * @param filepath: A const char* containing the path to the obj file to be loaded
 * @param out_vertices: A vector of type glm::vec3 that will hold all the vertices. Passed by reference.
 * @param out_normals: A vector of type glm::vec3 that will hold all the normals. Passed by reference.
 * @param out_uvs: A vector of type glm::vec2 that will hold all the uv values. Passed by reference.
 * @return A boolean specifying if the operation ws successful or not.
 */
bool LoadOBJ(const char* filepath, std::vector<glm::vec3>& out_vertices, std::vector<glm::vec3>& out_normals, std::vector<glm::vec2>& out_uvs);
