#include "settings.hpp"
#include "inputs.hpp"

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";


const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";


int main()
{
    if (!glfwInit())
    {
        std::cout << "GLFW failed to initialise" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Voxel", NULL, NULL);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


// Shader stuff -------------------- (please move to a separate header file at some point and make the shaders actually reference a file instead of just having ts as a variable.)
    // Vertex shader:

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "Vertex shader failed to compile!!" << infoLog << std::endl;
    }


    // Fragment shader
    

    
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "Fragment shader failed to compile!!" << infoLog << std::endl;
    }

    // Creating program
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    // Linking shader attributes.

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    
    if (!success) 
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Shader Linking failed.\n" << infoLog << std::endl;
    }

    // Using the program then deleting unnecessary shaders to avoid overuse of memory

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Doing viewports

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    unsigned int VAO, VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Frame loop

    while (!glfwWindowShouldClose(window))
    {
        // Logic
        getInputs(window);

        // Rendering

        glClearColor(0.0f, 0.33f, 0.33f, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // buffer swapping and shi
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}