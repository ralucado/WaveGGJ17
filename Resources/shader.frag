uniform vec2 resolution;
uniform float time;

float rand(vec2 n) { 
    return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}

float line(float p, float x, float glow) {
    return 1. - pow(abs(p - x), glow);
}

float grid(vec2 uv) {
    float glow = 0.05;
    float c = line(uv.x, 0.25, glow) + line(uv.x, 0.75, glow)
            + line(uv.x, 0.5, glow)
        	+ line(uv.x, 0.25, glow) + line(uv.x, 1.0, glow)
        	+ line(uv.y, 0.25, glow) + line(uv.y, 0.75, glow)
        	+ line(uv.y, 0.5, glow)
        	+ line(uv.y, 0.25, glow) + line(uv.y, 1.0, glow);   
    
    return c;
}

void main(void) {
    vec2 umuv = (gl_FragCoord.xy / resolution.xy - .5) * 2.;
    vec2 uv = umuv;
    float z = (abs(uv.y ) * .8 + 3.);
    
    uv.y *= 3.;
    uv /= z*0.25;
   
    float clampfinite = abs(clamp(umuv.y, -1., 0.)) * pow(z, 1. / 10.);
    
    uv.y += abs(time * 0.1);
    
    float grain = (0.8 + 0.2 * rand(umuv + time));
    vec4 color = vec4(255, 120, 153, 255) / 255.;
    gl_FragColor = (grid(fract(uv))) * grain * color * clampfinite;
}