#include "Sound.hpp"


Sound::Sound() : count(0){}


Sound::~Sound()
{
	if (count != 0){
		for (auto& sh : this->sh)	DeleteSoundMem(sh);
	}
}


int Sound::Load(const TCHAR * FNAME, std::string key, int BufferNum, int UnionHandle)
{
	this->key.push_back(key);

	sh.push_back(LoadSoundMem(FNAME, BufferNum, UnionHandle));

	count++;

	return 0;
}


int Sound::PlayMem(std::string key, int PlayType, int TopPositionFlag)
{
	if (count == 0)	return -1;

	const int& Hdl = GetHandle(key);

	if (Hdl == -1)	return Hdl;
	return PlaySoundMem(Hdl, PlayType, TopPositionFlag);
}


void Sound::List()
{
	if (count == 0)	return;

	int c = 0;

	printfDx("Sound�L�[���X�g�F\n");

	for(auto key : this->key)
	{
		std::string list = key + "\n";
		printfDx(list.c_str());
		c++;
	}

	printfDx("���v%d�t�@�C��", c);
}


int Sound::GetHandle(std::string key)
{
	for (int i = 0; i != this->key.size(); ++i)
	{
		if (this->key[i] != key)	continue;

		return this->sh[i];
	}

	std::string warning = key + "�Ƃ����L�[����������܂���B";

	MessageBox(NULL, warning.c_str(), "NOT FOUND", MB_OK);

	return -1;
}

// EOF