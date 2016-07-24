#pragma once


class FieldTask
{
	struct FieldStatus
	{
		bool hasGround;
		bool hasSky;
		bool hasLWall;
		bool hasRWall;
	};

public:
	virtual ~FieldTask(){}
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual bool HasGround() const = 0;
	virtual bool HasSky() const = 0;
	virtual bool HasLWall() const = 0;
	virtual bool HasRWall() const = 0;

protected:
	FieldStatus fieldStatus;
};