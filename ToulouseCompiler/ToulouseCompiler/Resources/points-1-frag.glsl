#version 400

in vec4 destinationColor;

out vec4 fColor;

void main() {
    vec2 coord = gl_PointCoord - vec2(0.5);
    float length = length(coord);
    if (length > 0.5 || length < 0.25)
        discard;
    fColor = destinationColor;
}
