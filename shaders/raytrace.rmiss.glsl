// Miss shader
// This shader defines what happens if a ray does not hit (misses) any geometry.

#version 460
#extension GL_EXT_ray_tracing : require

layout(location = 0) rayPayloadInEXT vec3 hitColor;

void main() {
    hitColor = vec3(0.0, 0.0, 0.0);  // Background color (black)
}
