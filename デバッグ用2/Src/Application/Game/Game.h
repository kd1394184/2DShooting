#pragma once
#include"../Scene.h"
#include"Background/Background.h"
#include"Chara/Chara.h"


class C_Game :public C_SceneStateBase
{
public:
    C_Game();
    ~C_Game() override;


    void Update();
    void Draw();

	C_Back& GetBackInst() { return m_back; }
	C_Chara& GetCharaInst() { return m_chara; }

private:

	C_Back m_back;			//îwåi
	C_Chara m_chara;		//é©ã@
   


};
