#include "KeyboardControls.h"
#include "../Loaders/ShaderLoader.h"
#include <iostream>

void key_press_w(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the w key is pressed on the keyboard, we should move the camera toward the object
    //this is done by translating the View matrix in the x direction and then resetting the value of the uniform in
    //out shader
    View = glm::translate(View, glm::vec3(0, 0 , -0.2));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "view_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &View[0][0]);
}

void key_press_s(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the s key is pressed on the keyboard, we should move the camera away from the object
    //this is done by translating the View matrix in the x direction and then resetting the value of the uniform in
    //our shader
    View = glm::translate(View, glm::vec3(0, 0 , 0.2));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "view_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &View[0][0]);
}

void key_press_a(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the a key is pressed on the keyboard, we should move the camera to the left the object
    //this is done by translating the View matrix in the x direction and then resetting the value of the uniform in
    //our shader
    View = glm::translate(View, glm::vec3(-0.2, 0 , 0));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "view_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &View[0][0]);
}

void key_press_d(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the d key is pressed on the keyboard, we should move the camera to the right of the object
    //this is done by translating the View matrix in the x direction and then resetting the value of the uniform in
    //our shader
    View = glm::translate(View, glm::vec3(0.2, 0 , 0));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "view_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &View[0][0]);
}

void key_press_o(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the o key is pressed on the keyboard, we should scale the object up by 10%.
    //this is done by scaling the model matrix in all directions and then resetting the value of the uniform in
    //our shader
    Model = glm::scale(Model, glm::vec3(1.01f, 1.01f, 1.01f));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "model_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &Model[0][0]);
}

void key_press_p(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the p key is pressed on the keyboard, we should scale the object down by 10%.
    //this is done by scaling the model matrix in all directions and then resetting the value of the uniform in
    //our shader
    Model = glm::scale(Model, glm::vec3(0.99f, 0.99f, 0.99f));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "model_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &Model[0][0]);
}

void key_press_left_arrow(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the left arrow is pressed, we need to rotate the camera (i.e the view matrix about the up vector in
    //counterclockwise fashion).
    View = glm::rotate(View, glm::radians(0.2f), glm::vec3(0,1,0));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "view_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &View[0][0]);
}

void key_press_right_arrow(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the right arrow is pressed, we need to rotate the camera (i.e the view matrix about the up vector in
    //clockwise fashion).
    View = glm::rotate(View, glm::radians(-0.2f), glm::vec3(0,1,0));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "view_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &View[0][0]);
}

void key_press_up_arrow(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the right arrow is pressed, we need to rotate the camera (i.e the view matrix about the up vector in
    //clockwise fashion).
    View = glm::rotate(View, glm::radians(-0.2f), glm::vec3(1,0,0));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "view_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &View[0][0]);
}

void key_press_down_arrow(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the right arrow is pressed, we need to rotate the camera (i.e the view matrix about the up vector in
    //clockwise fashion).
    View = glm::rotate(View, glm::radians(0.2f), glm::vec3(1,0,0));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "view_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &View[0][0]);
}

void key_press_b(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the b key is pressed, the OBJECT itself (not the camera) should be rotated about the x-axis.
    //in order to do this, we want to modify the Model matrix
    Model = glm::rotate(Model, glm::radians(-0.2f), glm::vec3(1,0,0));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "model_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &Model[0][0]);
}

void key_press_n(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the n key is pressed, the OBJECT itself (not the camera) should be rotated about the y-axis.
    //in order to do this, we want to modify the Model matrix
    Model = glm::rotate(Model, glm::radians(0.2f), glm::vec3(0,1,0));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "model_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &Model[0][0]);
}

void key_press_e(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the n key is pressed, the OBJECT itself (not the camera) should be rotated about the z-axis.
    //in order to do this, we want to modify the Model matrix
    Model = glm::rotate(Model, glm::radians(0.2f), glm::vec3(0,0,1));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "model_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &Model[0][0]);
}

void key_press_j(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the j key is pressed, the OBJECT itself (not the camera) should be translated along the x axis
    //in the positive direction
    //in order to do this, we want to modify the Model matrix
    Model = glm::translate(Model, glm::vec3(0.2f, 0 , 0));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "model_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &Model[0][0]);
}

void key_press_l(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the l key is pressed, the OBJECT itself (not the camera) should be translated along the x axis
    //in the positive direction
    //in order to do this, we want to modify the Model matrix
    Model = glm::translate(Model, glm::vec3(-0.2f, 0 , 0));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "model_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &Model[0][0]);
}

void key_press_i(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the i key is pressed, the OBJECT itself (not the camera) should be translated along the y axis
    //in the positive direction
    //in order to do this, we want to modify the Model matrix
    Model = glm::translate(Model, glm::vec3(0, 0.2f , 0));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "model_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &Model[0][0]);
}

void key_press_k(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the k key is pressed, the OBJECT itself (not the camera) should be translated along the y axis
    //in the negative direction
    //in order to do this, we want to modify the Model matrix
    Model = glm::translate(Model, glm::vec3(0, -0.2f , 0));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "model_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &Model[0][0]);
}

void key_press_pg_up(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the page up key is pressed, the OBJECT itself (not the camera) should be translated along the z axis
    //in the positive direction
    //in order to do this, we want to modify the Model matrix
    Model = glm::translate(Model, glm::vec3(0, 0 , 0.2f));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "model_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &Model[0][0]);
}

void key_press_pg_down(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the page down key is pressed, the OBJECT itself (not the camera) should be translated along the z axis
    //in the negative direction
    //in order to do this, we want to modify the Model matrix
    Model = glm::translate(Model, glm::vec3(0, 0 , -0.2f));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "model_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &Model[0][0]);
}

void key_press_lm_button_up(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    View = glm::translate(View, glm::vec3(0,0,0.1));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "view_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &View[0][0]);
}

void key_press_lm_button_down(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    View = glm::translate(View, glm::vec3(0,0,-0.1));
    GLuint MatrixID = glGetUniformLocation(ShaderID, "view_matrix");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &View[0][0]);
}

void key_press_1(GLuint program_ID)
{
    //when this key is pressed, we first need to find the id of the red channel uniform in the shader program
    GLuint red_channel_id = glGetUniformLocation(program_ID, "red_channel");
    GLfloat red_val; //this will hold the current value of the red channel uniform in the shader program
    glGetUniformfv(program_ID, red_channel_id, &red_val); //this will change the value of red_val so we have the
                                                          //the current one
    if(red_val == 1.0f)
        glUniform1f(red_channel_id, 0.0f);
    else
        glUniform1f(red_channel_id, 1.0f);

    //this changes the value of the red_channel from 1 to 0 or zero to 1 depending on what the current value is
}

void key_press_2(GLuint program_ID)
{
    //this method works exactly in the same way as the one for the red channel, the only difference is that here
    //we are modifying the green channel's value

    GLuint green_channel_id = glGetUniformLocation(program_ID, "green_channel");
    GLfloat green_val;
    glGetUniformfv(program_ID, green_channel_id, &green_val);

    if(green_val == 1.0f)
        glUniform1f(green_channel_id, 0.0f);
    else
        glUniform1f(green_channel_id, 1.0f);
}

void key_press_3(GLuint program_ID)
{
    //this method works exactly in the same way as the one for the red channel, the only difference is that here
    //we are modifying the blue channel's value

    GLuint blue_channel_id = glGetUniformLocation(program_ID, "blue_channel");
    GLfloat blue_val;
    glGetUniformfv(program_ID, blue_channel_id, &blue_val);

    if(blue_val == 1.0f)
        glUniform1f(blue_channel_id, 0.0f);
    else
        glUniform1f(blue_channel_id, 1.0f);
}

void key_press_4(GLuint program_ID)
{
    //when the '4' key is pressed on the keyboard, all of the channels should be toggled on.
    //to do this, we need to first find all of our channels
    GLuint red_channel_id = glGetUniformLocation(program_ID, "red_channel");
    GLuint green_channel_id = glGetUniformLocation(program_ID, "green_channel");
    GLuint blue_channel_id = glGetUniformLocation(program_ID, "blue_channel");

    //now that we have the color id's we need to change their values
    glUniform1f(red_channel_id, 1.0f);
    glUniform1f(green_channel_id, 1.0f);
    glUniform1f(blue_channel_id, 1.0f);
}

void key_press_6(GLuint program_ID)
{
    //if the light is on, then we should turn it off and vice versa
    GLuint light_on_id = glGetUniformLocation(program_ID, "light_on");
    GLint light_on_value;
    glGetUniformiv(program_ID, light_on_id, &light_on_value);

    if(light_on_value == 1)
        glUniform1i(light_on_id, 0);
    else
        glUniform1i(light_on_id, 1);
}

void key_press_5(GLuint& program_ID, GLboolean& gouraud)
{
    //there are two cases, either gouraud is true, in which case, we should load the phong shaders and flip it, or
    //it is false, and we should load the gouraud shaders and flip it.
    if(gouraud)
    {
        std::cout << "Switching to Phong Illumination Model..." << std::endl;
        program_ID = LoadShaders("../Shaders/PhongVertexShader.glsl", "../Shaders/PhongFragmentShader.glsl");
        glUseProgram(program_ID);
        gouraud = GL_FALSE;
    }

    else
    {
        std::cout << "Switching to Gouraud Illumination Model..." << std::endl;
        program_ID = LoadShaders("../Shaders/GouraudVertexShader.glsl", "../Shaders/GouraudFragmentShader.glsl");
        glUseProgram(program_ID);
        gouraud = GL_TRUE;
    }
}

void key_press_m(GLuint program_ID)
{
    //first we must check the value of the uniform
    GLint flag_value;
    glGetUniformiv(program_ID, glGetUniformLocation(program_ID, "normal_as_color"), &flag_value);

    //now that we have the current value, we should flip it
    if(flag_value == 1)
    {
        GLuint flag_location = glGetUniformLocation(program_ID, "normal_as_color");
        glUniform1i(flag_location, 0);
    }

    else
    {
        GLuint flag_location = glGetUniformLocation(program_ID, "normal_as_color");
        glUniform1i(flag_location, 1);
    }
}

void key_press_g(GLuint program_ID)
{
    //first we must check the value of the uniform
    GLint flag_value;
    glGetUniformiv(program_ID, glGetUniformLocation(program_ID, "gray_scale"), &flag_value);

    //now that we have the current value, we should flip it
    if(flag_value == 1)
    {
        GLuint flag_location = glGetUniformLocation(program_ID, "gray_scale");
        glUniform1i(flag_location, 0);
    }

    else
    {
        GLuint flag_location = glGetUniformLocation(program_ID, "gray_scale");
        glUniform1i(flag_location, 1);
    }
}