#version 330 core

uniform float currentSecondPointer;
uniform float currentMinutePointer;
uniform float currentHourPointer;

layout (location = 0) out vec4 color;
varying vec2 pos;

void main(){
	
	color = vec4(0.0, 0.0, 0.0, 1.0);

	float distance = length(pos);
	float dotSecond = dot(normalize(pos), vec2(cos(currentSecondPointer), sin(currentSecondPointer)));

	if (distance <= 0.9){
		color = vec4(1.0, 1.0, 1.0, 1.0);

		if (dotSecond > 0.999) color = vec4(0.0, 0.0, 1.0, 1.0);
	}

	// minute
	float dotMinute = dot(normalize(pos), vec2(cos(currentMinutePointer), sin(currentMinutePointer)));
	if (distance <= 0.6f && dotMinute > 0.995){
		color = vec4(0.0, 1.0, 0.0, 1.0);
	}

	// hour
	float dotHour = dot(normalize(pos), vec2(cos(currentHourPointer), sin(currentHourPointer)));
	if (distance <= 0.5f && dotHour > 0.99){
		color = vec4(1.0, 0.0, 0.0, 1.0);
	}

}