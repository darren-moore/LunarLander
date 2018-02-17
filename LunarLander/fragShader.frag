#version 330 core
out vec4 FragColor;
uniform float gv;

void main() {
    FragColor = vec4(1.0, gv, 1.0, 1.0);
}
