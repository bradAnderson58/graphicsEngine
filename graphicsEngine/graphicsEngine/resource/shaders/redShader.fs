# version 330 core

in vec4 vertexColor;    // the input variable from the vertex shader (same name and type)

out vec4 fragColor;

void main() {
    fragColor = vertexColor;
}
