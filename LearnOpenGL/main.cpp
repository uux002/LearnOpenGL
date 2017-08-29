#include "LearnOpenGL.h"

void framebuffer_size_callback(GLFWwindow * window, int width, int height);
void processInput(GLFWwindow * window);


int main() {
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow * window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Faidl to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Faild to initialize GLAD" << std::endl;
		return -1;
	}


	BaseDraw *draw = new DrawTriangle();

	draw->BeforeLoop();


	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		// render process
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);			// this is a state setted function
		glClear(GL_COLOR_BUFFER_BIT);					// this is a state useed function


		draw->Update();
		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	draw->AfterLoop();

	glfwTerminate();

	return 0;
}


void framebuffer_size_callback(GLFWwindow * window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow * window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window,true);
	}
}

