#version 330 core

 layout(location = 0) in vec3 vertexPosition_modelspace;
 layout(location = 1) in vec3 normals;

 uniform mat4 model_matrix;
 uniform mat4 view_matrix;
 uniform mat4 projection_matrix;

 out vec3 fragment_position;
 out vec3 normal;

 void main()
 {
     normal = mat3(model_matrix)*normals;
     fragment_position = mat3(model_matrix)*vertexPosition_modelspace;

     gl_Position = projection_matrix*view_matrix*model_matrix*vec4(vertexPosition_modelspace, 1);
 }