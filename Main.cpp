//------------------------------------------------------------------------------
/// @file
/// @brief    メイン
/// @author   矢伝翔平
///
/// @copyright  Copyright 2016 矢伝翔平

//------------------------------------------------------------------------------

#include "DxLib.h"

#include "Keyboard.hpp"
#include "SceneMng.hpp"

#include <memory>


static int FrameStartTime;
static int FPS_60 = 1000 / 60;
static bool isFullSc = true;
static bool isPlay = true;


// @brief	60fpsを保たせる処理
static void FPSMng();

// @brief	ウィンドウ初期設定
static void Initialize();

// @brief	いつでも受け付ける設定
static void DynamicConfig();


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Initialize();
	std::unique_ptr<SceneMng>	sceneMng(new SceneMng);

	// ゲーム--------------------------------------------------------------------------------------
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
	SetWaitVSyncFlag(FALSE);																	// 垂直同期信号を待たない
	FrameStartTime = GetNowCount();																// 開始時間を設定
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