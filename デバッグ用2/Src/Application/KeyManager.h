#pragma once

class C_KeyManager
{
public:
	
	bool IsPressing(char key);	//指定したキーが押されているかを判別
	bool IsPressing();			//何らかのキーが押されているかを判別

	void Press(char key);		//指定したキーを押している	情報を格納する
	void DoNotPress(char key);	//指定したキーを押していない情報を格納する

	void SetCoolDown(int coolDown)		//キーを指定した時間押せなくする
	{
		m_coolDown = coolDown;
	}

	int GetCoolDown()					//キーが押せない時間の情報を知る 
	{ return m_coolDown; }

	void Update();

private:
	//各ビット毎に対応するキーフラグ（現在KeyManegerクラスで対応している全てのキー）
	enum KeyFlg
	{
		NoPress = 0,			//0:何も押されていない
		LButton = 1 << 0,		//1:左クリック
		Return	= 1 << 1,		//2:エンターキー
		Tab		= 1 << 2,		//4:タブキー
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
