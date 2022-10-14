#version 440
layout(location = 0) in vec2 coord;
layout(location = 0) out vec4 fragColor;
layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
	
	float time;
	float strength;
};

layout(binding = 1) uniform sampler2D noiseTex;

vec2 rotateUV(vec2 uv, float rotation)
{
    float mid = 0.5;
    return vec2(
        cos(rotation) * (uv.x - mid) + sin(rotation) * (uv.y - mid) + mid,
        cos(rotation) * (uv.y - mid) - sin(rotation) * (uv.x - mid) + mid
    );
}

void main() {
	float PI = radians(180);
	
	vec2 rCoord = rotateUV(coord, time * 2 * PI);

	vec2 xy = rCoord * 2 - 1;
	float radius = length(xy);
	float angle = atan(xy.y, xy.x); // [-PI,PI]
	angle = (angle + PI) / (2 * PI); // [0,1]
	
	float radiusAlpha = pow(clamp(1 - radius, 0, 1), 0.5);
	float angularAlpha = pow(angle, 10);
	float alpha = radiusAlpha * angularAlpha;

    float radarNoise = texture(noiseTex, coord).x;
	radarNoise = pow(radarNoise, strength) * strength * strength;

	fragColor = mix(vec4(0), vec4(0.2, 0.72, 0.2, 0.0), alpha + radarNoise * alpha) * qt_Opacity;
}
