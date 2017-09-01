#pragma once

#ifndef __LEARNOPENGL_H__
#define __LEARNOPENGL_H__

#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "Shader.h"
#include "stb_image.h"

#include "DrawTriangle.h"

using namespace std;


class BaseDraw {
public:
	virtual void BeforeLoop() {}
	virtual void Update() {}
	virtual void AfterLoop() {}
};



class DrawTriangle : public BaseDraw {
public:
	void BeforeLoop();
	void Update();
	void AfterLoop();
};

class GLSLTest : public BaseDraw {
public:
	void BeforeLoop();
	void Update();
	void AfterLoop();
};

#endif