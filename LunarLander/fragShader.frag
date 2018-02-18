#version 330 core
out vec4 FragColor;

in vec3 theColor;
in vec2 TexCoord;

uniform sampler2D theTexture;

void main() {
    //FragColor = texture(theTexture, TexCoord) * vec4(1.0, 1.0, 1.0, 1.0);
	FragColor = vec4(1.0, 0.5, 1.0, 1.0);
}
