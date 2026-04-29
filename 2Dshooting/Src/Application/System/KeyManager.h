#pragma once

class C_KeyManager
{
public:

	bool IsPressing(char key);	
	bool IsPressing();			

	void Press(char key);		
	void DoNotPress(char key);	

	void SetCoolDown(int coolDown)		
	{
		m_coolDown = coolDown;
	}

	int GetCoolDown()					 
	{
		return m_coolDown;
	}

	void Update();

private:

	enum KeyFlg
	{
		NoPress = 0,			//0:何も押されていない
		LButton = 1 << 0,		//1:左クリック
		RButton = 1 << 1,		//2:右クリック
		Space = 1 << 2,			//4:スペース
	};

	int m_keyFlg;

	int m_coolDown;

private:
	C_KeyManager() {
		m_keyFlg = KeyFlg::NoPress;
		m_coolDown = 0;
	}
public:
	static C_KeyManager& GetInstance()
	{
		static C_KeyManager instance;
		return instance;
	}
};

#define KEY_MANAGER C_KeyManager::GetInstance()
