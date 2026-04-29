#pragma once

//enum SceneType
//{
//	Title,
//	Game,
//	Result
//};

class Scene
{
private:

	//マウス座標
	POINT m_mousePos;
	//マウス画像
	KdTexture m_mouseTex;
	//マウス行列
	Math::Matrix m_mouseMat;


public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();


	//マウス座標を変換する
	POINT ConvertMousePos();

	//マウス座標を他クラスに渡す
	Math::Vector2 GetMousePos() { return { (float)m_mousePos.x, (float)m_mousePos.y }; }

	//マウス座標と当たっているかを判定
	bool JudgeHitMouse(Math::Vector2 pos, Math::Vector2 radius);


	// GUI処理
	void ImGuiUpdate();

	//画面左
	int GetScreenLeft() { return -640; }
	//画面右
	int GetScreenRightt() { return 640; }
	//画面上
	int GetScreenUp() { return 360; }
	//画面下
	int GetScreenDown() { return -360; }



private:

	Scene() {}
	
public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

//シーンステータスの土台クラス
class C_SceneStateBase
{
public:
	virtual ~C_SceneStateBase() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

//シーン管理用クラス
class C_SceneManager
{
public:

	void ChangeState(C_SceneStateBase* newState)
	{
		delete currentState;
		currentState = newState;
		
	}

	void Update() 
	{
		currentState->Update();
	}

	void Draw()
	{
		currentState->Draw();
	}

	


private:

	C_SceneStateBase* currentState = nullptr;
	C_SceneStateBase* pendingState = nullptr;

	//シングルトン
private:
	C_SceneManager() {}
public:
	static C_SceneManager& GetInstance()
	{
		static C_SceneManager instance;
		return instance;
	}
};

#define SCENE_MANAGER C_SceneManager::GetInstance()

#define SCENE Scene::GetInstance()
