#version 400 core
//Fragement shaders can work on the position that come from the vertecies shader
//and you can assign it colour in here


out vec4 fragColour;

uniform sampler2D tex;

void main()
{

    fragColour = texture(tex, gl_PointCoord);

    //fragColour = vec4(1.0, 0.0, 0.0, 1.0);

    //if (fragColour.r>=0.8 && fragColour.g>=0.8 && fragColour.b>=0.8)
    //if (fragColour.r<=0.1 && fragColour.g<=0.1 && fragColour.b<=0.1)
    //   {
    //    discard;
    //}
}
