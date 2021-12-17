#version 440
layout(location = 0) in vec2 coord;
layout(location = 0) out vec4 fragColor;
layout(std140, binding = 0) uniform buf
{
    mat4 qt_Matrix;
    float qt_Opacity;

	int pingType;
};

layout(binding = 1) uniform sampler2D colorTex;
layout(binding = 2) uniform sampler2D maskTex;

void main()
{
	float PI = radians(180);
	float cutValue = sin(PI * 0.25f);

    vec4 colorSamp = texture(colorTex, coord);
	float maskSamp = 1 - texture(maskTex, coord).r;
	
	vec2 xy = coord * 2 - 1;
	vec2 xyDir = normalize(xy);
	float xyCenter = float(length(xy) < 0.2);
	float xyUp = float(dot(xyDir, vec2(0,-1)) > cutValue);
	float xyDown = float(dot(xyDir, vec2(0,1)) > cutValue);
	float xyLeft = float(dot(xyDir, vec2(-1,0)) > cutValue);
	float xyRight = float(dot(xyDir, vec2(1,0)) > cutValue);
		
	float targetCenter = float(pingType == 0);
	float targetUp = float(pingType == 1);
	float targetDown = float(pingType == 2);
	float targetLeft = float(pingType == 3);
	float targetRight = float(pingType == 4);

	float clip = mix((xyUp * targetUp + xyDown * targetDown + xyLeft * targetLeft + xyRight * targetRight) * (1 - xyCenter), xyCenter, xyCenter * targetCenter);
	vec3 finalColor = mix(colorSamp.xyz, colorSamp.xyz * 1.5, clip * maskSamp);
	float finalAlpha = mix(0.5, 0.4, clip * maskSamp) * colorSamp.a;
	
	fragColor = vec4(finalColor, finalAlpha);
}
