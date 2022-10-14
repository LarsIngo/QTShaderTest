#version 440
layout(location = 0) in vec2 coord;
layout(location = 0) out vec4 fragColor;
layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
	
	float time;
};

layout(binding = 1) uniform sampler2D noiseTex;
layout(binding = 2) uniform sampler2D videoTex;

// [0, 1] -> [0.5, 1]

void main() {

	// coord [0, 1]
	
	vec2 otherCoord = coord * 0.5; // [0, 1] -> [0, 0.5]
	otherCoord = otherCoord + 0.5; // [0, 0.5] -> [0.5, 1.0]

	//float noise = texture(noiseTex, coord).x;
	vec4 srcVal = texture(videoTex, otherCoord);
	fragColor = srcVal;
}
