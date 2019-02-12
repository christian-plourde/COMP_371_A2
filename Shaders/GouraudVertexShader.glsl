#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 normals;

//the three color channels
uniform float red_channel;
uniform float green_channel;
uniform float blue_channel;

//information required for lighting
uniform vec3 light_color;
uniform vec3 light_position;
uniform vec3 view_position;

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 projection_matrix;
uniform int normal_as_color;

out vec3 fragment_position;
out vec3 normal;
out vec3 vertex_color;

void main()
{
    normal = mat3(model_matrix)*normals;
    fragment_position = mat3(model_matrix)*vertexPosition_modelspace;
    gl_Position = projection_matrix*view_matrix*model_matrix*vec4(vertexPosition_modelspace, 1);

    //Ambient light
    float ambient_strength = 0.25f;
    vec3 ambient = ambient_strength * light_color;

    //diffuse light
    float diffuse_coeff = 0.75f;
    vec3 light_direction = normalize(light_position - vertexPosition_modelspace);
    float diffuse_strength = max(dot(normalize(normal), light_direction), 0.0f);
    vec3 diffuse = diffuse_strength*diffuse_coeff*light_color;

    //specular light
    float spec_coeff = 1.0f;
    vec3 view_direction = normalize(view_position - vertexPosition_modelspace);
    vec3 reflect_light_direction = reflect(-light_direction, normalize(normal));
    float specular_strength = pow(max(dot(reflect_light_direction, view_direction), 0.0f), 32);
    vec3 specular = specular_strength*spec_coeff*light_color;

    if(normal_as_color == 1)
    {
        vertex_color = (specular + ambient + diffuse)*normal;
    }

    else
    {
        vertex_color = (specular + ambient + diffuse)*vec3(red_channel, green_channel, blue_channel);
    }

}