#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{

	if (glfwInit() == false)
		return -1;

	// Code here

	GLFWwindow* window = glfwCreateWindow(1280, 720, "OpenGL Game Engine", nullptr, nullptr);

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -2;
	}

	// Rest of code goes here.

	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();

	std::cout << "GL Version is " << major << "." << minor << '\n';

	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		// Game logic and update code goes here.
		// So does render code.
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;

}