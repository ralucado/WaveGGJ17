uniform float time;
uniform bool blue;
uniform sampler2D texture;

void main(void) {
    float transpa = max (sin(time*5.)*100., 50.);
    vec4 color = vec4 (246.,111.,231.,transpa)/255.;
    if (blue) color = vec4(0.,153.,253.,transpa)/255.;
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    gl_FragColor = pixel * color;
}