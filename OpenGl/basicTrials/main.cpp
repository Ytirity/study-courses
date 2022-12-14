#include <iostream>

#include "glad/src/glad.c" // TODO: сделать правильно
#include <glad/glad.h>

#include <GLFW/glfw3.h>

using namespace std;

void framebuffer_size_callback( GLFWwindow * window, int width, int height )
{
    glViewport( 0, 0, width, height );
}

void processInput( GLFWwindow * window )
{
    if ( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS ) glfwSetWindowShouldClose( window, true );
}

const char * vertexShaderSource = "#version 330 core\n"
                                  "layout (location = 0) in vec3 aPos;\n"
                                  "void main()\n"
                                  "{\n"
                                  "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                  "}\0";

int main()
{
    glfwInit();
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    GLFWwindow * window = glfwCreateWindow( 800, 600, "LearnOpenGL", NULL, NULL );
    if ( window == NULL ) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent( window );

    glfwSetFramebufferSizeCallback( window, framebuffer_size_callback );

    if ( !gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ) ) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport( 0, 0, 800, 600 );

    // --------------

    float vertices[] = { -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f };

    unsigned int VBO;
    glGenBuffers( 1, &VBO );

    glBindBuffer( GL_ARRAY_BUFFER, VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof( vertices ), vertices, GL_STATIC_DRAW );

    // --------------

    unsigned int vertexShader;
    vertexShader = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource( vertexShader, 1, &vertexShaderSource, NULL );
    glCompileShader( vertexShader );

    int success; // Проверка корректности
    char infoLog[512];
    glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &success );
    if ( !success ) {
        glGetShaderInfoLog( vertexShader, 512, NULL, infoLog );
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // --------------

    while ( !glfwWindowShouldClose( window ) ) {

        // input
        processInput( window );

        // rendering commands here
        glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        // check and call events and swap the buffers
        glfwSwapBuffers( window );
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
