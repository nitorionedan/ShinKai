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
static bool isFullSc = false;
static bool isPlay = true;


// @brief	60fps��ۂ����鏈��
static void FPSMng();

// @brief	�E�B���h�E�����ݒ�
static void Initialize();

// @brief	���ł��󂯕t����ݒ�
static void DynamicConfig();


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Initialize();
	std::unique_ptr<SceneMng>	sceneMng(new SceneMng);

	// �Q�[��--------------------------------------------------------------------------------------
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && isPlay)
	{
		FPSMng();
		Keyboard_Update();										// �L�[���͏󋵍X�V
		DynamicConfig();
		sceneMng->Update();
		sceneMng->Draw();
	}
	DxLib_End();												// �c�w���C�u�����g�p�̏I������
	return 0;
}


void FPSMng()
{
	while (GetNowCount() - FrameStartTime < FPS_60) {}		// 1/60 �b�܂ő҂�
	FrameStartTime = GetNowCount();							// ���݂̃J�E���g��ۑ�
}


void Initialize()
{
	SetGraphMode(850, 650, 32), ChangeWindowMode(TRUE), DxLib_Init();							// �E�B���h�E�����ݒ�(VGA),DxLib�N��
	SetDrawScreen(DX_SCREEN_BACK);																// ����ʏ���
	SetMainWindowText("���K");																	// �^�C�g����ݒ�
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);											// ��ʃ��[�h�ύX��A�f�ރ����������Z�b�g���Ȃ�
	SetWaitVSyncFlag(FALSE);																	// ���������M����҂��Ȃ�
	FrameStartTime = GetNowCount();																// �J�n���Ԃ�ݒ�
}


void DynamicConfig()
{
	// ���C�����[�v�𔲂���
	if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1)	isPlay = false;
}
// EOF