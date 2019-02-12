#version 330 core

out vec3 color;

//the three color channels
uniform float red_channel;
uniform float green_channel;
uniform float blue_channel;

//the components for Phong Lighting
uniform vec3 light_color;
uniform vec3 light_position;
uniform vec3 view_position;

//the flag to turn the light on and off
uniform int light_on;

//the flag to determine if the normal should be used as the color.
uniform int normal_as_color;

//the flag to use grayscale or not
uniform int gray_scale;

in vec3 fragment_position;
in vec3 normal;

void main()
{
    if(normal_as_color == 1)
    {
        color = normal;
    }

    else
    {
        color = vec3(red_channel, green_channel, blue_channel);
    }


    if(light_on == 1)
    {
        //Ambient light
        float ambient_strength = 0.25f;
        vec3 ambient = ambient_strength * light_color;

        //diffuse light
        float diffuse_coeff = 0.75f;
        vec3 light_direction = normalize(light_position - fragment_position);
        float diffuse_strength = max(dot(normalize(normal), light_direction), 0.0f);
        vec3 diffuse = diffuse_strength*diffuse_coeff*light_color;

        //specular light
        float spec_coeff = 1.0f;
        vec3 view_direction = normalize(view_position - fragment_position);
        vec3 reflect_light_direction = reflect(-light_direction, normalize(normal));
        float specular_strength = pow(max(dot(reflect_light_direction, view_direction), 0.0f), 32);
        vec3 specular = specular_strength*spec_coeff*light_color;

        color = (specular + ambient + diffuse)*color;

        if(gray_scale == 1)
            color = vec3(0.2989*color.x+0.5870*color.y+0.1140*color.z);
    }

    else
    {
        color = vec3(1.0f, 1.0f, 1.0f);
    }
}