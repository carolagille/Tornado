#version 400 core
//Fragement shaders can work on the position that come from the vertecies shader
//and you can assign it colour in here


out vec4 fragColour;

uniform sampler2D tex;

void main()
{

    fragColour = texture(tex,gl_PointCoord);
    if (fragColour.r>=0.7 && fragColour.g>=0.7 && fragColour.b>=0.7)
       {
        discard;
    }
}
