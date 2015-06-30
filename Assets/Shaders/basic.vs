#version 400

uniform mat4 matrixWorld;
uniform mat4 matrixView;
uniform mat4 matrixProjection;

in vec3 position;

void main(void) {
	gl_Position = vec4(position, 1.0) * ((matrixWorld * matrixView) * matrixProjection);
	gl_FrontColor = gl_Color;
}