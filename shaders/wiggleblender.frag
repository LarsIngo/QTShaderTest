#version 440
layout(location = 0) in vec2 coord;
layout(location = 0) out vec4 fragColor;
layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
	
	float time;
};

layout(binding = 1) uniform sampler2D src;

void main() {
    vec4 tex = texture(src, coord);
	vec2 xy = coord * 2 - 1;
	float r = length(xy);
	
	float alphaMask = tex.x * time;
	vec3 color = vec3(0.7, 0.2, 0.2);

	fragColor = vec4(color, alphaMask);
    //fragColor = vec4(vec3(dot(tex.rgb, vec3(0.344, 0.5, 0.156))), tex.a) * qt_Opacity;
}
