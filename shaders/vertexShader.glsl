#version 410 core

//Vertex shaders gets position of a vertex (and other intformation like normals,uv)
//and in the shader you can manipulate thoose positions with math. This is neccessary when
//using a camera so the vertecies are displayed in replation to the camera




in vec3 inPosition;
uniform mat4 MVP;
//uniform mat4 P;
//tells the programm which slot on the graphics card to use
//inputs a position that is stored in inPosition


void main()
{ //we can change the position in here but i don't want to change it
    gl_Position = MVP*vec4(inPosition,1.0);
}
