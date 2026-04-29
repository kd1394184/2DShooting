#pragma once

class C_Chara
{

public:
	C_Chara() {};
	~C_Chara() { void Release();};

	void Init();
	void Update();
	void Draw();
	

private:
	void Release();


	//自機
	bool m_bCharaFlg;					//自機の生存状態
	bool m_bCharaAnimFlg;				//自機のアニメーション状態
	float m_charaAnimCnt;				//自機のアニメーション
	KdTexture m_charaTex;			
	Math::Matrix m_charaMat;				
	Math::Vector2 m_charaPos;
	
};

