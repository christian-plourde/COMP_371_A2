#version 330 core

out vec3 color;

//the flag to turn the light on and off
uniform int light_on;

uniform int gray_scale;

in vec3 vertex_color;

void main()
{
    if(light_on == 1)
    {
        color = vertex_color;

        if(gray_scale == 1)
            color = vec3(color.x*0.2989+color.y*0.5870+color.z*0.1140);
    }

    else
    {
        color = vec3(1.0f, 1.0f, 1.0f);
    }
}
