#version 460 core

in vec3 vertex_position;
in vec3 vertex_normal;

out vec3 frag_position;
out vec3 frag_normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    frag_position = vec3(model * vec4(vertex_position, 1.0));
    frag_normal = mat3(transpose(inverse(model))) * vertex_normal;

    gl_Position = projection * view * vec4(frag_position, 1.0);
}

