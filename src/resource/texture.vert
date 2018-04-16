#version 330

uniform mat4 u_ModelViewProjectionMatrix;

layout (location = 0) in vec4 a_position;

out float height;

void main(void) {
	height = a_position.y;
    gl_Position =  u_ModelViewProjectionMatrix * a_position;
}