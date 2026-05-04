#pragma once

enum SceneType
{
	Title,			//タイトル
	Game,			//ゲーム
	Result,			//リザルト
};

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
	Math::Vector2 GetMousePos() { return {(float)m_mousePos.x, (float)m_mousePos.y }; }

	//マウス座標と当たっているかを判定
	bool JudgeHitMouse(Math::Vector2 pos, Math::Vector2 radius);

	// GUI処理
	void ImGuiUpdate();

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
		pendingState = newState;
	}

	void Update() {
		// まず現在の状態を更新（この途中で ChangeState が呼ばれても safe）
		if (currentState) currentState->Update();

		// 更新後に遷移要求があれば安全に切り替え -> 新しい状態の初期化として Update を一度呼ぶ
		if (pendingState)
		{
			delete currentState;
			currentState = pendingState;
			pendingState = nullptr;
			if (currentState) 
			{
				currentState->Update(); // 初期化目的で一回呼ぶ（既存の実装意図を再現）
			}
		}
	}

	void Draw()
	{
		if(currentState)currentState->Draw();
	}

	void Release()
	{
		if (currentState)delete currentState;
		if (pendingState)delete pendingState;
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
