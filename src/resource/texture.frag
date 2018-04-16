#version 330

uniform float u_scale;

layout (location = 0) out vec4 final_color;

in float height;

void main(void) {

	//float temp = height / 20.0;
	////float temp = height / 2.0;

	//if (height > 0)
	//	final_color = vec4(0.0, temp, temp, 1.0);
	//else if (height < 0)
	//	final_color = vec4(-temp, 0.0, -temp, 1.0);
	//else
	//	final_color = vec4(0.0, 0.0, 0.0, 1.0);

	float temp = height / u_scale;
	final_color = vec4(0.5 + temp, 0.5 + temp, 0.5 + temp, 1.0);
}