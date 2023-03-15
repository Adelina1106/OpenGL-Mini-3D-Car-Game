#version 330

// Input
layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_texture_coord;
layout(location = 3) in vec3 v_positionCar;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

// Uniforms for light properties
uniform vec3 light_position;
uniform vec3 eye_position;
uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;

uniform vec3 object_color;
uniform vec3 car_position;
uniform vec3 obs_position;

// Output value to fragment shader
out vec3 color;


void main()
{
    
    vec3 v_pos = v_position;
    float scaleFactor = 0.012f;
    vec3 pos = v_pos;
    vec3 aux = car_position - obs_position;
    float norma = sqrt(aux.x * aux.x + aux.y * aux.y +aux.z * aux.z);
    float pos_y = v_position.y - norma * norma * scaleFactor;
    gl_Position = Projection * View * Model * vec4(v_position.x ,pos_y , v_position.z  , 1.0);
    color = object_color;
}
