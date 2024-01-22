//#include <iostream>
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <fstream>
//#include <string>
//
//#include "shaderClass.h"
//#include "VAO.h"
//#include "VBO.h"
//#include "EBO.h"
//#include "Camera.h"
//
//const unsigned int width = 1024;
//const unsigned int height = 768;
//
//static unsigned int ss_id = 0;
//void dump_framebuffer_to_ppm(std::string prefix, unsigned int width, unsigned int height) {
//	int pixelChannel = 3;
//	int totalPixelSize = pixelChannel * width * height * sizeof(GLubyte);
//	GLubyte* pixels = new GLubyte[totalPixelSize];
//	glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
//	std::string file_name = prefix + std::to_string(ss_id) + ".ppm";
//	std::ofstream fout(file_name);
//	fout << "P3\n" << width << " " << height << "\n" << 255 << std::endl;
//	for (size_t i = 0; i < height; i++)
//	{
//		for (size_t j = 0; j < width; j++)
//		{
//			size_t cur = pixelChannel * ((height - i - 1) * width + j);
//			fout << (int)pixels[cur] << " " << (int)pixels[cur + 1] << " " << (int)pixels[cur + 2] << " ";
//		}
//		fout << std::endl;
//	}
//	ss_id++;
//	delete[] pixels;
//	fout.flush();
//	fout.close();
//}
//
////key board control
//void processInput(GLFWwindow* window)
//{
//	//press escape to exit
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//	//press p to capture screen
//	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
//	{
//		std::cout << "Capture Window " << ss_id << std::endl;
//		int buffer_width, buffer_height;
//		glfwGetFramebufferSize(window, &buffer_width, &buffer_height);
//		dump_framebuffer_to_ppm("cubepic", buffer_width, buffer_height);
//	}
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//// Vertices coordinates
//GLfloat vertices[] =
//{ //    COORDINATES       /      COLORS
//  //    Front             /      Fuchsia
//	 1.0f,  1.0f,  1.0f,     1.0f, 0.0f, 1.0f,
//	-1.0f, -1.0f,  1.0f,     1.0f, 0.0f, 1.0f,
//	-1.0f,  1.0f,  1.0f,     1.0f, 0.0f, 1.0f,
//	 1.0f, -1.0f,  1.0f,     1.0f, 0.0f, 1.0f,
//  //    Back              /      Yellow
//	-1.0f,  1.0f, -1.0f,     1.0f, 1.0f, 0.0f,
//	 1.0f, -1.0f, -1.0f,     1.0f, 1.0f, 0.0f,
//	 1.0f,  1.0f, -1.0f,     1.0f, 1.0f, 0.0f,
//	-1.0f, -1.0f, -1.0f,     1.0f, 1.0f, 0.0f,
//  //    Left              /      Red
//	-1.0f,  1.0f,  1.0f,     1.0f, 0.0f, 0.0f,
//	-1.0f, -1.0f, -1.0f,     1.0f, 0.0f, 0.0f,
//	-1.0f,  1.0f, -1.0f,     1.0f, 0.0f, 0.0f,
//	-1.0f, -1.0f,  1.0f,     1.0f, 0.0f, 0.0f,
//  //    Right             /      Green
//	 1.0f,  1.0f, -1.0f,     0.0f, 1.0f, 0.0f,
//	 1.0f, -1.0f,  1.0f,     0.0f, 1.0f, 0.0f,
//	 1.0f,  1.0f,  1.0f,     0.0f, 1.0f, 0.0f,
//	 1.0f, -1.0f, -1.0f,     0.0f, 1.0f, 0.0f,
//  //    Top               /      Blue
//	 1.0f,  1.0f, -1.0f,     0.0f, 0.0f, 1.0f,
//	-1.0f,  1.0f,  1.0f,     0.0f, 0.0f, 1.0f,
//	-1.0f,  1.0f, -1.0f,     0.0f, 0.0f, 1.0f,
//	 1.0f,  1.0f,  1.0f,     0.0f, 0.0f, 1.0f,
//  //    Bottom            /      Aqua
//	 1.0f, -1.0f,  1.0f,     0.0f, 1.0f, 1.0f,
//	-1.0f, -1.0f, -1.0f,     0.0f, 1.0f, 1.0f,
//	-1.0f, -1.0f,  1.0f,     0.0f, 1.0f, 1.0f,
//	 1.0f, -1.0f, -1.0f,     0.0f, 1.0f, 1.0f
//};
//
//// Indices for vertices order
//GLuint indices[] =
//{
//	0, 1, 2,
//	0, 1, 3,
//	4, 5, 6,
//	4, 5, 7,
//	8, 9, 10,
//	8, 9, 11,
//	12, 13, 14,
//	12, 13, 15,
//	16, 17, 18,
//	16, 17, 19,
//	20, 21, 22,
//	20, 21, 23
//};
//
//
//
//int main()
//{
//	// Initialize GLFW
//	glfwInit();
//
//	// Tell GLFW what version of OpenGL we are using 
//	// In this case we are using OpenGL 3.3
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	// Tell GLFW we are using the CORE profile
//	// So that means we only have the modern functions
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	// Create a GLFWwindow object of width by height pixels, naming it "3GC3 A1"
//	GLFWwindow* window = glfwCreateWindow(width, height, "3GC3 A1", NULL, NULL);
//	// Error check if the window fails to create
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	// Introduce the window into the current context
//	glfwMakeContextCurrent(window);
//
//	//Load GLAD so it configures OpenGL
//	gladLoadGL();
//	// Specify the viewport of OpenGL in the Window
//	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
//	glViewport(0, 0, width, height);
//
//
//
//	// Generates Shader object using shaders defualt.vert and default.frag
//	Shader shaderProgram("default.vert", "default.frag");
//
//
//
//	// Generates Vertex Array Object and binds it
//	VAO VAO1;
//	VAO1.Bind();
//
//	// Generates Vertex Buffer Object and links it to vertices
//	VBO VBO1(vertices, sizeof(vertices));
//	// Generates Element Buffer Object and links it to indices
//	EBO EBO1(indices, sizeof(indices));
//
//	// Links VBO attributes such as coordinates and colors to VAO
//	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
//	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	// Unbind all to prevent accidentally modifying them
//	VAO1.Unbind();
//	VBO1.Unbind();
//	EBO1.Unbind();
//
//	glEnable(GL_DEPTH_TEST);
//
//	Camera camera(width, height, glm::vec3(7.0f, -8.0f, -9.0f), glm::vec3(0.0f, 0.0f, 0.0f));
//
//	// Main while loop
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//
//		// Specify the color of the background
//		glClearColor(0.3f, 0.4f, 0.5f, 1.0f);
//		// Clean the back buffer and assign the new color to it
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		// Tell OpenGL which Shader Program we want to use
//		shaderProgram.Activate();
//		
//		camera.Matrix(45.0f, 0.1f, 1000.0f, shaderProgram, "camMatrix");
//
//		// Bind the VAO so OpenGL knows to use it
//		VAO1.Bind();
//		// Draw primitives, number of indices, datatype of indices, index of indices
//		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
//		// Swap the back buffer with the front buffer
//		glfwSwapBuffers(window);
//		// Take care of all GLFW events
//		glfwPollEvents();
//	}
//
//
//
//	// Delete all the objects we've created
//	VAO1.Delete();
//	VBO1.Delete();
//	EBO1.Delete();
//	shaderProgram.Delete();
//	// Delete window before ending the program
//	glfwDestroyWindow(window);
//	// Terminate GLFW before ending the program
//	glfwTerminate();
//	return 0;
//}