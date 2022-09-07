#include "OpenGLWindow.h"

OpenGLWindow::OpenGLWindow()
{

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);




    currentWindow = glfwCreateWindow(800, 800, "Bamtan Exam", NULL, NULL);
}

void OpenGLWindow::InitWindow()
{
    glfwMakeContextCurrent(currentWindow);

    gladLoadGL();

    glViewport(0, 0, 800, 800);



    GLfloat vertices[] = {
        -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, ///Esquina inferior izq.
        0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, //Esquina inferior der.
        0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, //Esquina superior
        -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, //Interior derecho
        0.0f, -0.5f * float(sqrt(3)) /3, 0.0f //Interior abajo
    };


    GLuint indices[] = {
        0,3,5, //Lower left triangle
        3,2,4, //Lower Right Triangle
        5,4,1 //Upper triangle
    };

    //STORE VERTEX SHADER

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);


    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteProgram(vertexShader);
    glDeleteShader(fragmentShader);

    /// <summary>
    /// El VAO debe de ser generado previo al VBO
    /// </summary>
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);


    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);


    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
 

    glfwSwapBuffers(currentWindow);
}

void OpenGLWindow::TickWindow()
{
    while (!glfwWindowShouldClose(currentWindow)) {

        /// <summary>
        /// Especifica el color del fondo
        /// </summary>
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        /// <summary>
        /// Limpia el buffer trasero y asigna uno nuevo
        /// </summary>
        glClear(GL_COLOR_BUFFER_BIT);
        /// <summary>
        /// Le dice a OpenGL que Shader vamos a usar
        /// </summary>
        glUseProgram(shaderProgram);
        /// <summary>
        /// Vincula el Vertex Array a OpenGL
        /// </summary>
        glBindVertexArray(VAO);
        /// <summary>
        /// Dibuja el triángulo, usando finalmente el GLTriangles primitivo
        /// </summary>
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
        /// <summary>
        /// Intercambia el buffer trasero con el delantero
        /// </summary>
        glfwSwapBuffers(currentWindow);

        /// <summary>
        /// Se encarga de los eventos que se tienen que ejecutar de GLFW
        /// </summary>
        glfwPollEvents();
    }
}

void OpenGLWindow::DestroyWindow()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
    glfwDestroyWindow(currentWindow);
    glfwTerminate();

}

void OpenGLWindow::DisplayWindow()
{
    
}

bool OpenGLWindow::windowIsOpen()
{

    return false;
}

bool OpenGLWindow::windowIsNull()
{
    if (currentWindow == NULL) 
    {
        std::cout << "FAILED TO CREATE GLFW WINDOW " << std::endl;

        glfwTerminate();

        return true;
    }

    return false;
}
