#include "KeyboardControls.h"
#include <iostream>

void key_press_w(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the w key is pressed on the keyboard, we should move the camera toward the object
    //this is done by translating the View matrix in the x direction and then resetting the value of the uniform in
    //out shader
    View = glm::translate(View, glm::vec3(0, 0 , -0.05));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_s(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the s key is pressed on the keyboard, we should move the camera away from the object
    //this is done by translating the View matrix in the x direction and then resetting the value of the uniform in
    //our shader
    View = glm::translate(View, glm::vec3(0, 0 , 0.05));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_a(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the a key is pressed on the keyboard, we should move the camera to the left the object
    //this is done by translating the View matrix in the x direction and then resetting the value of the uniform in
    //our shader
    View = glm::translate(View, glm::vec3(-0.05, 0 , 0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_d(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the d key is pressed on the keyboard, we should move the camera to the right of the object
    //this is done by translating the View matrix in the x direction and then resetting the value of the uniform in
    //our shader
    View = glm::translate(View, glm::vec3(0.05, 0 , 0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_o(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the o key is pressed on the keyboard, we should scale the object up by 10%.
    //this is done by scaling the model matrix in all directions and then resetting the value of the uniform in
    //our shader
    Model = glm::scale(Model, glm::vec3(1.01f, 1.01f, 1.01f));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_p(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the p key is pressed on the keyboard, we should scale the object down by 10%.
    //this is done by scaling the model matrix in all directions and then resetting the value of the uniform in
    //our shader
    Model = glm::scale(Model, glm::vec3(0.99f, 0.99f, 0.99f));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_left_arrow(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the left arrow is pressed, we need to rotate the camera (i.e the view matrix about the up vector in
    //counterclockwise fashion).
    View = glm::rotate(View, glm::radians(0.05f), glm::vec3(0,1,0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_right_arrow(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the right arrow is pressed, we need to rotate the camera (i.e the view matrix about the up vector in
    //clockwise fashion).
    View = glm::rotate(View, glm::radians(-0.05f), glm::vec3(0,1,0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_up_arrow(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the right arrow is pressed, we need to rotate the camera (i.e the view matrix about the up vector in
    //clockwise fashion).
    View = glm::rotate(View, glm::radians(-0.05f), glm::vec3(1,0,0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_down_arrow(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the right arrow is pressed, we need to rotate the camera (i.e the view matrix about the up vector in
    //clockwise fashion).
    View = glm::rotate(View, glm::radians(0.05f), glm::vec3(1,0,0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_b(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the b key is pressed, the OBJECT itself (not the camera) should be rotated about the x-axis.
    //in order to do this, we want to modify the Model matrix
    Model = glm::rotate(Model, glm::radians(-0.05f), glm::vec3(1,0,0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_n(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the n key is pressed, the OBJECT itself (not the camera) should be rotated about the y-axis.
    //in order to do this, we want to modify the Model matrix
    Model = glm::rotate(Model, glm::radians(0.05f), glm::vec3(0,1,0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_e(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the n key is pressed, the OBJECT itself (not the camera) should be rotated about the z-axis.
    //in order to do this, we want to modify the Model matrix
    Model = glm::rotate(Model, glm::radians(0.05f), glm::vec3(0,0,1));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_j(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the j key is pressed, the OBJECT itself (not the camera) should be translated along the x axis
    //in the positive direction
    //in order to do this, we want to modify the Model matrix
    Model = glm::translate(Model, glm::vec3(0.05f, 0 , 0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_l(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the l key is pressed, the OBJECT itself (not the camera) should be translated along the x axis
    //in the positive direction
    //in order to do this, we want to modify the Model matrix
    Model = glm::translate(Model, glm::vec3(-0.05f, 0 , 0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_i(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the i key is pressed, the OBJECT itself (not the camera) should be translated along the y axis
    //in the positive direction
    //in order to do this, we want to modify the Model matrix
    Model = glm::translate(Model, glm::vec3(0, 0.05f , 0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_k(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the k key is pressed, the OBJECT itself (not the camera) should be translated along the y axis
    //in the negative direction
    //in order to do this, we want to modify the Model matrix
    Model = glm::translate(Model, glm::vec3(0, -0.05f , 0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_pg_up(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the page up key is pressed, the OBJECT itself (not the camera) should be translated along the z axis
    //in the positive direction
    //in order to do this, we want to modify the Model matrix
    Model = glm::translate(Model, glm::vec3(0, 0 , 0.05f));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_pg_down(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the page down key is pressed, the OBJECT itself (not the camera) should be translated along the z axis
    //in the negative direction
    //in order to do this, we want to modify the Model matrix
    Model = glm::translate(Model, glm::vec3(0, 0 , -0.05f));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_lm_button_up(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    View = glm::translate(View, glm::vec3(0,0,0.1));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_lm_button_down(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    View = glm::translate(View, glm::vec3(0,0,-0.1));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}



