#version 400 core

//Vertex shaders gets position of a vertex (and other intformation like normals,uv)
//and in the shader you can manipulate thoose positions with math. This is neccessary when
//using a camera so the vertecies are displayed in replation to the camera

layout (location=0) in vec3 inPosition;
//tells the programm which slot on the graphics card to use
//inputs a position that is stored in inPosition

void main()
{ //we can change the position in here but i don't want to change it
    gl_Position = vec4(inPosition,1.0);
}
