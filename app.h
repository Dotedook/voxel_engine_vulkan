#pragma once

#include "window.h"
#include "pipeline.h"
#include "device.h"
#include "swap_chain.h"
#include "model.h"

#include <memory>
#include<vector>

namespace voxel {
	class App
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		App();
		~App();

		App(const App&) = delete;
		App& operator=(const App&) = delete;

		void run();
	
	private:
		void sierpinski(
			std::vector<Model::Vertex>& vertices,
			int depth,
			glm::vec2 left,
			glm::vec2 right,
			glm::vec2 top);
		void loadModels();
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();

		Window window{WIDTH, HEIGHT, "Tela do Voxel!"};
		Device device{ window };
		SwapChain swapChain{ device, window.getExtent() };
		std::unique_ptr<Pipeline> pipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
		std::unique_ptr<Model> model;
	};
}	
