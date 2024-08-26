// Closest-Hit shader
// This shader is executed when a ray hits an object, determining the color based on the intersection.

#version 460
#extension GL_EXT_ray_tracing : require

layout(location = 0) rayPayloadInEXT vec3 hitColor;

hitAttributeEXT vec3 attribs;

void main() {
    hitColor = vec3(1.0, 0.0, 0.0);  // Set the color to red for the hit object
}
