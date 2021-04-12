#version 330 core
//This code was refferenced from learnOpenGl's tutorial showcasing how to make a frag shader for HDR
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D hdrBuffer;
uniform bool hdr;
uniform float u_Exposure;

void main()
{             
    const float gamma = 2.2;
   
   vec3 hdrColor = texture(hdrBuffer, TexCoords).rgb;
    
    if(hdr)
    {

        // exposure
        vec3 result = vec3(1.0) - exp(-hdrColor * u_Exposure);
        //Gamma correct    
        result = pow(result, vec3(1.0 / gamma));
        FragColor = vec4(result, 1.0);

    }
}