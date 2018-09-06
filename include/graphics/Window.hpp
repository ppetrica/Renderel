#ifndef GRAPHICS_WINDOW_HPP
#define GRAPHICS_WINDOW_HPP

#include <string>
#include <GL/glew.h>
#include "GLFW/glfw3.h"

namespace renderel::graphics {

class Window {
  private:
    int m_Width;
    int m_Height;
    GLFWwindow *m_GLFWwindow;
public:
    Window(int width, int height, std::string title);
    ~Window();

    bool ShouldClose() const;
    void Clear() const;
    void PollEvents() const;
    void setClearColor(float r, float g, float b);

    int getWidth() const { return m_Width; }
    int getHeight() const { return m_Width; }
};

} // namespace renderel::graphics

#endif // GRAPHICS_WINDOW_HPP