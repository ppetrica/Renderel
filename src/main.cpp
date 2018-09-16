#include "Camera.hpp"
#include "GameEventHandler.hpp"
#include "ImGUI.hpp"
#include "InputControl.hpp"
#include "Transform.hpp"
#include "WindowGLFW.hpp"
#include "graphics/BasicRenderer.hpp"
#include "graphics/IndexBuffer.hpp"
#include "graphics/OBJLoader.hpp"
#include "graphics/Shader.hpp"
#include "graphics/Texture.hpp"
#include "graphics/VertexArray.hpp"
#include "graphics/VertexBuffer.hpp"
#include "math/EulerAngle.hpp"
#include "math/Mat4.hpp"
#include "math/Quaternion.hpp"
#include "math/Vec2.hpp"
#include "math/Vec3.hpp"
#include "test/Test.hpp"
#include "test/TestClearColor.hpp"
#include "test/TestOBJLoader.hpp"
#include "test/TestTexturedCube.hpp"

using namespace renderel;

#define WIDTH 1080
#define HEIGHT 720

int main() {
	GameEventHandler gameEventHandler;

	Window *window =
		new WindowGLFW(WIDTH, HEIGHT, "Renderel", &gameEventHandler);

	graphics::Renderer<unsigned int>::InitGraphics();
	graphics::Renderer<unsigned int>::SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	test::Test *currentTest = nullptr;
	test::TestMenu *testMenu = new test::TestMenu(currentTest);
	currentTest = testMenu;

	testMenu->RegisterTest<test::TestClearColor>("Clear color test");
	testMenu->RegisterTest<test::TestTexturedCube>("Textured cube test");
	testMenu->RegisterTest<test::TestOBJLoader>("Test obj loader");

	GUI *gui = new ImGUI(window->GetAPIHandle(), "#version 130");

	float prevTime = 0;
	float newTime = static_cast<float>(glfwGetTime());
	float deltaTime;

	while (!window->ShouldClose()) {
		deltaTime = newTime - prevTime;
		prevTime = newTime;

		window->PollEvents();
		graphics::Renderer<>::Clear();

		gui->Init();

		if (currentTest) {
			currentTest->OnUpdate(deltaTime);
			currentTest->OnRender();
			gui->Begin("Test");
			currentTest->OnGUIRender();

			if (currentTest != testMenu && gui->Button("| <-- |")) {
				delete currentTest;
				currentTest = testMenu;
			}

			gui->End();
		}

		gui->Render();

		window->SwapBuffers();

		newTime = static_cast<float>(glfwGetTime());
	}

	// TODO: use unique pointers
	delete testMenu;
	delete gui;
	delete window;
}
