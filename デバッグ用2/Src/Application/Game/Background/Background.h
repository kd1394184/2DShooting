#pragma once


class C_Game;

class C_Back
{
public:

	C_Back() {}
	~C_Back();

	void Init();
	void Update();
	void Draw();

private:

	//“úŒõ
	KdTexture m_light1Tex;
	Math::Matrix m_light1Mat;
	Math::Vector2 m_light1Pos;

	KdTexture m_light2Tex;
	Math::Matrix m_light2Mat;
	Math::Vector2 m_light2Pos;

	KdTexture m_light3Tex;
	Math::Matrix m_light3Mat;
	Math::Vector2 m_light3Pos;


	//”wŒi‚P
	KdTexture m_back1Tex;			
	Math::Matrix m_back1Mat;
	Math::Vector2 m_back1Pos;

	KdTexture m_back2Tex;
	Math::Matrix m_back2Mat;
	Math::Vector2 m_back2Pos;

	KdTexture m_back3Tex;
	Math::Matrix m_back3Mat;
	Math::Vector2 m_back3Pos;
	
	KdTexture m_back4Tex;
	Math::Matrix m_back4Mat;
	Math::Vector2 m_back4Pos;

	KdTexture m_back5Tex;
	Math::Matrix m_back5Mat;
	Math::Vector2 m_back5Pos;

	KdTexture m_back6Tex;
	Math::Matrix m_back6Mat;
	Math::Vector2 m_back6Pos;


	//”wŒi2
	KdTexture m_back1bTex;
	Math::Matrix m_back1bMat;
	Math::Vector2 m_back1bPos;

	KdTexture m_back2bTex;
	Math::Matrix m_back2bMat;
	Math::Vector2 m_back2bPos;

	KdTexture m_back3bTex;
	Math::Matrix m_back3bMat;
	Math::Vector2 m_back3bPos;

	KdTexture m_back4bTex;
	Math::Matrix m_back4bMat;
	Math::Vector2 m_back4bPos;

	KdTexture m_back5bTex;
	Math::Matrix m_back5bMat;
	Math::Vector2 m_back5bPos;

	KdTexture m_back6bTex;
	Math::Matrix m_back6bMat;
	Math::Vector2 m_back6bPos;
};
