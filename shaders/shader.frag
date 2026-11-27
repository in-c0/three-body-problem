#version 450

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragPos;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform GlowSettings {
    float radius;
    float glowIntensity;
};

void main() {
    // Calculate the distance from the fragment to the center of the circle
    float distance = length(fragPos);

    // Calculate glow factor: the farther from the center, the lower the glow
    float glowFactor = max(0.0, 1.0 - (distance / radius));

    // Apply an exponential falloff to the glow factor
    glowFactor = pow(glowFactor, glowIntensity);

    // Final color is the base color multiplied by the glow factor
    vec3 glowColor = fragColor * glowFactor;

    // Output the final color with the calculated glow effect
    outColor = vec4(glowColor, glowFactor);
}