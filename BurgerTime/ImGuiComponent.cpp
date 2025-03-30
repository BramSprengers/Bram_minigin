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
#include <memory>

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

	static std::unique_ptr<bool> open = std::make_unique<bool>(true);

	static uint32_t selection_start = 0, selection_length = 0;

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();



	ImGui::SetNextWindowSize(ImVec2(500, 700), ImGuiCond_FirstUseEver);
	ImGui::Begin("exercise 1:", open.get(), flags);
	{
		static std::unique_ptr<int> i = std::make_unique<int>(10);
		ImGui::InputInt("#samples", i.get());

		static std::vector<float> intTime;
		static std::unique_ptr<int> button = std::make_unique<int>(0);
		static std::vector<float>::iterator intRes;

		if (*button != 0)
		{
			ImGui::Text("wait for it");
			intTime = Trashing(*i, TrashType::intTrashing);
			intRes = std::max_element(intTime.begin(), intTime.end());
			*button = 0;
		}
		else
		{
			if (ImGui::Button("trash te sistem")) 
				*button.get() += 1;
		}

		if (intTime.size() > 0)
		{
			ImGui::PlotConfig conf;
			//conf.values.xs = testx; // this line is optional
			conf.values.ys = intTime.data();
			conf.values.count = (int)intTime.size();
			conf.scale.min = 0;
			conf.scale.max = intRes[0];
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
			conf.values.color = ImColor(0, 255, 0);
			conf.frame_size = ImVec2(400, 400);
			conf.line_thickness = 2.f;

			ImGui::Plot("plot", conf);
		}
	}
	ImGui::End();

	ImGui::SetNextWindowSize(ImVec2(500, 700), ImGuiCond_FirstUseEver);
	ImGui::Begin("exercise 2:", open.get(), flags);
	{

		static std::unique_ptr<int> i = std::make_unique<int>(10);
		ImGui::InputInt("#samples", i.get());

		static std::vector<float> obnp;
		static std::vector<float> obwp;
		static std::unique_ptr<int> pButton = std::make_unique<int>(0);
		static std::unique_ptr<int> npButton = std::make_unique<int>(0);
		static std::vector<float>::iterator obnpRes;
		static std::vector<float>::iterator obwpRes;

		if (*pButton != 0)
		{
			ImGui::Text("wait for it");
			obnp = Trashing(*i, TrashType::GOWithoutPointer);
			obnpRes = std::max_element(obnp.begin(), obnp.end());
			*pButton = 0;
		}
		else
		{
			if (ImGui::Button("trash without pointer")) 
				++*pButton;
		}

		if (*npButton != 0)
		{
			ImGui::Text("wait for it");
			obwp = Trashing(*i, TrashType::GOWithPointer);
			obwpRes = std::max_element(obwp.begin(), obwp.end());
			*npButton = 0;
		}
		else
		{
			if (ImGui::Button("trash with pointer")) 
				++*npButton;
		}

		if (obnp.size() > 0)
		{
			ImGui::PlotConfig conf;
			//conf.values.xs = testx; // this line is optional
			conf.values.ys = obnp.data();
			conf.values.count = (int)obnp.size();
			conf.scale.min = 0;
			conf.scale.max = obnpRes[0];
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
			conf.values.color = ImColor(122, 0, 255);
			conf.frame_size = ImVec2(400, 300);
			conf.line_thickness = 2.f;

			ImGui::Plot("plot1", conf);
		}

		if (obwp.size() > 0)
		{
			ImGui::PlotConfig conf;
			//conf.values.xs = testx; // this line is optional
			conf.values.ys = obwp.data();
			conf.values.count = (int)obwp.size();
			conf.scale.min = 0;
			conf.scale.max = obwpRes[0];
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
			conf.values.color = ImColor(255, 122, 0);
			conf.frame_size = ImVec2(400, 300);
			conf.line_thickness = 2.f;

			ImGui::Plot("plot2", conf);
		}

		if (obwp.size() > 0 && obnp.size() > 0)
		{
			static const float* y_data[] = { obwp.data(), obnp.data() };
			static ImU32 colors[2] = { ImColor(255, 122, 0), ImColor(122, 0, 255) };

			ImGui::PlotConfig conf;
			//conf.values.xs = testx; // this line is optional
			conf.values.ys_list = y_data;
			conf.values.count = (int)obwp.size();
			conf.values.ys_count = 2;
			conf.scale.min = 0;
			conf.scale.max = obnpRes[0];
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
			conf.values.colors = colors;
			conf.frame_size = ImVec2(400, 300);
			conf.line_thickness = 2.f;

			ImGui::Plot("plot3", conf);
		}
	}

	ImGui::End();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

std::vector<float> dae::ImGuiComponent::Trashing(unsigned int times, TrashType type) const
{
	if(times == 0)
	{
		return std::vector<float>();
	}
	std::vector<std::vector<int>> timings;
	timings.resize(11);

	

	for (unsigned int i = 0; i < timings.size(); i++)
	{
		timings[i].resize(times);
	}

	for (unsigned int x = 0; x < times; x++)
	{
		int count{};
		for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
		{
			int total{};

			switch (type)
			{
			case dae::intTrashing:
				total = IntTrashing(stepsize);
				break;
			case dae::GOWithPointer:
				total = OBWTrashing(stepsize);
				break;
			case dae::GOWithoutPointer:
				total = OBNTrashing(stepsize);
				break;
			default:
				break;
			}
			
			timings[count][x] = total;
			++count;
		}
	}

	std::vector<float> rounded(timings.size());

	for (unsigned int i = 0; i < rounded.size(); i++)
	{
		auto min = std::min_element(timings[i].begin(), timings[i].end());
		auto max = std::min_element(timings[i].begin(), timings[i].end());

		for (unsigned int j = 0; j < times; j++)
		{
			rounded[i] += timings[i][j];
		}

		rounded[i] -= min[0] + max[0];

			rounded[i] /= times;
	}


	return rounded;
}

//this can be better
int dae::ImGuiComponent::OBWTrashing(int stepsize) const
{

	std::vector<GameObject3DWithP> arr((const unsigned int)powf(2, 26));

	const auto start = std::chrono::high_resolution_clock().now();

	for (unsigned int i = 0; i < arr.size(); i += stepsize)
	{
		arr[i].ID *= 2;
	}

	const auto end = std::chrono::high_resolution_clock().now();

	std::cout << (int)(1000 * std::chrono::duration<float>(end - start).count()) << std::endl;

	return (int)(1000 * std::chrono::duration<float>(end - start).count());
}

int dae::ImGuiComponent::OBNTrashing(int stepsize) const
{
	std::vector<GameObject3DNoP> arr((const unsigned int)powf(2, 26));

	const auto start = std::chrono::high_resolution_clock().now();

	for (unsigned int i = 0; i < arr.size(); i += stepsize)
	{
		arr[i].ID *= 2;
	}

	const auto end = std::chrono::high_resolution_clock().now();

	std::cout << (int)(1000 * std::chrono::duration<float>(end - start).count()) << std::endl;

	return (int)(1000 * std::chrono::duration<float>(end - start).count());
}

int dae::ImGuiComponent::IntTrashing(int stepsize) const
{

	std::vector<int> arr((const unsigned int)powf(2, 26));

	const auto start = std::chrono::high_resolution_clock().now();

	for (unsigned int i = 0; i < arr.size(); i += stepsize)
	{
		arr[i] *= 2;
	}

	const auto end = std::chrono::high_resolution_clock().now();

	return (int)(1000 * std::chrono::duration<float>(end - start).count());
}


