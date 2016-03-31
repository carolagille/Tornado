#version 400 core
//Fragement shaders can work on the position that come from the vertecies shader
//and you can assign it colour in here


out vec4 fragColour;

uniform sampler2D tex;

void main()
{

    fragColour = texure(tex,gl_PointCoord);
}
