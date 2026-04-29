#include"Title.h"
#include"../Scene.h"



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


	//点滅関数
	m_gateEffectAlpha = 0.6f;
	m_gateEffectDelta = -0.01f;
	
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

	//オベリスクのアニメーション
	m_obeliskAnimCnt += 0.2f;
	if (m_obeliskAnimCnt > 13)
	{
		m_obeliskAnimCnt = 1.0f;
		for (int i = 0; i < s_ObeliskNum; i++)
		{
			m_obeliskMat[i] = Math::Matrix::CreateTranslation(m_obeliskPos[i].x, m_obeliskPos[i].y, 0);
		}
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

	m_textEffectAnimCnt += 0.01f;
	if (m_textEffectAnimCnt > 16)
	{
		m_textEffectAnimCnt = 1.0f;
		for (int i = 0; i < s_ObeliskNum; i++)
		{
			m_textEffectMat[i] = Math::Matrix::CreateTranslation(m_textEffectPos[i].x, m_textEffectPos[i].y, 0);
		}
	}


	//マウスと当たっているか
	Math::Vector2 radius = m_obeliskTex[0].GetRadius();

	//メニュー選択の処理
	if (GetAsyncKeyState(VK_LBUTTON)&0x8000)
	{
		if (m_bCanPressKey)
		{
			//クリックされていない
			m_bCanPressKey = false;

			if (SCENE.JudgeHitMouse(m_obeliskPos[0],radius))
			{
				a = true;
			}


		}

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
		SHADER.m_spriteShader.SetMatrix(m_textEffectMat[i]);
		SHADER.m_spriteShader.DrawTex(&m_textEffectTex[i], Math::Rectangle{ (int)m_textEffectAnimCnt * 136,0,136,80 }, 0.7f);
	}

	//テキスト類
	//スタート
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
	SHADER.m_spriteShader.SetMatrix(m_gateEffectMat);
	Math::Color  color{ 1,1,1,m_gateEffectAlpha };
	SHADER.m_spriteShader.DrawTex_Color(&m_gateEffectTex, &color);
	SHADER.m_spriteShader.SetMatrix(m_gateMat);
	SHADER.m_spriteShader.DrawTex_Src(&m_gateTex);


	//オベリスクのエフェクトの描画処理
	for (int i = 0; i < s_ObeliskNum; i++)
	{
		SHADER.m_spriteShader.SetMatrix(m_obeliskEffectMat[i]);
		SHADER.m_spriteShader.DrawTex(&m_obeliskEffectTex[i], Math::Rectangle{ (int)m_obeliskEffectAnimCnt * 170,0,170,301 }, 1.0f);
	
		//オベリスクの描画処理
		SHADER.m_spriteShader.SetMatrix(m_obeliskMat[i]);
		SHADER.m_spriteShader.DrawTex(&m_obeliskTex[i], Math::Rectangle{ (int)m_obeliskAnimCnt * 200,0,200,400 }, 1.0f);
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
	}
}