#pragma once

#include "Image.hpp"
#include <memory>


class Stage
{
public:
	Stage();
	~Stage();
	void Initialzie();
	void Update();
	void Draw();

private:
	std::unique_ptr<Image> img;
};