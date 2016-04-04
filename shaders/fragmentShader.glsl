#version 400 core
//Fragement shaders can work on the position that come from the vertecies shader
//and you can assign it colour in here


out vec4 fragColour;

uniform sampler2D tex;

void main()
{

    fragColour = texture(tex,gl_PointCoord);
    if (fragColour.r>=0.9 && fragColour.g>=0.9 && fragColour.b>=0.9)
    //if (fragColour.r<=0.1 && fragColour.g<=0.1 && fragColour.b<=0.1)
       {
        discard;
    }
}
