#ifndef COMP_371_A1_KEYBOARDCONTROLS_H
#define COMP_371_A1_KEYBOARDCONTROLS_H
#endif

#include <glew.h>
#include <GLFW/glfw3.h>
#include "../GLM/glm/matrix.hpp"
#include "../GLM/glm/gtc/matrix_transform.hpp"

/*
 * This method defines what occurs when the w key is pressed on the keyboard. For this assignment, it modifies
 * the viewing angle of the camera and so to change this, we need to pass in the View, Projection, and Model
 * matrices, as well as the shader ID since we will need to update the value in the uniform in the shader program
 * once we have recalculated the location of the camera.
 */
void key_press_w(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the s key is pressed on the keyboard. For this assignment, it modifies
 * the viewing angle of the camera and so to change this, we need to pass in the View, Projection, and Model
 * matrices, as well as the shader ID since we will need to update the value in the uniform in the shader program
 * once we have recalculated the location of the camera.
 */
void key_press_s(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the a key is pressed on the keyboard. For this assignment, it modifies
 * the viewing angle of the camera and so to change this, we need to pass in the View, Projection, and Model
 * matrices, as well as the shader ID since we will need to update the value in the uniform in the shader program
 * once we have recalculated the location of the camera.
 */
void key_press_a(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the d key is pressed on the keyboard. For this assignment, it modifies
 * the viewing angle of the camera and so to change this, we need to pass in the View, Projection, and Model
 * matrices, as well as the shader ID since we will need to update the value in the uniform in the shader program
 * once we have recalculated the location of the camera.
 */
void key_press_d(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the o key is pressed on the keyboard. For this assignment, it modifies
 * the size uniformly of the object and so to change this, we need to pass in the View, Projection, and Model
 * matrices, as well as the shader ID since we will need to update the value in the uniform in the shader program
 * once we have recalculated the size of the model.
 */
void key_press_o(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the p key is pressed on the keyboard. For this assignment, it modifies
 * the size uniformly of the object and so to change this, we need to pass in the View, Projection, and Model
 * matrices, as well as the shader ID since we will need to update the value in the uniform in the shader program
 * once we have recalculated the size of the model.
 */
void key_press_p(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the left arrow key is pressed on the keyboard. When this occurs, the camera
 * should rotate counterclockwise about the up vector.
 */
void key_press_left_arrow(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the right arrow key is pressed on the keyboard. When this occurs, the camera
 * should rotate clockwise about the up vector.
 */
void key_press_right_arrow(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the up arrow key is pressed on the keyboard. When this occurs, the camera
 * should rotate counterclockwise about the right vector.
 */
void key_press_up_arrow(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the down arrow key is pressed on the keyboard. When this occurs, the camera
 * should rotate clockwise about the right vector.
 */
void key_press_down_arrow(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defined what happens when b is pressed on the keyboard. When this occurs, the OBJECT (i.e. the model)
 * will be rotated about the x axis in counterclockwise fashion
 */
void key_press_b(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defined what happens when n is pressed on the keyboard. When this occurs, the OBJECT (i.e. the model)
 * will be rotated about the y axis in counterclockwise fashion
 */
void key_press_n(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defined what happens when e is pressed on the keyboard. When this occurs, the OBJECT (i.e. the model)
 * will be rotated about the z axis in counterclockwise fashion
 */
void key_press_e(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defined what happens when j is pressed on the keyboard. When this occurs, the OBJECT (i.e. the model)
 * will be translated along the x axis in the positive direction
 */
void key_press_j(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defined what happens when l is pressed on the keyboard. When this occurs, the OBJECT (i.e. the model)
 * will be translated along the x axis in the negative direction
 */
void key_press_l(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defined what happens when i is pressed on the keyboard. When this occurs, the OBJECT (i.e. the model)
 * will be translated along the y axis in the positive direction
 */
void key_press_i(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defined what happens when k is pressed on the keyboard. When this occurs, the OBJECT (i.e. the model)
 * will be translated along the y axis in the negative direction
 */
void key_press_k(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defined what happens when page up is pressed on the keyboard. When this occurs, the OBJECT (i.e. the model)
 * will be translated along the z axis in the positive direction
 */
void key_press_pg_up(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what happens when page down is pressed on the keyboard. When this occurs, the OBJECT (i.e. the model)
 * will be translated along the z axis in the negative direction
 */
void key_press_pg_down(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what happens when the left mouse button is pressed. This should move the camera in and out of
 * the scene. If the mouse is moved up while the left button is clicked, then the camera should move in. Down should
 * make the camera move out of the scene.
 */
void key_press_lm_button_up(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what happens when the left mouse button is pressed. This should move the camera in and out of
 * the scene. If the mouse is moved up while the left button is clicked, then the camera should move in. Down should
 * make the camera move out of the scene.
 */
void key_press_lm_button_down(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the '1' key is pressed. When this occurs, if the 'red' channel in the fragment
 * has a value of 1.0, then the value should be changed to 0.0 (off) and vice-versa.
 */
void key_press_1(GLuint program_ID);

/*
 * This method defines what occurs when the '2' key is pressed. When this occurs, if the 'green' channel in the fragment
 * has a value of 1.0, then the value should be changed to 0.0 (off) and vice-versa.
 */
void key_press_2(GLuint program_ID);

/*
 * This method defines what occurs when the '3' key is pressed. When this occurs, if the 'blue' channel in the fragment
 * has a value of 1.0, then the value should be changed to 0.0 (off) and vice-versa.
 */
void key_press_3(GLuint program_ID);

/*
 * This method defines what occurs when the '4' key is pressed. When this occurs, all the color channels are turned
 * on.
 */
void key_press_4(GLuint program_ID);

/*
 * This method defines what happens when the '6' key is pressed. When this occurs, the lights should be toggled on
 * and off.
 */
void key_press_6(GLuint program_ID);

/*
 * This method defines what happens when the '5' key is pressed. When this occurs, the lighting model should toggle
 * between Gouraud and Phong. This will be done by loading the appropriate shaders, one done for each lighting model.
 * We pass the program_id by reference since it will eventually point to the new shader program, and also a flag
 * indicating if we are currently using gouraud lighting or not. This flag will get flipped by the method.
 */
void key_press_5(GLuint& program_ID, GLboolean& gouraud);

/*
 * This method defines what happens when the 'm' key is pressed. When this occurs, the normal_as_color uniform should
 * be toggled between 0 and 1, to determine if the normal should be used as the fragment color or not.
 */
void key_press_m(GLuint program_ID);

/*
 * This method defines what happens when the 'g' key is pressed. When this occurs, it should toggle between grayscale
 * rendering mode by flipping the flag in the shader program.
 */
void key_press_g(GLuint program_ID);