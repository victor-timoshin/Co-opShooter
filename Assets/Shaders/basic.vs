#version 400

in vec3 position;

void main(void) {
	gl_Position = vec4(position, 1.0);
	gl_FrontColor = gl_Color;
}