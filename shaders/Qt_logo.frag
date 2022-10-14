#version 440
layout(location = 0) in vec2 coord;
layout(location = 0) out vec4 fragColor;
layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
};

layout(binding = 1) uniform sampler2D srcTex;

void main() {
	vec4 srcVal = texture(srcTex, coord);
	
	float red = srcVal.x;
	float green = srcVal.y;
	float blue = srcVal.z;
	float alpha = srcVal.w;
	
	float finalAlpha = 1.0;
	if (red > 0.4 && green > 0.4 && blue > 0.4)
	{
		finalAlpha = 0.0;
	}
	else 
	{
		finalAlpha = alpha;
	}
	
	
	
	fragColor = vec4(red, green, blue, 1) * finalAlpha * qt_Opacity;
}
