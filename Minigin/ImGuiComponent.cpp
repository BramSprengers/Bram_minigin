#include "ImGuiComponent.h"
#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3_loader.h>
#include <imgui_impl_opengl3.h>
#include <imgui_plot.h>
#include <iostream>
#include <string>
#include <chrono>

void dae::ImGuiComponent::Update(float)
{
}

void dae::ImGuiComponent::FixedUpdate(float)
{
}

void dae::ImGuiComponent::Render() const
{
	ImGuiWindowFlags flags = 0;
	flags |= ImGuiWindowFlags_NoResize;
	flags |= ImGuiWindowFlags_NoSavedSettings;

	bool* open = new bool(true);

	static uint32_t selection_start = 0, selection_length = 0;

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
	//ImGui::ShowDemoWindow();



	ImGui::SetNextWindowSize(ImVec2(500, 700), ImGuiCond_FirstUseEver);
	ImGui::Begin("exercise 1:", open, flags);

	static int* i = new int(10);
	ImGui::InputInt("#samples", i);

	//float testx[10];

	std::vector<float> testy;

	testy = IntTrashing(*i);

	auto res = std::max_element(testy.begin(), testy.end());

	ImGui::PlotConfig conf;
	//conf.values.xs = testx; // this line is optional
	conf.values.ys = testy.data();
	conf.values.count = (int)testy.size();
	conf.scale.min = 0;
	conf.scale.max = res[0];
	conf.tooltip.show = true;
	conf.tooltip.format = "x=%.2f, y=%.2f";
	conf.grid_x.show = true;
	conf.grid_x.size = 128;
	conf.grid_x.subticks = 4;
	conf.grid_y.show = true;
	conf.grid_y.size = 0.5f;
	conf.grid_y.subticks = 5;
	conf.selection.start = &selection_start;
	conf.selection.length = &selection_length;
	conf.frame_size = ImVec2(400, 400);
	conf.line_thickness = 2.f;

	ImGui::Plot("plot", conf);

	ImGui::End();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

std::vector<float> dae::ImGuiComponent::IntTrashing(int times) const
{
	std::vector<std::vector<int>> timings;
	timings.resize(times);
	for (int x = 0; x < times; x++)
	{
		std::vector<int> arr((const unsigned int)powf(2, 26));

		for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
		{
			const auto start = std::chrono::high_resolution_clock().now();

			for (int i = 0; i < arr.size(); i += stepsize)
			{
				arr[i] *= 2;
			}

			const auto end = std::chrono::high_resolution_clock().now();

			const int total = (int)std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

			timings[x].push_back(total);
		}
	}

	std::vector<float> rounded;


	return rounded;
}

std::vector<float> dae::ImGuiComponent::OBTrashing(int times) const
{
	for (int x = 0; x < times; x++)
	{
		for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
		{
			std::vector<GameObject3D> arr((const unsigned int)powf(2, 26));

			const auto start = std::chrono::high_resolution_clock().now();

			for (int i = 0; i < arr.size(); i += stepsize)
			{
				arr[i].ID *= 2;
			}

			const auto end = std::chrono::high_resolution_clock().now();

			const auto total = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

			std::cout << total << " " << std::endl;
		}
	}

	return std::vector<float>();
}


