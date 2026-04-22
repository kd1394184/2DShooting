#pragma once
class C_BackGround
{
public:
	C_BackGround() {};
	~C_BackGround() { void Release(); };
	void Init();
	void Update();
	void Draw();
	

private:
	void Release();
};
