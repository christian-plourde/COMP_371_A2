Author: Christian Plourde
Student ID: 26572499

This program loads in a cat object file and allows the user to view it as a point cloud and interact with the model
by using the mouse and keyboard inputs listed below.

This program consists of a main function, found within the main.cpp file, as well as a fragment and vertex shader (found
in the BasicFragmentShader.shader and BasicVertexShader.shader files respectively). The keyboard control functions
are defined in the KeyboardControls.h file and implemented in the KeyboardControls.cpp file. The file used
to generate the model of the cat is found in the cat.obj file and the loader function to load it from the file is found
in the ObjectLoader.cpp file (the implementation of the function defined in the ObjectLoader.h file). Finally the
shader compiler is found in the ShaderLoader.h file (and implemented in the ShaderLoader.cpp file).

The keyboard controls are as follows:
Left-Mouse-Button + Mouse Up = Move into the scene
Left-Mouse-Button + Mouse Down = Move out of the scene
W = Move camera in negative Z direction
S = Move camera in positive Z direction
A = Move camera in negative X direction
D = Move camera in positive X direction
O = Scale the object up by a factor of 10%
P = Scale the object down by a factor of 10%
Left-Arrow = Rotate the camera counterclockwise around the up vector
Right-Arrow = Rotate the camera clockwise around the up vector
Up-Arrow = Rotate the camera counterclockwise around the right vector
Down-Arrow = Rotate the camera clockwise around the right vector
B = Rotate the object (cat) around the x-axis in counterclockwise fashion
N = Rotate the object (cat) around the y-axis in counterclockwise fashion
E = Rotate the object (cat) around the z-axis in counterclockwise fashion
J = Translate the object (cat) along the negative x-axis
L = Translate the object (cat) along the positive x-axis
I = Translate the object (cat) along the positive y-axis
K = Translate the object (cat) along the negative y-axis
Page Up = Translate the object (cat) along the positive z-axis
Page Down = Translate the object (cat) along the negative z-axis






