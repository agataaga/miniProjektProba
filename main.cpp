//	ten plik robi piekne drewniane okno


#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "include/stb/stb_image.h"
#include "include/glm/gtc/matrix_transform.hpp"
#include "include/glm/gtc/type_ptr.hpp"

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include "camera.h"
#include "Texture.h"


const unsigned int width = 800;
const unsigned int height = 800;


GLfloat boxVertices[] = {
	//     COORDINATES        //    COLORS (light brown RGB)   //      TEXTURE COORDS      //      NORMALS    
	-0.1f, -0.1f,  0.1f,  0.8f, 0.52f, 0.25f,  0.0f, 0.0f,   0.0f, 0.0f, 1.0f,  // Front face
	-0.1f, -0.1f, -0.1f,  0.8f, 0.52f, 0.25f,  0.0f, 0.0f,  0.0f, 1.0f, -1.0f,  // Back face
	 0.1f, -0.1f, -0.1f,  0.8f, 0.52f, 0.25f,  1.0f, 0.0f,  0.0f, 1.0f, -1.0f,  // Back face
	 0.1f, -0.1f,  0.1f,  0.8f, 0.52f, 0.25f,  1.0f, 1.0f,  0.0f, 0.0f, 1.0f,  // Front face
	-0.1f,  0.1f,  0.1f,  0.8f, 0.52f, 0.25f,  0.0f, 1.0f,  0.0f, 0.0f, 1.0f,  // Top face
	-0.1f,  0.1f, -0.1f,  0.8f, 0.52f, 0.25f,  0.0f, 1.0f,   0.0f, 0.0f, -1.0f,  // Bottom face
	 0.1f,  0.1f, -0.1f,  0.8f, 0.52f, 0.25f,  1.0f, 1.0f,   0.0f, 0.0f, -1.0f,  // Bottom face
	 0.1f,  0.1f,  0.1f,  0.8f, 0.52f, 0.25f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f   // Top face
};


//verices for light cube
GLfloat lightVertices[] = {
	//     COORDINATES    
	-0.1f, -0.1f,  0.1f,
	-0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f,  0.1f,
	-0.1f,  0.1f,  0.1f,
	-0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f,  0.1f,
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

float leftShutterRotation = 0.0f;
float rightShutterRotation = 0.0f;

float windowRotation = 0.0f;

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		if (leftShutterRotation < 100.0f) {
			leftShutterRotation += 1.0f; // Open left shutter
		}
		if (rightShutterRotation > -100.0f) {
			rightShutterRotation -= 1.0f; // Open right shutter
		}
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		if (leftShutterRotation > 0.0f) {
			leftShutterRotation -= 1.0f; // Close left shutter
		}
		if (rightShutterRotation < 0.0f) {
			rightShutterRotation += 1.0f; // Close right shutter
		}
	}
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
		windowRotation += 1.0f;  // Rotate clockwise
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		windowRotation -= 1.0f;
}

int main()
{
	// Initialize GLFW
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(width, height, "mywindow", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, width, height);

	//////////////////////////gen cubes for window frame////////////////////////////////////
	Shader shaderProgram("default.vert", "default.frag");

	VAO boxVAO;
	boxVAO.Bind();
	VBO boxVBO(boxVertices, sizeof(boxVertices));
	EBO boxEBO(lightIndices, sizeof(lightIndices));
	// position
	boxVAO.LinkAttrib(boxVBO, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	// color
	boxVAO.LinkAttrib(boxVBO, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	// textures
	boxVAO.LinkAttrib(boxVBO, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	//normals - for light
	boxVAO.LinkAttrib(boxVBO, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

	boxVAO.Unbind();
	boxVBO.Unbind();
	boxEBO.Unbind();

	///////////////////////////////generating the lightsource/////////////////////////////////////
	Shader lightShader("light.vert", "light.frag");

	VAO lightVAO;
	lightVAO.Bind();
	VBO lightVBO(lightVertices, sizeof(lightVertices));
	EBO lightEBO(lightIndices, sizeof(lightIndices));
	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	lightVAO.Unbind();
	lightVBO.Unbind();
	lightEBO.Unbind();


	/////////////////////// light stuff using shaders//////////////////////////////
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 2.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	// light cube shader defined outside the main loop - doesnt change
	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

	shaderProgram.Activate();
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// textrue!!
	Texture woodTex("wood.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	woodTex.texUnit(shaderProgram, "tex0", 0);
	
	glEnable(GL_DEPTH_TEST);
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 5.0f));


	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//allows keyboard inputs
		processInput(window);
		camera.Inputs(window);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		//cam activate
		shaderProgram.Activate();
		camera.Matrix(shaderProgram, "camMatrix");

		woodTex.Bind();

		glm::mat4 cubeModel = glm::mat4(1.0f);
		glm::mat4 identityMatrix = glm::mat4(1.0f);
		glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

		glm::mat4 windowRotationMatrix = glm::rotate(identityMatrix, glm::radians(windowRotation), glm::vec3(0.0f, 1.0f, 0.0f));

		//// dolna pozioma
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0f, 1.0f, 1.0f));
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));

		model = windowRotationMatrix * translateMatrix * scaleMatrix;
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
		boxVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		
		//// gorna pozioma
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0f, 1.0f, 1.0f));
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 1.0f, 0.0f));

		model = windowRotationMatrix * translateMatrix * scaleMatrix;
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
		boxVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		/// prawa pionowa
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 6.0f, 1.0f));
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.8f, 0.5f, 0.0f));

		model = windowRotationMatrix * translateMatrix * scaleMatrix;
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
		boxVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		/// lewa pionowa
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 6.0f, 1.0f));
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.8f, 0.5f, 0.0f));

		model = windowRotationMatrix * translateMatrix * scaleMatrix;
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
		boxVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		/// srodkowa pionowa
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 6.0f, 1.0f));
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.5f, 0.0f));

		model = windowRotationMatrix * translateMatrix * scaleMatrix;
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
		boxVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		
		/// LEFT WINDOW PANEL
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.5f, 6.0f, 1.0f));
		glm::mat4 translateMatrix1 = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.2f));
		glm::mat4 rotateMatrix = glm::rotate(identityMatrix, glm::radians(rightShutterRotation), glm::vec3(0.0f, 1.0f, 0.0f)); // Use z-axis to rotate outward toward the viewer
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.65f, 0.5f, 0.2f));
		model = windowRotationMatrix * translateMatrix * rotateMatrix* translateMatrix1 * scaleMatrix;
		if (rightShutterRotation > -45) {
			model = windowRotationMatrix * translateMatrix * rotateMatrix * scaleMatrix;
		}
		else {
			model = windowRotationMatrix * translateMatrix * rotateMatrix * translateMatrix1 * scaleMatrix;
		}
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
		boxVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		///	 RIGHT FRONT PANEL
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.5f, 6.0f, 1.0f));
		translateMatrix1 = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.2f));
		rotateMatrix = glm::rotate(identityMatrix, glm::radians(leftShutterRotation), glm::vec3(0.0f, 1.0f, 0.0f)); 
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.65f, 0.5f, 0.2f));
		if (leftShutterRotation > 45) {
			
			model = windowRotationMatrix * translateMatrix * rotateMatrix * translateMatrix1 * scaleMatrix;
		}
		else {
			model = windowRotationMatrix * translateMatrix * rotateMatrix * scaleMatrix;
		}
		

		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
		boxVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		
		lightShader.Activate();
		camera.Matrix(lightShader, "camMatrix");

		lightVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	shaderProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;


}