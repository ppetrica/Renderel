#include "test/TestMenu.hpp"

namespace renderel::test {

TestMenu::TestMenu(const Window &m_Window) : Test(m_Window) {}

void TestMenu::OnGUIRender() {
	for (auto test : m_Tests) {
		if (m_Window.GetGUI()->Button(test.name.c_str())) {
			m_CurrentTest = test.function();
			isActive = false;
		}
	}
}

void TestMenu::Run(float deltaTime) {
	m_Window.GetGUI()->Init();
	m_Window.GetGUI()->Begin("Test");
	m_Window.GetGUI()->Text("FPS: %.2f", static_cast<double>(1.0f / deltaTime));

	if (isActive) {

		OnGUIRender();
		if (m_Window.GetGUI()->Button("Exit")) {
			m_Window.Close();
		}
		m_Window.GetGUI()->End();

	} else {
		m_CurrentTest->OnUpdate(deltaTime);
		m_CurrentTest->OnRender();

		m_CurrentTest->OnGUIRender();
		if (m_Window.GetGUI()->Button("| <-- |")) {
			isActive = true;
		}

		m_Window.GetGUI()->End();
	}
}

} // namespace renderel::test
