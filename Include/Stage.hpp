#pragma once

#include "Image.hpp"
#include "Sound.hpp"
#include <memory>


class Stage
{
public:
	Stage();
	~Stage();
	void Initialize();
	void Update();
	void Draw();

private:

	std::unique_ptr<Image> img;
	std::unique_ptr<Sound> sound;
	double c_shake;
	double shake;

	int tmp[14];
};


template
<
	typename TYPE,
	std::size_t SIZE
>
std::size_t array_length(const TYPE(&)[SIZE])
{
	return SIZE;
}