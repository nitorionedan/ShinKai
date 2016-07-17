#pragma once
#include "Vector2D.hpp"


class Creature
{
public:
	virtual ~Creature() {}
	virtual void Initialize() {}		//�����������͎������Ȃ��Ă�����
	virtual void Finalize() {}   	//�I�������͎������Ȃ��Ă�����
	virtual void Update() = 0;	//�X�V�����͕K���p����Ŏ�������
	virtual void Draw() = 0;	//�`�揈���͕K���p����Ŏ�������
	virtual bool IsExist() = 0;
	virtual bool IsDead() = 0;
	virtual bool IsOB() = 0;
	virtual Vector2D& GetPos() = 0;

protected:
	Vector2D pos;
	bool isExist, isOB, isDead;
	bool isTurn;
};

// EOF