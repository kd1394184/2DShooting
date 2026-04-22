#include "main.h"
#include "Scene.h"


void Scene::Draw2D()
{
	m_game.m_chara->Draw();
	m_game.m_backGround->Draw();
}

void Scene::Update()
{
	m_chara.Update();
	m_backGround.Update();
}

void Scene::Init()
{
	m_chara.Init();
	m_backGround.Init();
}

void Scene::Release()
{
	m_chara.Release();
	m_backGround.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
