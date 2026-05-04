#include "System/KdSystem.h"

#include "KdAudio.h"


//==================================================================
//
// SoundInstance
//
//==================================================================
void KdSoundInstance::Play(bool loop, bool manage)
{
	if(m_instance == nullptr)return;

	// 設定
	m_instance->Stop();
	//m_Inst->SetVolume(1);

	// 再生
	m_instance->Play(loop);

	// 再生リストへ追加
	if (manage)
	{
		AUDIO.AddPlayList(shared_from_this());
	}
}

// 3D Sound Ver
void KdSoundInstance::Play3D(const Math::Vector3& pos, bool loop, bool manage)
{
	if (m_instance == nullptr)return;

	// 設定
	m_instance->Stop();
	m_instance->SetVolume(1);

	// 再生
	m_instance->Play(loop);

	// 座標設定
	m_emitter.SetPosition(pos);
//	m_emitter.CurveDistanceScaler = FLT_MAX;

	Apply3D();


	// 再生リストへ追加
	if (manage)
	{
		AUDIO.AddPlayList(shared_from_this());
	}
}

void KdSoundInstance::Apply3D()
{
	if (m_instance == nullptr)return;

	m_instance->Apply3D(AUDIO.GetListener(), m_emitter, false);
}

void KdSoundInstance::SetVolume(float vol)
{
	if (m_instance == nullptr)return;

	m_instance->SetVolume(vol);
}

void KdSoundInstance::SetPos(const Math::Vector3& pos)
{
	if (m_instance == nullptr)return;

	// 座標設定
	m_emitter.SetPosition(pos);

	m_instance->Apply3D(AUDIO.GetListener(), m_emitter, false);
}

void KdSoundInstance::SetCurveDistanceScaler(float val)
{
	if (m_instance == nullptr)return;

	m_emitter.CurveDistanceScaler = val;

	m_instance->Apply3D(AUDIO.GetListener(), m_emitter, false);
}

bool KdSoundInstance::IsPlay()
{
	if (m_instance == nullptr)return false;

	if (m_instance->GetState() == DirectX::SoundState::PLAYING)return true;

	return false;
}

bool KdSoundInstance::IsPause()
{
	if (m_instance == nullptr)return false;

	if (m_instance->GetState() == DirectX::SoundState::PAUSED)return true;

	return false;
}

KdSoundInstance::~KdSoundInstance()
{
	Stop();

	m_instance = nullptr;
	m_srcData = nullptr;
}

//==================================================================
//
// SoundEffect
//
//==================================================================
bool KdSoundEffect::Load(const std::string& fileName)
{
	if(!AUDIO.IsInit())return false;


	try 
	{
		// wstringに変換
		std::wstring wFilename = sjis_to_wide(fileName);

		// 読み込み
		m_soundEffect = std::make_unique<DirectX::SoundEffect>(AUDIO.GetAudioEngine().get(), wFilename.c_str());
	}
	catch (...) 
	{
		return false;
	}
	
	// ファイル名記憶
	m_fileName = fileName;

	return true;
}

std::shared_ptr<KdSoundInstance> KdSoundEffect::CreateInstance(bool b3D)
{
	if(AUDIO.IsInit() == false)return nullptr;
	if (m_soundEffect == nullptr)return nullptr;

	// SoundInstanceはprivateコンストラクタなので、make_sharedを使わない方法で作成する
	std::shared_ptr<KdSoundInstance> inst = std::shared_ptr<KdSoundInstance>(new KdSoundInstance());

	// フラグ
	DirectX::SOUND_EFFECT_INSTANCE_FLAGS flags = DirectX::SoundEffectInstance_Default;
	if (b3D) {
		flags = flags | DirectX::SoundEffectInstance_Use3D | DirectX::SoundEffectInstance_ReverbUseFilters;
	}

	// インスタンス設定
	inst->Init(m_soundEffect->CreateInstance(flags), shared_from_this(), b3D);

	return inst;
}


//==================================================================
//
//
// AudioManager
//
//
//==================================================================

bool KdAudioManager::Init()
{
	Release();

	DirectX::AUDIO_ENGINE_FLAGS eflags = DirectX::AudioEngine_ReverbUseFilters;
	#ifdef _DEBUG
	eflags = eflags | DirectX::AudioEngine_Debug;
	#endif
	
	m_audioEng = std::make_unique<DirectX::AudioEngine>( eflags );
	m_audioEng->SetReverb(DirectX::Reverb_Default);

	m_listener.OrientFront = { 0, 0, 1 };

    SELoad();
    BGMLoad();

	return true;
}


void KdAudioManager::Release()
{
	m_playList.clear();
	se.clear();
    m_seList.clear();
	bgm.clear();
    m_bgmList.clear();

	m_audioEng = nullptr;

}

void KdAudioManager::SELoad()
{
	

}

void KdAudioManager::BGMLoad()
{
	

}

void KdAudioManager::StopAll()
{
	if(m_audioEng == nullptr)return;

	// 再生リスト
	{
		auto it = m_playList.begin();
		while(it != m_playList.end()){
			(*it).second->Stop();
			++it;
		}
		m_seList.clear();
		m_bgmList.clear();
	}

}

void KdAudioManager::SE(SE_ID id, float vol)
{

	m_seList[id] = se[id]->CreateInstance(false);
	m_seList[id]->SetVolume(vol);

	if (m_seList[id]->IsPlay() == false)
	{
		m_seList[id]->Play();
	}

}

void KdAudioManager::BGMPlay(BGM_ID id, float vol, bool Loop)
{

	if (!m_bgmList[id])
	{
		m_bgmList[id] = bgm[id]->CreateInstance(false);
		m_bgmList[id]->SetVolume(vol);

		m_bgmList[id]->Play(Loop);
	}

}

void KdAudioManager::SetVolume(BGM_ID id, float vol)
{
	if (m_bgmList[id])
	{
		m_bgmList[id]->SetVolume(vol);
	}

}

void KdAudioManager::Stop(BGM_ID id)
{

	if (m_bgmList[id])
	{
		m_bgmList[id]->Stop();
		m_bgmList[id].reset();
	}

}

void KdAudioManager::Pause(BGM_ID id)
{

	if (m_bgmList[id]->IsPause() == false && !m_bgmList[id])
	{
		m_bgmList[id]->Pause();
	}

}

void KdAudioManager::ReStart(BGM_ID id)
{

	if (m_bgmList[id]->IsPause() == true && (!m_bgmList[id]))
	{
		m_bgmList[id]->Resume();
	}

}

void KdAudioManager::Update()
{
	if (m_audioEng == nullptr)return;

	if (!m_audioEng->Update()) {
		// No audio device is active
		if (m_audioEng->IsCriticalError())
		{

		}
	}

	// 再生リスト処理
	{
		auto it = m_playList.begin();
		while(it != m_playList.end())
		{
			// 再生中でないときは、リストから削除(どこからも参照されていなければ解放される)
			if(!(*it).second->IsPlay())
			{
				it = m_playList.erase(it);
				continue;
			}

			++it;
		}
	}

}
