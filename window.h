#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace voxel {
	class Window
	{
	private:
		GLFWwindow* window;
		const int width;
		const int height;
		std::string name;
		void initWindow();

	public:
		Window(int width, int height, std::string name);
		~Window();

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); };
		VkExtent2D getExtent() { return { static_cast<uint32_t>(width),  static_cast<uint32_t>(height) }; }

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
	};
}

