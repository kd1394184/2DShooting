#pragma once

class C_Chara;
class C_BackGround;

class C_Game
{
public:
	C_Game() {};
	~C_Game() { void Release(); };

	void Init();
	void Update();
	void Draw();
	

private:
	
	void Release();
	C_Chara* m_chara;
	C_BackGround* m_backGround;
};

