uniform float time;
uniform float type;
uniform sampler2D texture;

void main(void) {
    //transparencia entre 100 y 50
    float transpa = max (sin(time*5.)*200., 75.)*gl_TexCoord[0].y; 
//     vec4 color = vec4 (246.,111.,231.,transpa)/255.;
//     if (blue) color = vec4(0.,153.,253.,transpa)/255.;

    vec4 color = vec4 (255.,255.,0.,transpa)/255.; //amarillo = 0
    if (type == 1) color = vec4(122.,202.,255.,transpa)/255.; //azul = 1
    else if (type == 2) color = vec4(255.,167.,245.,transpa)/255.; //rosa = 2
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    gl_FragColor = pixel * color;
}