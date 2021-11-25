#version 440
layout(location = 0) in vec2 coord;
layout(location = 0) out vec4 fragColor;
layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
	
	float time;
	float alphaOverTime;
	float threshold;
};

//layout(binding = 1) uniform sampler2D src;

void main() {
    //vec4 tex = texture(src, coord);
	vec2 xy = coord * 2 - 1;
	float r = length(xy);
	
	//vec3 color = vec3(0.7, 0.2, 0.2);
	
	float alphaMask = abs(time - r - threshold) < threshold ? 1 : 0;
	float alpha = alphaMask * (1 - alphaOverTime);

	fragColor = mix(vec4(0), vec4(0.7, 0.2, 0.2, 1.0), alpha);
	//fragColor = mix(vec4(1), vec4(0), 1);
    //fragColor = vec4(vec3(dot(tex.rgb, vec3(0.344, 0.5, 0.156))), tex.a) * qt_Opacity;
}
