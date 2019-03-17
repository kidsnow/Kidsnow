#version 330

layout (location = 0) in vec4 a_position;
layout (location = 1) in vec2 a_texcoord;

uniform mat4 MVP;

out vec2 UV;

void main(void) {
    gl_Position = MVP * a_position;
	UV = a_texcoord;
}
