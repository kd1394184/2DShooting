#pragma once

class C_Game;

class Scene
{
private:


public:

	// ‰Šúİ’è
	void Init();

	// ‰ğ•ú
	void Release();

	// XVˆ—
	void Update();

	// •`‰æˆ—
	void Draw2D();

	// GUIˆ—
	void ImGuiUpdate();

private:

	Scene() {}
	C_Game* m_game

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
