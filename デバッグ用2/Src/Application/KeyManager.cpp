#include "KeyManager.h"

bool C_KeyManager::IsPressing(char key)
{
	switch (key)
	{
	case VK_LBUTTON:
		return m_keyFlg & KeyFlg::LButton;
	case VK_RETURN:
		return m_keyFlg & KeyFlg::Return;
	case VK_TAB:
		return m_keyFlg & KeyFlg::Tab;
	default:return false;
	}
}

bool C_KeyManager::IsPressing()
{
	return m_keyFlg;
}

void C_KeyManager::Press(char key)
{
	switch (key)
	{
	case VK_LBUTTON: 
		m_keyFlg |= KeyFlg::LButton; 
		break;
	case VK_RETURN:
		m_keyFlg|= KeyFlg::Return;
		break;
	case VK_TAB:
		m_keyFlg |= KeyFlg::Tab;
		break;
	}
}

void C_KeyManager::DoNotPress(char key)
{
	switch (key)
	{
	case VK_LBUTTON:
		m_keyFlg &= ~KeyFlg::LButton;
		break;
	case VK_RETURN:
		m_keyFlg &= ~KeyFlg::Return;
		break;
	case VK_TAB:
		m_keyFlg &= ~KeyFlg::Tab;
		break;
	}
}

void C_KeyManager::Update()
{
	//クールタイムをデクリメントする
	m_coolDown--;
	if (m_coolDown < 0)m_coolDown = 0;

	//押されていなかったらフラグを立てない
	if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000))m_keyFlg &= ~KeyFlg::LButton;
	if (!(GetAsyncKeyState(VK_RETURN) & 0x8000))m_keyFlg &= ~KeyFlg::Return;
	if (!(GetAsyncKeyState(VK_TAB) & 0x8000))m_keyFlg &= ~KeyFlg::Tab;
}

