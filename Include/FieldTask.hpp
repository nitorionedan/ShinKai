#pragma once


class FieldTask
{
public:
	virtual ~FieldTask(){}
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual bool HasGround() = 0;
	virtual bool HasSky() = 0;
	virtual bool HasLWall() = 0;
	virtual bool HasRWall() = 0;

protected:
	bool hasGround;
	bool hasSky;
	bool hasLWall;
	bool hasRWall;
};