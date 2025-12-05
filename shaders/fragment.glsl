#version 460 core

in vec3 frag_position;
in vec3 frag_normal;

out vec4 frag_color;

uniform vec3 light_direction;  // Directional light (towards object)
uniform vec3 light_color;      // Color of the light
uniform vec3 object_color;     // Base color of the object

void main()
{
    vec3 normal = normalize(frag_normal);
    vec3 light_dir = normalize(-light_direction); // Make it point from light to fragment

    float diffuse_factor = max(dot(normal, light_dir), 0.0);
    vec3 diffuse = diffuse_factor * light_color;

    vec3 result = diffuse * object_color;
    frag_color = vec4(result, 1.0);
}

