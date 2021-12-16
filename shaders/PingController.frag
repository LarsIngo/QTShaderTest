#version 440
layout(location = 0) in vec2 coord;
layout(location = 0) out vec4 fragColor;
layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
};

layout(binding = 1) uniform sampler2D colorTex;
layout(binding = 2) uniform sampler2D maskTex;

void main() {
    vec4 color = texture(colorTex, coord);
	float mask = 1 - texture(maskTex, coord).r;
	
	vec3 finalColor = color.rbg * (1 + mask);

	fragColor = vec4(finalColor.rbg, color.a);
}
