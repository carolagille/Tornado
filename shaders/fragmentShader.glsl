#version 400 core
//Fragement shaders can work on the position that come from the vertex shader
//and you can assign it colour in here


out vec4 fragColour;

uniform sampler2D tex;

void main()
{
    //fragment shader that assigns the texure tho the point
    fragColour = texture(tex, gl_PointCoord);


}
