#version 330 core
out vec4 FragColor;

in vec3 theColor;
in vec2 TexCoord;

uniform sampler2D theTexture;
uniform vec3 shaderColor;

void main() {
    //FragColor = texture(theTexture, TexCoord) * vec4(1.0, 1.0, 1.0, 1.0);
	FragColor = vec4(shaderColor, 1.0);
}
