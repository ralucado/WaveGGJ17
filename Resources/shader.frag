uniform vec2 resolution;
uniform float time;

float rand(vec2 n) { 
    return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}

float line(float p, float x, float glow, float thick) {
    if (abs(p - x) < thick) return 1.; 
    return 1. - pow(abs(p - x), glow);
}

float line2(float p, float x, float glow) {
    return 1. - pow(abs(p - x), glow);
}

float grid(vec2 uv) {
    float glow = 0.05;
    float c = line(uv.x, 0.25, glow, 0.025) + line(uv.x, 0.75, glow, 0.025)
            + line(uv.x, 0.5, glow, 0.025)
        	+ line(uv.x, 0.0,  glow, 0.025) + line(uv.x, 1.0, glow, 0.025)
        	+ line(uv.y, 0.25, glow, 0.025) + line(uv.y, 0.75, glow, 0.025)
        	+ line(uv.y, 0.5,  glow, 0.025)
        	+ line(uv.y, 0.0,  glow, 0.025) + line(uv.y, 1.0, glow, 0.025);   
    
    return c;
}

void main(void) {
    vec2 umuv = (gl_FragCoord.xy / resolution.xy - .5) * 2.;
    vec2 uv = umuv;
    float z = (abs(uv.y ) * .8 + .2);
    
    uv.y *= 3.;
    uv /= z;
    
    if (uv.y < umuv.y) uv.y += abs(time * 0.1);
    else uv.y -= abs(time * 0.1);
    
    vec4 color = vec4(255, 120, 153, 255) / 255.;
    vec4 colorB = vec4(255,255,255,255)/ 255.;
    gl_FragColor = (grid(fract(uv))) * color;
}