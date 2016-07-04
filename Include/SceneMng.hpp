//------------------------------------------------------------------------------
/// @file
/// @brief    SceneMng�N���X
/// @author   ��`�ĕ�
///
/// @copyright  Copyright 2016 ��`�ĕ�

//------------------------------------------------------------------------------

#ifndef DEF_SCENEMNG_HPP
#define DEF_SCENEMNG_HPP

#include "ISceneChanger.hpp"
#include "BaseScene.hpp"


class SceneMng : public ISceneChanger, Task
{
public:
	SceneMng();
	~SceneMng();
	virtual void Update() override; // �X�V
	virtual void Draw() override; // �`��

								  // ���� nextScene �ɃV�[����ύX����
	void ChangeScene(eScene NextScene) override;

private:
	BaseScene* mScene;     // �V�[���Ǘ��ϐ� (���C�ӂ̃^�C�~���O�Ń������̊m�ہA��������܂�)
	eScene     mNextScene; // ���̃V�[���Ǘ��ϐ�
};

#endif