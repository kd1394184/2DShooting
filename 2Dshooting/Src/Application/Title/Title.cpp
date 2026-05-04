#include"Title.h"
#include"../Scene.h"
#include "../System/KeyManager.h"
#include"../Game/Game.h"

C_Title::C_Title()
{
	a = false;

	m_gateTex.Load("Texture/Title/gate.png");
	m_gateEffectTex.Load("Texture/Title/gateEffect.png");
	m_backGroundTex.Load("Texture/Title/backGround.png");
	m_titleTex.Load("Texture/Title/title.png");
	
	//テキストの読み込み
	m_playTex.Load("Texture/Title/playText.png");
	m_controlsTex.Load("Texture/Title/controlsText.png");
	m_storyTex.Load("Texture/Title/storyText.png");
	m_creditTex.Load("Texture/Title/creditText.png");
	m_exitTex.Load("Texture/Title/exitText.png");

	//メニュー選択時
	m_controlShowTex.Load("Texture/Title/Menu/control.png");
	m_storyShowTex.Load("Texture/Title/Menu/story.png");
	m_creditShowTex.Load("Texture/Title/Menu/credit.png");
	
	for (int i = 0; i < s_ObeliskNum; i++)	
	{
		m_obeliskTex[i].Load("Texture/Title/obelisk.png");
		//選択のオベリスクのエフェクト
		m_obeliskEffectTex[i].Load("Texture/Title/obeliskEffect.png");
		//選択時のテキストのエフェクト
		m_textEffectTex[i].Load("Texture/Title/textEffect.png");	

		m_obeliskPos[0] = {-500,0};
		m_obeliskPos[1] = {-300,0};
		m_obeliskPos[2] = {300,0};
		m_obeliskPos[3] = {500,0};

		m_obeliskEffectPos[0] = m_obeliskPos[0];
		m_obeliskEffectPos[1] = m_obeliskPos[1];
		m_obeliskEffectPos[2] = m_obeliskPos[2];
		m_obeliskEffectPos[3] = m_obeliskPos[3];

		m_textEffectPos[0] = { m_obeliskPos[0].x,-220 };
		m_textEffectPos[1] = { m_obeliskPos[1].x,-220 };
		m_textEffectPos[2] = { m_obeliskPos[2].x,-220 };
		m_textEffectPos[3] = { m_obeliskPos[3].x,-220 };

	}

	m_gatePos = { 0,-100 };
	m_gateEffectPos = { 0,-100 };
	m_backGroundPos = { 0,0 };
	m_titlePos = { 0,200 };

	//テキストの位置
	m_playPos = { 0,-250 };
	m_controlsPos = { m_obeliskPos[0].x,-220};
	m_storyPos = { m_obeliskPos[1].x,-220 };
	m_creditPos = { m_obeliskPos[2].x,-220 };
	m_exitPos = { m_obeliskPos[3].x,-220 };

	//メニュー選択時の表示画像の位置
	m_controlShowPos = { 0,-320 };
	m_storyShowPos = { 0,-320 };
	m_creditShowPos = { 0,-300 };

	//フラグ
	m_bCanPressKey = false;			//クリック判定フラグ
	m_bControlShowFlg = false;		//コントロールの表示フラグ
	m_bStoryShowFlg = false;		//ストーリーの表示フラグ
	m_bCreditShowFlg = false;		//クレジットの表示フラグ

	//点滅関数
	m_gateEffectAlpha = 0.6f;
	m_gateEffectDelta = -0.01f;
	
	//エフェクト管理フラグ
	for (int i = 0; i < s_ObeliskNum; i++)
	{
		m_bEffectFlg[i] = false;
	}
	m_bGateEffectFlg = false;

	//オベリスクのアニメーション
	m_obeliskAnimCnt = 1;
	m_bObeliskAnimFlg = true;
	//オベリスクのエフェクトアニメーション
	m_obeliskEffectAnimCnt = 1;
	m_bObeliskEffectAnimFlg = true;
	//テキストのエフェクトアニメーション
	m_textEffectAnimCnt = 1;


	
}

void C_Title::Update()
{

	m_gateMat =Math::Matrix::CreateTranslation(m_gatePos.x, m_gatePos.y, 0);			//行列		
	m_gateEffectMat =Math::Matrix::CreateTranslation(m_gateEffectPos.x, m_gateEffectPos.y, 0);					
	m_backGroundMat = Math::Matrix::CreateTranslation(m_backGroundPos.x, m_backGroundPos.y, 0);

	//タイトルの行列
	m_titleMat = Math::Matrix::CreateTranslation(m_titlePos.x, m_titlePos.y, 0);
	//テキストの行列
	m_playMat = Math::Matrix::CreateTranslation(m_playPos.x, m_playPos.y, 0);
	m_controlsMat = Math::Matrix::CreateTranslation(m_controlsPos.x, m_controlsPos.y, 0);
	m_storyMat = Math::Matrix::CreateTranslation(m_storyPos.x, m_storyPos.y, 0);
	m_creditMat = Math::Matrix::CreateTranslation(m_creditPos.x, m_creditPos.y, 0);
	m_exitMat = Math::Matrix::CreateTranslation(m_exitPos.x, m_exitPos.y, 0);

	//メニュー選択時の表示画像の行列
	m_controlShowMat = Math::Matrix::CreateTranslation(m_controlShowPos.x, m_controlShowPos.y, 0);
	m_storyShowMat = Math::Matrix::CreateTranslation(m_storyShowPos.x, m_storyShowPos.y, 0);
	m_creditShowMat = Math::Matrix::CreateTranslation(m_creditShowPos.x, m_creditShowPos.y, 0);

	for (int i = 0; i < s_ObeliskNum; i++)
	{
		m_obeliskMat[i] = Math::Matrix::CreateTranslation(m_obeliskPos[i].x, m_obeliskPos[i].y, 0);
	}

	//オベリスクのアニメーション
	m_obeliskAnimCnt += 0.2f;
	if (m_obeliskAnimCnt > 13)
	{
		m_obeliskAnimCnt = 1.0f;
	}
	//オベリスクのエフェクトアニメーション
	m_obeliskEffectAnimCnt += 0.7f;
	if (m_obeliskEffectAnimCnt > 16)
	{
		m_obeliskEffectAnimCnt = 1.0f;
		for (int i = 0; i < s_ObeliskNum; i++)
		{
			m_obeliskEffectMat[i] = Math::Matrix::CreateTranslation(m_obeliskEffectPos[i].x, m_obeliskEffectPos[i].y, 0);
			m_textEffectMat[i] = Math::Matrix::CreateTranslation(m_textEffectPos[i].x, m_textEffectPos[i].y, 0);
		}
	}

	//テキストのエフェクトアニメーション
	m_textEffectAnimCnt += 0.5f;
	if (m_textEffectAnimCnt > 16)
	{
		m_textEffectAnimCnt = 1.0f;
		for (int i = 0; i < s_ObeliskNum; i++)
		{
			m_textEffectMat[i] = Math::Matrix::CreateTranslation(m_textEffectPos[i].x, m_textEffectPos[i].y, 0);
		}
	}

	//メニューの選択
	//============================================================================
	if (GetAsyncKeyState(VK_LBUTTON)&0x8000)
	{
		if (m_bCanPressKey)
		{
			//クリックされていない
			m_bCanPressKey = false;

			if (SCENE.JudgeHitMouse(m_controlsPos,m_controlsTex.GetRadius()))
			{
				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
				{
					if (!KEY_MANAGER.IsPressing(VK_LBUTTON))
					{
						KEY_MANAGER.Press(VK_LBUTTON);

						m_bControlShowFlg = true;		//コントロールの表示フラグを立てる

					}
				}
			}

			if (SCENE.JudgeHitMouse(m_storyPos, m_storyTex.GetRadius()))
			{
				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
				{
					if (!KEY_MANAGER.IsPressing(VK_LBUTTON))
					{
						KEY_MANAGER.Press(VK_LBUTTON);

						m_bStoryShowFlg = true;			//ストーリーの表示フラグを立てる
					}
				}
			}

			if (SCENE.JudgeHitMouse(m_creditPos, m_creditTex.GetRadius()))
			{
				
				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
				{
					if (!KEY_MANAGER.IsPressing(VK_LBUTTON))
					{
						KEY_MANAGER.Press(VK_LBUTTON);

						m_bCreditShowFlg = true;			//クレジットの表示フラグを立てる
					}
				}
				
			}

			if (SCENE.JudgeHitMouse(m_obeliskPos[3], m_obeliskTex[3].GetRadius()))
			{
				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
				{
					if (!KEY_MANAGER.IsPressing(VK_LBUTTON))
					{
						KEY_MANAGER.Press(VK_LBUTTON);

						//↓↓退出↓↓


					}
				}
			}

			if (SCENE.JudgeHitMouse(m_playPos, m_playTex.GetRadius()))
			{
				
				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
				{
					if (!KEY_MANAGER.IsPressing(VK_LBUTTON))
					{
						KEY_MANAGER.Press(VK_LBUTTON);

						//スタートの処理
						SCENE_MANAGER.ChangeState(new C_Game());
						return;

					}
				}
			}
			
		}
	}

	else
	{
		m_bCanPressKey = true;
	}

	//============================================================================

	//オベリスクと当たっているか

		//最左オベリスク
		if (SCENE.JudgeHitMouse(m_controlsPos, m_controlsTex.GetRadius()))
		{
			m_bEffectFlg[0] = true;
		}
		//近左オベリスク
		else if (SCENE.JudgeHitMouse(m_storyPos, m_storyTex.GetRadius()))
		{
			m_bEffectFlg[1] = true;
		}
		//近右オベリスク
		else if (SCENE.JudgeHitMouse(m_creditPos, m_creditTex.GetRadius()))
		{
			m_bEffectFlg[2] = true;
		}
		//最右オベリスク
		else if (SCENE.JudgeHitMouse(m_exitPos, m_exitTex.GetRadius()))
		{
			m_bEffectFlg[3] = true;
		}
	
		else
		{
			for (int i = 0; i < s_ObeliskNum; i++)
			{
				m_bEffectFlg[i] = false;
			}
		}


	//ゲートと当たっているか
	if (SCENE.JudgeHitMouse(m_playPos, m_playTex.GetRadius()))
	{
		m_bGateEffectFlg = true;
	}

	else
	{
		m_bGateEffectFlg = false;
	}

	//点滅処理
	m_gateEffectAlpha += m_gateEffectDelta;

	if (m_gateEffectAlpha <= 0.2f) { m_gateEffectDelta = 0.01f; }
	else if (m_gateEffectAlpha >=0.6) { m_gateEffectDelta = -0.01f; }

	
}

void C_Title::Draw()
{
	Math::Vector2 radius;

	//背景（上に描画書かない）
	SHADER.m_spriteShader.SetMatrix(m_backGroundMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_backGroundTex);

	//タイトル
	SHADER.m_spriteShader.SetMatrix(m_titleMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_titleTex);

	for (int i = 0; i < s_ObeliskNum; i++)
	{
		if (m_bEffectFlg[i])
		{
			SHADER.m_spriteShader.SetMatrix(m_textEffectMat[i]);
			SHADER.m_spriteShader.DrawTex(&m_textEffectTex[i], Math::Rectangle{ (int)m_textEffectAnimCnt * 100,0,100,80 }, 0.7f);
		}
	}

	//テキスト類
	////スタート
	SHADER.m_spriteShader.SetMatrix(m_playMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_playTex);
	//操作方法
	SHADER.m_spriteShader.SetMatrix(m_controlsMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_controlsTex);
	//ストーリー
	SHADER.m_spriteShader.SetMatrix(m_storyMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_storyTex);
	//クレジット
	SHADER.m_spriteShader.SetMatrix(m_creditMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_creditTex);
	//退出
	SHADER.m_spriteShader.SetMatrix(m_exitMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_exitTex);

	//エフェクト
	if (!m_bGateEffectFlg)
	{
		SHADER.m_spriteShader.SetMatrix(m_gateMat);
		SHADER.m_spriteShader.DrawTex_Src(&m_gateTex);
	}

	else
	{
		SHADER.m_spriteShader.SetMatrix(m_gateEffectMat);
		Math::Color  color{ 1,1,1,m_gateEffectAlpha };
		SHADER.m_spriteShader.DrawTex_Color(&m_gateEffectTex, &color);
		SHADER.m_spriteShader.SetMatrix(m_gateMat);
		SHADER.m_spriteShader.DrawTex_Src(&m_gateTex);
	}


	if (m_bEffectFlg[0])
	{
		SHADER.m_spriteShader.SetMatrix(m_obeliskEffectMat[0]);
		SHADER.m_spriteShader.DrawTex(&m_obeliskEffectTex[0], Math::Rectangle{ (int)m_obeliskEffectAnimCnt * 170,0,170,301 }, 1.0f);
	}

	else if (m_bEffectFlg[1])
	{
		SHADER.m_spriteShader.SetMatrix(m_obeliskEffectMat[1]);
		SHADER.m_spriteShader.DrawTex(&m_obeliskEffectTex[1], Math::Rectangle{ (int)m_obeliskEffectAnimCnt * 170,0,170,301 }, 1.0f);
	}
	
	else if (m_bEffectFlg[2])
	{
		SHADER.m_spriteShader.SetMatrix(m_obeliskEffectMat[2]);
		SHADER.m_spriteShader.DrawTex(&m_obeliskEffectTex[2], Math::Rectangle{ (int)m_obeliskEffectAnimCnt * 170,0,170,301 }, 1.0f);
	}

	else if (m_bEffectFlg[3])
	{
		SHADER.m_spriteShader.SetMatrix(m_obeliskEffectMat[3]);
		SHADER.m_spriteShader.DrawTex(&m_obeliskEffectTex[3], Math::Rectangle{ (int)m_obeliskEffectAnimCnt * 170,0,170,301 }, 1.0f);
	}

	//オベリスクの描画処理
	for (int i = 0; i < s_ObeliskNum; i++)
	{
		//オベリスクの描画処理
		SHADER.m_spriteShader.SetMatrix(m_obeliskMat[i]);
		SHADER.m_spriteShader.DrawTex(&m_obeliskTex[i], Math::Rectangle{ (int)m_obeliskAnimCnt * 200,0,200,400 }, 1.0f);
	}

	//メニュー選択時の表示画像の描画処理
	if (m_bControlShowFlg)
	{
		SHADER.m_spriteShader.SetMatrix(m_controlShowMat);
		SHADER.m_spriteShader.DrawTex_Src(&m_controlShowTex);
	}
	else if (m_bStoryShowFlg)
	{
		SHADER.m_spriteShader.SetMatrix(m_storyShowMat);
		SHADER.m_spriteShader.DrawTex_Src(&m_storyShowTex);
	}
	else if (m_bCreditShowFlg)
	{
		SHADER.m_spriteShader.SetMatrix(m_creditShowMat);
		SHADER.m_spriteShader.DrawTex_Src(&m_creditShowTex);
	}

}

void C_Title::Release()
{
	m_titleTex.Release();
	m_playTex.Release();	
	m_controlsTex.Release();
	m_storyTex.Release();
	m_gateTex.Release();
	m_gateEffectTex.Release();
	m_backGroundTex.Release();
	
	
	for (int i = 0; i < s_ObeliskNum; i++)
	{
		m_obeliskTex[i].Release();
		m_obeliskEffectTex[i].Release();
		m_textEffectTex[i].Release();
	}
}