uniform float time;
uniform bool blue;

void main(void) {
    float transpa = sin(time)*255.;
    vec4 color = (246,111,231, (transpa));
    if (blue) color = (0,153,253, (transpa));
    gl_FragColor = color;
}