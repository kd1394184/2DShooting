#include "KeyManager.h"

bool C_KeyManager::IsPressing(char key)
{
	switch (key)
	{
	case VK_LBUTTON:
		return m_keyFlg & KeyFlg::LButton;
	case VK_RBUTTON:
		return m_keyFlg & KeyFlg::RButton;
	case VK_SPACE:
		return m_keyFlg & KeyFlg::Space;
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
	case VK_RBUTTON:
		m_keyFlg |= KeyFlg::RButton;
		break;
	case VK_SPACE:
		m_keyFlg |= KeyFlg::Space;
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
	case VK_RBUTTON:
		m_keyFlg &= ~KeyFlg::RButton;
		break;
	case VK_SPACE:
		m_keyFlg &= ~KeyFlg::Space;
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
	if (!(GetAsyncKeyState(VK_RBUTTON) & 0x8000))m_keyFlg &= ~KeyFlg::RButton;
	if (!(GetAsyncKeyState(VK_SPACE) & 0x8000))m_keyFlg &= ~KeyFlg::Space;
}

