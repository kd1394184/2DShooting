#include "main.h"
#include "Scene.h"
#include"Title/Title.h"
#include"Game/Game.h"

void Scene::Draw2D()
{
	SCENE_MANAGER.Draw();

	//マウス描画
	Math::Matrix rotatMat = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(30));
	Math::Matrix transMat = Math::Matrix::CreateTranslation(m_mousePos.x, m_mousePos.y, 0);
	Math::Matrix scaleMat = Math::Matrix::CreateScale(0.06f, 0.07f, 0);
	m_mouseMat = scaleMat * rotatMat * transMat;
	SHADER.m_spriteShader.SetMatrix(m_mouseMat);
	SHADER.m_spriteShader.DrawTex_Color(&m_mouseTex, &Math::Color{ 0,0,0,1 });

	scaleMat = Math::Matrix::CreateScale(1.0f, 1.0f, 0);
	m_mouseMat = scaleMat * rotatMat * transMat;
	SHADER.m_spriteShader.SetMatrix(m_mouseMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_mouseTex);
}

void Scene::Update()
{
	//マウス座標取得
	m_mousePos = ConvertMousePos();

	SCENE_MANAGER.Update();
}

void Scene::Init()
{
	//乱数の初期化
	srand(timeGetTime());

	//マウス画像
	m_mouseTex.Load("Texture/System/Cursor.png");

	//マウスカーソルは見えないようにする
	ShowCursor(false);

	//タイトルにする
	SCENE_MANAGER.ChangeState(new C_Title());
}


void Scene::Release()
{
	//マウス画像の解放
	m_mouseTex.Release();
}

//マウス座標を取得
POINT Scene::ConvertMousePos()
{
	POINT mousePos;

	//ディスプレイ上のマウス座標取得
	GetCursorPos(&mousePos);

	//ウィンドウ上のマウス座標に変換（ウィンドウ左上(0,0)）
	ScreenToClient(APP.m_window.GetWndHandle(), &mousePos);

	//マウス座標を補正（ウィンドウの中心（0,0））
	mousePos.x += SCREEN_LEFT;
	mousePos.y += SCREEN_BOTTOM;
	mousePos.y *= -1;

	return mousePos;
}

//マウスとの当たり判定
bool Scene::JudgeHitMouse(Math::Vector2 pos, Math::Vector2 radius)
{
	const float Left = pos.x - radius.x;
	const float Right = pos.x + radius.x;
	const float Top = pos.y + radius.y;
	const float Bottom = pos.y - radius.y;

	if (Left <= m_mousePos.x &&
		Right >= m_mousePos.x &&
		Top >= m_mousePos.y &&
		Bottom <= m_mousePos.y)
	{
		return true;
	}
	else
	{
		return false;
	}
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

