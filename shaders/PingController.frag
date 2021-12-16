#version 440
layout(location = 0) in vec2 coord;
layout(location = 0) out vec4 fragColor;
layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
	
	vec2 rootPos;
	vec2 targetPos;
};

layout(binding = 1) uniform sampler2D colorTex;
layout(binding = 2) uniform sampler2D maskTex;

void main() {
	float PI = radians(180);
	float cutValue = sin(PI * 0.25f);

    vec4 colorSamp = texture(colorTex, coord);
	float maskSamp = 1 - texture(maskTex, coord).r;
	
	vec2 xy = coord * 2 - 1;
	vec2 xyDir = normalize(xy);
	float xyCenter = length(xy) < 0.1 ? 1 : 0;
	float xyUp = dot(xyDir, vec2(0,1)) > cutValue ? 1 : 0;
	float xyDown = dot(xyDir, vec2(0,-1)) > cutValue ? 1 : 0;
	float xyRight = dot(xyDir, vec2(1,0)) > cutValue ? 1 : 0;
	float xyLeft = dot(xyDir, vec2(-1,0)) > cutValue ? 1 : 0;
	
	vec2 targetVec = targetPos - rootPos;
	vec2 targetDir = normalize(targetVec);
	float targetCenter = length(targetVec) < 0.1 ? 1 : 0;
	float targetUp = dot(targetDir, vec2(0,1)) > cutValue ? 1 : 0;
	float targetDown = dot(targetDir, vec2(0,-1)) > cutValue ? 1 : 0;
	float targetRight = dot(targetDir, vec2(1,0)) > cutValue ? 1 : 0;
	float targetLeft = dot(targetDir, vec2(-1,0)) > cutValue ? 1 : 0;
	
	float clip = xyCenter * targetCenter + xyUp * targetUp + xyDown * targetDown + xyRight * targetRight + xyLeft * targetLeft;
	float mask = 1 + (maskSamp * clip);

	vec3 finalColor = colorSamp.xyz * mask;
	float finalAlpha = colorSamp.a * 0.6 * mask;
	
	fragColor = vec4(finalColor.xyz, clamp(finalAlpha, 0, 1));
}
