//------------------------------------------------------------------------------
/// @file
/// @brief    ���C��
/// @author   ��`�ĕ�
///
/// @copyright  Copyright 2016 ��`�ĕ�

//------------------------------------------------------------------------------

#include "DxLib.h"

#include "Keyboard.hpp"
#include "SceneMng.hpp"

#include <memory>


static int FrameStartTime;
static int FPS_60 = 1000 / 60;
static bool isFullSc = true;
static bool isPlay = true;


// @brief	60fps��ۂ����鏈��
static void FPSMng();

// @brief	�E�B���h�E�����ݒ�
static void Initialize();

// @brief	���ł��󂯕t����ݒ�
static void DynamicConfig();


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Initialize();
	std::unique_ptr<SceneMng>	sceneMng(new SceneMng);

	// �Q�[��--------------------------------------------------------------------------------------
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && isPlay)
	{
		FPSMng();
		Keyboard_Update();
		DynamicConfig();
		sceneMng->Update();
		sceneMng->Draw();
	}
	DxLib_End();
	return 0;
}


void FPSMng()
{
	while (GetNowCount() - FrameStartTime < FPS_60) {}		// wait for 1/60sec
	FrameStartTime = GetNowCount();							// save now count
}


void Initialize()
{
	SetGraphMode(320, 240, 32), ChangeWindowMode(isFullSc), DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	SetMainWindowText("ShinKai");
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
	SetWaitVSyncFlag(FALSE);																	// ���������M����҂��Ȃ�
	FrameStartTime = GetNowCount();																// �J�n���Ԃ�ݒ�
	SetMouseDispFlag(TRUE);
}


void DynamicConfig()
{
	// exit main loop
	if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1)	isPlay = false;

	// Change window mode
	if (Keyboard_Get(KEY_INPUT_F5) == 1)
	{
		isFullSc = !isFullSc;
		ChangeWindowMode(isFullSc);
	}
}
// EOF