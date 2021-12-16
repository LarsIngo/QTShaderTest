#version 440
layout(location = 0) in vec2 coord;
layout(location = 0) out vec4 fragColor;
layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
	
	float time;
	float threshold;
	float r;
	float g;
	float b;
};

//layout(binding = 1) uniform sampler2D src;

void main() {
    //vec4 tex = texture(src, coord);
	vec2 xy = coord * 2 - 1;
	float rLen = length(xy);
	
	float centerMask = rLen < threshold * 2 ? 1 : 0;
	float radiusMask = abs(time - rLen - threshold) < threshold ? 1 : 0;
	float alphaMask = centerMask + radiusMask;
	float alpha = alphaMask * (1 - time);

	fragColor = mix(vec4(0), vec4(r, g, b, 1.0), alpha);
}
