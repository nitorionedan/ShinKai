#pragma once

#include "Image.hpp"
#include "Sound.hpp"
#include "FieldTask.hpp"
#include "Field.hpp"
#include <memory>


class Stage
{
	class SoundLogo
	{
	public:
		SoundLogo();
		~SoundLogo() {}
		void Update();
		void Draw();
	private:
		std::unique_ptr<Image> img;
		int counter;
		int c_alpha;
	};

public:
	Stage();
	~Stage();
	void Initialize();
	void Update();
	void Draw();

	static const int L_BOUNDARY = 32;
	static const int R_BOUNDARY = 287;

private:
	std::unique_ptr<Image> img;
	std::unique_ptr<Sound> sound;
	std::unique_ptr<SoundLogo> logo;
	std::shared_ptr<FieldTask> field;
	double c_alpha;
};


template<typename TYPE, std::size_t SIZE>
std::size_t array_length(const TYPE(&)[SIZE])
{
	return SIZE;
}

// EOF