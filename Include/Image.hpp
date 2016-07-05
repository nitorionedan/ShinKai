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
	@brief					Near Raster Scrole
	@param[in]	X, Y		Position
	@param[in]	Cycle		Period
	@param[in]	Shake		Amplitude
	@param[in]	Key			Key Word
	@param[in]	isVertical	Does Wave direct vertical or horizontal?
	@return					Successe >> 1, Failed >> -1
	*/
	int DrawRasterScroll(const int &X, const int &Y, double Cycle, double Shake, const std::string &Key, bool isVertical = true);

	int GetSize(std::string key, int* width, int* height);

private:
	int GetHandle(std::string key);

	std::vector<std::string> key;	// key name
	std::vector<int> gh;			// graphic handle
	int count;						// loaded file num
};


#endif // !DEF_IMAGE_HPP
