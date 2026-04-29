#include "Game.h"
#include "../Scene.h"
#include "Chara/Chara.h"
#include "BackGround/BackGround.h"

void C_Game::Init()
{
	//new‚·‚é
	m_chara->Init();
	m_backGround->Init();
}

void C_Game::Update()
{
	m_chara->Update();
	m_backGround->Update();
}

void C_Game::Draw()
{
	m_chara->Draw();
	m_backGround->Draw();
}

void C_Game::Release()
{
	
}
