#ifndef DEF_IMAGE_HPP
#define DEF_IMAGE_HPP


#include "DxLib.h"
#include "Graphics2D.hpp"

#include <string>
#include <vector>


class Image
{
public:
	Image();
	~Image();

	int Load(const TCHAR* FNAME, std::string key);
	void List();

	int Draw(const int& X, const int& Y, std::string key, int TransFlag = 0);
	int DrawRota(const int& X, const int& Y, const double& ExRate, const double& Angle, std::string key, int TransFlag = 0, int TurnFlag = 0);
	int DrawRect(const int& DestX, const int& DestY,
		const int& SrcX, const int& SrcY, const int& Width, const int& Height,
		std::string key, const int& TransFlag = 0, const int& TurnFlag = 0);
	
	/*
	@brief					Near raster scroll
	@param[in]	X, Y		Drawing position
	@param[in]	Cycle		Wave period
	@param[in]	Shake		Wave amplitude
	@param[in]	Speed		Wave speed
	@param[in]	Key			The key you yourself set
	@param[in]	isVertical	Does wave facing vertical or  horizontal?
	@return					Successful:1	Error:-1
	*/
	int DrawRasterScroll(const int& X, const int& Y, const double& Cycle, const double& Shake, const double& Speed, const std::string &Key, const bool& isVertical = true);
//	int DrawWrapScroll(const )

	int GetSize(std::string key, int* width, int* height);

private:
	int GetHandle(std::string key);

	std::vector<std::string> key;	// キーネーム
	std::vector<int> gh;			// グラフィックハンドル
	int count;
};


#endif // !DEF_IMAGE_HPP
