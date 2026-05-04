#include"Background.h"
#include "../../main.h"
#include"../../Scene.h"
#include"../../KeyManager.h"
#include"../Game.h"

C_Back::~C_Back()
{
}

void C_Back::Init()
{
	//îwåi1
	m_back1Tex.Load("Texture/Game/BackGround/back1.png");
	m_back2Tex.Load("Texture/Game/BackGround/back2.png");
	m_back3Tex.Load("Texture/Game/BackGround/back3.png");
	m_back4Tex.Load("Texture/Game/BackGround/back4.png");
	m_back5Tex.Load("Texture/Game/BackGround/back5.png");
	m_back6Tex.Load("Texture/Game/BackGround/back6.png");

	//îwåi2
	m_back1bTex.Load("Texture/Game/BackGround/back1.png");
	m_back2bTex.Load("Texture/Game/BackGround/back2.png");
	m_back3bTex.Load("Texture/Game/BackGround/back3.png");
	m_back4bTex.Load("Texture/Game/BackGround/back4.png");
	m_back5bTex.Load("Texture/Game/BackGround/back5.png");
	m_back6bTex.Load("Texture/Game/BackGround/back6.png");

	//ì˙åı
	m_light1Tex.Load("Texture/Game/BackGround/light1.png");
	m_light2Tex.Load("Texture/Game/BackGround/light2.png");
	m_light3Tex.Load("Texture/Game/BackGround/light3.png");

	m_back1bPos = { 0,0 };
	m_back2bPos = { 0,0 };
	m_back3bPos = { 0,0 };
	m_back4bPos = { 0,0 };
	m_back5bPos = { 0,0 };
	m_back6bPos = { 0,0 };


	m_back1bPos = { 1280,0 };
	m_back2bPos = { 1280,0 };
	m_back3bPos = { 1280,0 };
	m_back4bPos = { 1280,0 };
	m_back5bPos = { 1280,0 };
	m_back6bPos = { 1280,0 };

	m_light1Pos = { 1300,0 };
	m_light2Pos = {1600,0 };
	m_light3Pos = { 1900,0 };
}

void C_Back::Update()
{
	//îwåi1
	m_back1Mat = Math::Matrix::CreateTranslation(m_back1Pos.x, m_back1Pos.y, 0);
	m_back2Mat = Math::Matrix::CreateTranslation(m_back2Pos.x, m_back2Pos.y, 0);
	m_back3Mat = Math::Matrix::CreateTranslation(m_back3Pos.x, m_back3Pos.y, 0);
	m_back4Mat = Math::Matrix::CreateTranslation(m_back4Pos.x, m_back4Pos.y, 0);
	m_back5Mat = Math::Matrix::CreateTranslation(m_back5Pos.x, m_back5Pos.y, 0);
	m_back6Mat = Math::Matrix::CreateTranslation(m_back6Pos.x, m_back6Pos.y, 0);

	//îwåi2
	m_back1bMat = Math::Matrix::CreateTranslation(m_back1bPos.x, m_back1bPos.y, 0);
	m_back2bMat = Math::Matrix::CreateTranslation(m_back2bPos.x, m_back2bPos.y, 0);
	m_back3bMat = Math::Matrix::CreateTranslation(m_back3bPos.x, m_back3bPos.y, 0);
	m_back4bMat = Math::Matrix::CreateTranslation(m_back4bPos.x, m_back4bPos.y, 0);
	m_back5bMat = Math::Matrix::CreateTranslation(m_back5bPos.x, m_back5bPos.y, 0);
	m_back6bMat = Math::Matrix::CreateTranslation(m_back6bPos.x, m_back6bPos.y, 0);

	//ÉâÉCÉg
	m_light1Mat = Math::Matrix::CreateTranslation(m_light1Pos.x, m_light1Pos.y, 0);
	m_light2Mat = Math::Matrix::CreateTranslation(m_light2Pos.x, m_light2Pos.y, 0);
	m_light3Mat = Math::Matrix::CreateTranslation(m_light3Pos.x, m_light3Pos.y, 0);


	m_back1Pos.x -= 1.8f;
	m_back2Pos.x -= 1.3f;
	m_back3Pos.x -= 1.0f;
	m_back4Pos.x -= 0.6f;
	m_back5Pos.x -= 0.4f;
	m_back6Pos.x -= 0.2f;

	//îwåi2
	m_back1bPos.x -= 1.8f;
	m_back2bPos.x -= 1.3f;
	m_back3bPos.x -= 1.0f;
	m_back4bPos.x -= 0.6f;
	m_back5bPos.x -= 0.4f;
	m_back6bPos.x -= 0.2f;

	//ÉâÉCÉg
	m_light1Pos.x -= 1.3f;
	m_light2Pos.x -= 1.0f;
	m_light3Pos.x -= 0.6f;


	//îwåiÇÃÉãÅ[Évèàóù
	if (m_back1Pos.x <= -1280) m_back1Pos.x =1280;
	if (m_back2Pos.x <= -1280) m_back2Pos.x = 1280;
	if (m_back3Pos.x <= -1280) m_back3Pos.x = 1280;
	if (m_back4Pos.x <= -1280) m_back4Pos.x = 1280;
	if (m_back5Pos.x <= -1280) m_back5Pos.x = 1280;
	if (m_back6Pos.x <= -1280) m_back6Pos.x = 1280;
	//==========================================================
	if (m_back1bPos.x <= -1280) m_back1bPos.x =1280;
	if (m_back2bPos.x <= -1280) m_back2bPos.x =1280;
	if (m_back3bPos.x <= -1280) m_back3bPos.x =1280;
	if (m_back4bPos.x <= -1280) m_back4bPos.x =1280;
	if (m_back5bPos.x <= -1280) m_back5bPos.x =1280;
	if (m_back6bPos.x <= -1280) m_back6bPos.x =1280;

	//ÉâÉCÉgÇÃÉãÅ[Évèàóù
	if (m_light1Pos.x <= -1000) m_light1Pos.x = 1000;
	if (m_light2Pos.x <= -1000) m_light2Pos.x = 1000;
	if (m_light3Pos.x <= -1000) m_light3Pos.x = 1000;
}

void C_Back::Draw()
{
	
	SHADER.m_spriteShader.SetMatrix(m_back1Mat);
	SHADER.m_spriteShader.DrawTex_Src(&m_back1Tex);
	SHADER.m_spriteShader.SetMatrix(m_back1bMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_back1bTex);

	SHADER.m_spriteShader.SetMatrix(m_back2Mat);
	SHADER.m_spriteShader.DrawTex_Src(&m_back2Tex);
	SHADER.m_spriteShader.SetMatrix(m_back2bMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_back2bTex);

	//ÉâÉCÉg1
	SHADER.m_spriteShader.SetMatrix(m_light1Mat);
	SHADER.m_spriteShader.DrawTex_Src(&m_light1Tex);

	SHADER.m_spriteShader.SetMatrix(m_back3Mat);
	SHADER.m_spriteShader.DrawTex_Src(&m_back3Tex);
	SHADER.m_spriteShader.SetMatrix(m_back3bMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_back3bTex);

	SHADER.m_spriteShader.SetMatrix(m_back4Mat);
	SHADER.m_spriteShader.DrawTex_Src(&m_back4Tex);
	SHADER.m_spriteShader.SetMatrix(m_back4bMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_back4bTex);

	//ÉâÉCÉg2
	SHADER.m_spriteShader.SetMatrix(m_light2Mat);
	SHADER.m_spriteShader.DrawTex_Src(&m_light2Tex);

	SHADER.m_spriteShader.SetMatrix(m_back5Mat);
	SHADER.m_spriteShader.DrawTex_Src(&m_back5Tex);
	SHADER.m_spriteShader.SetMatrix(m_back5bMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_back5bTex);

	//ÉâÉCÉg3
	SHADER.m_spriteShader.SetMatrix(m_light3Mat);
	SHADER.m_spriteShader.DrawTex_Src(&m_light3Tex);

	SHADER.m_spriteShader.SetMatrix(m_back6Mat);
	SHADER.m_spriteShader.DrawTex_Src(&m_back6Tex);
	SHADER.m_spriteShader.SetMatrix(m_back6bMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_back6bTex);
	
	
}




