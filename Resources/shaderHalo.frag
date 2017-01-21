// uniform float time2;
uniform bool blue;

void main(void) {
//     float transpa = sin(time2)*255.;
    vec4 color = (246,111,231, 255);
    if (blue) color = (0,153,253, 255);
    gl_FragColor = color;
}