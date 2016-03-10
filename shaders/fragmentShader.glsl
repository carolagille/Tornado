#version 400 core
//Fragement shaders can work on the position that come from the vertecies shader
//and you can assign it colour in here

out vec4 fragColour;

layout vec4 in inColour;

void main()
{
    fragColour = inColour;
}
