#include "Chara.h"
void C_Chara::Init()
{
	m_charaTex.Load("Texture/Chara/Idle.png");
	m_charaPos = { 0,0 };
	m_bCharaFlg = true;
	m_charaAnimCnt = 1;
	m_bCharaAnimFlg = true;
}

void C_Chara::Update()
{
	
	//自機のアニメーション
	if (m_bCharaAnimFlg == true)
	{
		m_charaAnimCnt += 0.4f;
		if (m_charaAnimCnt > 8)
		{
			m_charaAnimCnt = 1.0f;
		}
	}
	
	//移動
	//シフト押していたらスピードダウン
	if (GetAsyncKeyState('W')&0x8000)
	{
		m_charaPos.y += 8;
		if (GetAsyncKeyState(VK_SHIFT)&0x8000)
		{
			m_charaPos.y -=5;
		}
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_charaPos.y -= 8;
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
		{
			m_charaPos.y += 5;
		}
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_charaPos.x -= 8;
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
		{
			m_charaPos.x += 5;
		}
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_charaPos.x += 8;
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
		{
			m_charaPos.x -= 5;
		}
	}



	Math::Matrix transMat = Math::Matrix::CreateTranslation(m_charaPos.x, m_charaPos.y, 0);
	m_charaMat = transMat;
}

void C_Chara::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_charaMat);
	SHADER.m_spriteShader.DrawTex(&m_charaTex, Math::Rectangle{ (int)m_charaAnimCnt * 64,0,32,32 }, 1.0f);
		
}

void C_Chara::Release()
{
		m_charaTex.Release();
}


