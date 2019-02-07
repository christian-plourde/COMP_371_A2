#include "ShaderLoader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

//this file contains the function definition for the shader loader function

/*
 * This is the function implementation for loading shaders into a usable program
 * @param vertex_file_path: This is the file path for the vertex shader
 * @param fragment_file_path: This is the file path for the fragment shader
 * @return Returns an unsigned int that is the unique identifier for the new shader program
 */
GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path)
{
    //these are the id's of the new shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    //we will deal with the vertex shader first
    //begin by reading the code from the appropriate file
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);

    //if we have succeeded in opening our vertex shader file, read the data and place it in the vertex shader code
    //string object
    if(VertexShaderStream.is_open())
    {
        std::stringstream sstr;
        sstr << VertexShaderStream.rdbuf();
        VertexShaderCode = sstr.str();
        VertexShaderStream.close();
    }

    else
    {
        printf("Impossible to open the file at %s", vertex_file_path);
        return 0;
    }

    //Now that we have read the source code for the Vertex shader, we need to do the same but with the fragment shader
    //source code

    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);

    if(FragmentShaderStream.is_open())
    {
        std::stringstream sstr;
        sstr << FragmentShaderStream.rdbuf();
        FragmentShaderCode = sstr.str();
        FragmentShaderStream.close();
    }

    else
    {
        printf("Impossible to open the file at %s", fragment_file_path);
        return 0;
    }

    //now that we have the source code from both shaders in memory, we need to compile that source code into
    //a program that can be used by our gpu in order to modify our objects

    //first we will compile the vertex shader source code
    char const* VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
    glCompileShader(VertexShaderID);

    //now that this is done, we can compile our fragment shader
    char const* FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
    glCompileShader(FragmentShaderID);

    //now that both have been compiled we need to link them together
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    //now that the program has been linked we can detach and delete the shaders and return the program id
    glDetachShader(ProgramID, VertexShaderID);
    glDetachShader(ProgramID, FragmentShaderID);
    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
}

