#pragma once

#include "Image.hpp"
#include "Sound.hpp"
#include "FieldTask.hpp"
#include "Field.hpp"
#include <memory>


enum class eChangeStage
{
	Up,		// go to up
	Down,	// ...
	Left,
	Right,

	First,	// start point
};


class Stage
{
	class SoundLogo
	{
	public:
		SoundLogo();
		~SoundLogo(){}
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
	void ChangeField(eChangeStage nextStage);
	const std::unique_ptr<FieldTask>& GetField() {
		return field;
	}

private:
	std::unique_ptr<Image> img;
	std::unique_ptr<Sound> sound;
	std::unique_ptr<SoundLogo> logo;
	std::unique_ptr<FieldTask> field;
	eChangeStage nextStage;
	double c_alpha;
};


// get array length
template<typename TYPE, std::size_t SIZE>
std::size_t array_length(const TYPE(&)[SIZE])
{
	return SIZE;
}

// EOF