# version 330 core

uniform vec4 ourColor;	// we set this variable in the OpenGL code

out vec4 fragColor;

void main() {
	fragColor = ourColor;
}