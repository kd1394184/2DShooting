#include"Game.h"
#include"../Scene.h"
#include"../Title/Title.h"
#include"../KeyManager.h"


C_Game::C_Game()
{
    
	m_back.Init();
	m_chara.Init();
}

C_Game::~C_Game()
{

}

void C_Game::Update()
{
    m_back.Update();
    m_chara.Update();
 
}

void C_Game::Draw()
{
	m_back.Draw();
	m_chara.Draw();


}