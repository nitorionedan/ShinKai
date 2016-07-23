#ifndef DEF_SOUND_HPP
#define DEF_SOUND_HPP

#include "DxLib.h"
#include <string>
#include <vector>


class Sound
{
public:
	Sound();
	~Sound();

	int Load(const TCHAR* FNAME, std::string key, int BufferNum = 3, int UnionHandle = -1);

	int PlayMem(std::string key, int PlayType, int TopPositionFlag = 1);

	void List();

private:
	int GetHandle(std::string key);

	std::vector<std::string> key;	// �L�[�l�[��
	std::vector<int> sh;			// �T�E���h�n���h��
	int count;
};

#endif

// EOF