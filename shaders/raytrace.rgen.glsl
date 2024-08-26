// This shader is responsible for generating rays in a ray tracing pipeline.

#version 460
#extension GL_EXT_ray_tracing : require

layout(set = 0, binding = 0) uniform accelerationStructureEXT topLevelAS;
layout(location = 0) rayPayloadEXT vec3 hitColor;

void main() {
    vec3 origin = vec3(0.0, 0.0, 0.0);
    vec3 direction = normalize(vec3(gl_LaunchIDEXT.xy, 1.0));

    traceRayEXT(topLevelAS, 
                gl_RayFlagsOpaqueEXT, 
                0xFF, 
                0, 
                0, 
                0, 
                origin, 
                0.0, 
                direction, 
                10000.0, 
                0);
}
