#ifndef SHADERS_H
#define SHADERS_H

#include <ngl/Types.h>
#include <string>

class Shader
{
public:

private:
    GLuint m_id;
    enum class DebugMode{COMPILE,LINK};
    void printInfoLog(GLuint _id, DebugMode _mode)
};




#endif // SHADERS_H
