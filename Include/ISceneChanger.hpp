//------------------------------------------------------------------------------
/// @file
/// @brief    ISceneChanger�N���X
/// @author   ��`�ĕ�
///
/// @copyright  Copyright 2016 ��`�ĕ�

//------------------------------------------------------------------------------

#ifndef DEF_ISCENEMNG_HPP
#define DEF_ISCENEMNG_HPP


typedef enum
{
	eScene_Menu,	// ���j���[���
	eScene_Game,	// �Q�[�����
	eScene_GameClear,

	eScene_None,	// ����
} eScene;


//�V�[����ύX���邽�߂̃C���^�[�t�F�C�X�N���X
class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(eScene NextScene) = 0; //�w��V�[���ɕύX����
};


#endif
// EOF