#pragma once
#include "Vector2D.hpp"


class Creature
{
public:
	virtual ~Creature() {}
	virtual void Initialize() {}		//初期化処理は実装しなくてもいい
	virtual void Finalize() {}   	//終了処理は実装しなくてもいい
	virtual void Update() = 0;	//更新処理は必ず継承先で実装する
	virtual void Draw() = 0;	//描画処理は必ず継承先で実装する
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