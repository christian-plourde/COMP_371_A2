#include <iostream>
#include <glew.h>
#include <GLFW/glfw3.h>
#include "GLM/glm/matrix.hpp"
#include "GLM/glm/gtc/matrix_transform.hpp"
#include "GLM/glm/gtc/type_ptr.hpp"
#include "Loaders/ShaderLoader.h"
#include "Loaders/ObjectLoader.h"
#include "Controls/KeyboardControls.h"

//definition of all the uniforms
GLuint view_mat_ID;
GLuint model_mat_ID;
GLuint projection_mat_ID;
glm::mat4 Model;
glm::mat4 Projection;
glm::mat4 View;
GLuint red_channel_id;
GLuint blue_channel_id;
GLuint green_channel_id;
GLuint light_position;
GLuint light_color;
GLuint view_position;

GLuint lightOn; //a flag to determine whether or not the light should be on (1 is on, 0 is off)
GLboolean gouraud_flag; //this determines if we use gouraud or not (alternative is phong) for lighting
GLuint programID; //this variable will be assigned the program ID of the shader program
                  //since we need it to modify the color channels, we will make it global
                  //so we can use it in the keyboard callback method

/*
 * Method to reset the values of all the uniforms for the new program id when we switch shaders.
 */
void setUniforms()
{
    //first we get handles for all of the matrix uniforms to use in our MVP matrix and we set their values
    //according to the matrices defined in the main method
    view_mat_ID = glGetUniformLocation(programID, "view_matrix");
    model_mat_ID = glGetUniformLocation(programID, "model_matrix");
    projection_mat_ID = glGetUniformLocation(programID, "projection_matrix");
    glUniformMatrix4fv(view_mat_ID, 1, GL_FALSE, &View[0][0]);
    glUniformMatrix4fv(model_mat_ID, 1, GL_FALSE, &Model[0][0]);
    glUniformMatrix4fv(projection_mat_ID, 1, GL_FALSE, &Projection[0][0]);

    //next we need to set up three uniforms, one for each color channel since we will be implementing controls
    //to toggle each one on and off.
    red_channel_id = glGetUniformLocation(programID, "red_channel");
    glUniform1f(red_channel_id, 1.0f);
    green_channel_id = glGetUniformLocation(programID, "green_channel");
    glUniform1f(green_channel_id, 1.0f);
    blue_channel_id = glGetUniformLocation(programID, "blue_channel");
    glUniform1f(blue_channel_id, 1.0f);

    //next is a uniform to turn on and off the light as a whole. (No light means no lighting model is used)
    lightOn = glGetUniformLocation(programID, "light_on");
    glUniform1i(lightOn, 1);

    //this is the uniform that defines the position of the light
    light_position = glGetUniformLocation(programID, "light_position");
    glUniform3fv(light_position, 1, glm::value_ptr(glm::vec3(0, 20, 5)));

    //this is uniform that defines the color of the light
    light_color = glGetUniformLocation(programID, "light_color");
    glUniform3fv(light_color, 1, glm::value_ptr(glm::vec3(0.8,0.8,0.8)));

    //this is the view position of the camera. This is important for calculating the impact of the specular light
    //component.
    view_position = glGetUniformLocation(programID, "view_position");
    glUniform3fv(view_position, 1, glm::value_ptr(glm::vec3(100,100,100)));
}

/*
 * This is the method that will execute when there is input from the keyboard.
 * For this method to be a valid callback method for the keyboard, it must match the proper signature,
 * which is the one used for this method.
 */
void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    /*
     * This defines what happens when the escape key is pressed. In our case, we would like the escape key to close
     * the currently used window
     */
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

    //controls what occurs when the '1' key is pressed
    if(glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        key_press_1(programID);

    //controls what happens when the '2' key is pressed
    if(glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        key_press_2(programID);

    //controls what happens when the '3' key is pressed
    if(glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
        key_press_3(programID);

    if(glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
        key_press_4(programID);

    if(glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
        key_press_6(programID);

    if(glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
    {
        key_press_5(programID, gouraud_flag);
        setUniforms();
    }
}

/*
 * Method to handle the initialization process of the window
 */
static GLFWwindow* initialize()
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
        return nullptr;

    // Create a windowed mode window and its OpenGL context
    int width =  800;
    int height = 800;
    window = glfwCreateWindow(width, height, "COMP 371 A2", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return nullptr;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    //we should also set the keyboard input callback method
    glfwSetKeyCallback(window, keyboard_callback);
    glfwWindowHint(GLFW_DOUBLEBUFFER, 1);

    glewExperimental = GL_TRUE;

    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return nullptr;
    }

    return window;
}

int main()
{
    std::cout << glfwGetVersionString() << std::endl;
    GLFWwindow* window = initialize();

    if(window == nullptr)
    {
        std::cout << "ERROR -- Initialization failed." << std::endl;
        return -1;
    }

    //we need to load the data for the object that we would like to draw from an object file
    //we can do this using the method that we have defined
    std::vector<glm::vec3> vertices, normals;
    std::vector<glm::vec2> uvs;
    //we try to load the object file and if we fail, then we simply exit the program since we won't be able to draw anything
    if(!LoadOBJ("../ObjectFiles/cat.obj", vertices, normals, uvs))
        return -1;

    //We will try to create a cube by using a vertex array object
    GLuint VertexArrayID; //this is our reference to our vao
    glGenVertexArrays(1, &VertexArrayID); //this will generate the actual array for us and we want only one
    glBindVertexArray(VertexArrayID); //then we make it the current one (pass to GPU)

    //Now in order for openGL to be able to draw this triangle we need to pass it then data by creating a vertex buffer
    //object
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*vertices.size(), &vertices.front(), GL_STATIC_DRAW);

    //for the lighting, we also need the normals, therefore we should create another vbo
    GLuint normalBuffer;
    glGenBuffers(1, &normalBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*normals.size(), &normals.front(), GL_STATIC_DRAW);

    //now we load the shader program and assign it tour our program id
    //initially, we use the Phong illumination model
    gouraud_flag = GL_FALSE;
    programID = LoadShaders("../Shaders/PhongVertexShader.glsl", "../Shaders/PhongFragmentShader.glsl");
    glUseProgram(programID);

    //in order for this object to be viewed from a perspective view, we need a Model View Projection matrix
    //we wish to draw the triangle from a perspective view
    //this is the projection matrix for a perspective view
    int width; //the width of the window
    int height; //the height of the window
    glfwGetWindowSize(window, &width, &height);

    //this creates an perspective projection matrix which we will use to render our object
    Projection = glm::perspective(glm::radians(45.0f), (float)width/height, 0.1f, 200.0f);
    //we then need a camera matrix, we will make it look at the origin
    View = glm::lookAt(glm::vec3(0,0,-40),glm::vec3(0,0,0), glm::vec3(0, 1, 0));

    //this is the model matrix (the identity matrix since we are placing the mode (our triangle) at the origin.
    //also changing this will modify what the final triangle looks like. This is where we apply transformations
    //such as scaling, translation, etc.
    Model = glm::mat4(1.0f);

    //now that we have our matrices, we should set all of our uniforms
    setUniforms();

    //we need to define two doubles to hold the old and new positions of the mouse cursor so we can check
    //which direction the user is moving the mouse in.

    double oldMouseY = 0;
    double newMouseY = 0;

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        //each time we draw we should clear both the color and the depth buffer bit so that the sorting process can
        //begin again from scratch
        //if we don't clear the depth buffer, then on the next frame everything we want to draw will be further than the
        //last closest item (obviously) and we won't have anything drawn
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //now we can draw our triangle
        //to do this we need to tell open GL about our vertex array (id 0)
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        //we also need to enable the normals array
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        //this will allow us to access that buffer in GLSL

        //this configures the z-buffer so that only elements that are closer will be drawn
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        //here we need to specify the number of vertices we wish to draw
        //for this assignment, they should be drawn using triangles
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        //check if there was input
        //this includes clicking the close button on the window
        glfwPollEvents();

        //here we define what occurs if specific keys are pressed
        //the functions are defined in the keyboard controls file, we are simply calling them based on
        //which key is pressed
        if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            key_press_w(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            key_press_s(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            key_press_a(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            key_press_d(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
            key_press_o(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
            key_press_p(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
            key_press_left_arrow(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
            key_press_right_arrow(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
            key_press_up_arrow(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
            key_press_down_arrow(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
            key_press_b(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
            key_press_n(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
            key_press_e(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
            key_press_j(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
            key_press_l(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
            key_press_i(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
            key_press_k(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS)
            key_press_pg_up(window, View, Projection, Model, programID);

        if(glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
            key_press_pg_down(window, View, Projection, Model, programID);

        //before dealing with the mouse input, we need to get the current position of the mouse and compare it to
        //the old. Since we don't care about x, we can just pass 0.

        glfwGetCursorPos(window, &newMouseY, 0);

        if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && newMouseY > oldMouseY)
            key_press_lm_button_up(window, View, Projection, Model, programID);

        if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && newMouseY < oldMouseY)
            key_press_lm_button_down(window, View, Projection, Model, programID);

        //update the last position of the mouse
        oldMouseY = newMouseY;
    }

    glfwTerminate();

    return 0;
}