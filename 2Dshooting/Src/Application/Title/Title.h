#pragma once
#include"../Scene.h"

class C_Title:public C_SceneStateBase
{
public:
	C_Title();
	~C_Title()override { void Release(); };

	void Update();
	void Draw();
private:

	void Release();

	bool m_bCanPressKey;			//クリック判定

	//タイトル
	KdTexture m_titleTex;
	Math::Matrix m_titleMat;
	Math::Vector2 m_titlePos;

	//テキスト
	//スタート
	KdTexture m_playTex;
	Math::Matrix m_playMat;
	Math::Vector2 m_playPos;
	//操作方法
	KdTexture m_controlsTex;
	Math::Matrix m_controlsMat;
	Math::Vector2 m_controlsPos;
	//ストーリー
	KdTexture m_storyTex;
	Math::Matrix m_storyMat;
	Math::Vector2 m_storyPos;
	//クレジット
	KdTexture m_creditTex;
	Math::Matrix m_creditMat;
	Math::Vector2 m_creditPos;
	//退出
	KdTexture m_exitTex;
	Math::Matrix m_exitMat;
	Math::Vector2 m_exitPos;



	//中央オブジェクト
	KdTexture m_gateTex;
	Math::Matrix m_gateMat;
	Math::Vector2 m_gatePos;
	//中央オブジェクトエフェクト
	KdTexture m_gateEffectTex;
	Math::Matrix m_gateEffectMat;
	Math::Vector2 m_gateEffectPos;
	//点滅関数
	float m_gateEffectAlpha;
	float m_gateEffectDelta;

	//左右オブジェクト（オベリスク）
	static const int s_ObeliskNum = 4;
	bool m_bObeliskAnimFlg;				
	float m_obeliskAnimCnt;				
	KdTexture m_obeliskTex[s_ObeliskNum];
	Math::Matrix m_obeliskMat[s_ObeliskNum];
	Math::Vector2 m_obeliskPos[s_ObeliskNum];
	Math::Vector2 m_obeliskScale[s_ObeliskNum];

	//メニュー選択時オベリスクエフェクトとテキスト
	bool m_bObeliskEffectAnimFlg;				//オベリスクのエフェクトアニメーション状態
	float m_obeliskEffectAnimCnt;				//オベリスクのアニメーション
	KdTexture m_obeliskEffectTex[s_ObeliskNum];
	Math::Matrix m_obeliskEffectMat[s_ObeliskNum];
	Math::Vector2 m_obeliskEffectPos[s_ObeliskNum];

	//メニューテキスト選択時の		
	float m_textEffectAnimCnt;				
	KdTexture m_textEffectTex[s_ObeliskNum];
	Math::Matrix m_textEffectMat[s_ObeliskNum];
	Math::Vector2 m_textEffectPos[s_ObeliskNum];

	//背景（黒）
	KdTexture m_backGroundTex;
	Math::Matrix m_backGroundMat;
	Math::Vector2 m_backGroundPos;

	bool a;
	
};

