/*
@file		Image.hpp
@brief		If you used this module, you no need DeleteGraph function!
@author		nitorionedan
@warning	This module uses DxLib functions.
*/


#ifndef DEF_IMAGE_HPP
#define DEF_IMAGE_HPP


#include "DxLib.h"
#include "Graphics2D.hpp"

#include <string>
#include <vector>

// TODO : Be implement.
/*
enum class eColor
{
	Red		= GetColor(255, 0, 0),
	Green	= GetColor(0, 255, 0),
	Blue	= GetColor(0, 0, 255),
};
*/


class Image
{
public:
	Image();
	~Image();

	static void ChengeIsUpdate();

<<<<<<< HEAD
	int Draw(const int& X, const int& Y, std::string key, int TransFlag = 0);
	int DrawRota(const int& X, const int& Y, const double& ExRate, const double& Angle, std::string key, int TransFlag = 0, int TurnFlag = 0);
	int DrawRect(const int& DestX, const int& DestY,
		const int& SrcX, const int& SrcY, const int& Width, const int& Height,
		std::string key, const int& TransFlag = 0, const int& TurnFlag = 0);
<<<<<<< HEAD

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
=======
=======
	int Load(		const TCHAR* FNAME, std::string key);
	void List();
	int Draw(		const int& X,		const int& Y,	  const std::string& key, int TransFlag = 0 );
	int DrawRota(	const int& X,		const int& Y,     const double& ExRate,	  const double& Angle, std::string key,	 int TransFlag = 0,	int TurnFlag = 0 );
	int DrawRect(	const int& DestX,	const int& DestY, const int& SrcX,		  const int& SrcY,	   const int& Width, const int& Height,	std::string key, const int& TransFlag = 0, const int& TurnFlag = 0 );
>>>>>>> dev
	
	// @brief					Near raster scroll
	// @param[in]	X, Y		Drawing position
	// @param[in]	Cycle		Wave period
	// @param[in]	Shake		Wave amplitude
	// @param[in]	Speed		Wave speed
	// @param[in]	Key			The key you yourself set
	// @param[in]	isVertical	Does wave facing vertical or  horizontal?
	// @return					Successful:1	Error:-1
	int DrawRasterScroll(const int& X, const int& Y, const double& Cycle, const double& Shake, const double& Speed, const std::string &Key, const bool& isVertical = true);
//	int DrawWrapScroll(const )
>>>>>>> dev

	int GetSize(std::string key, int* width, int* height);

private:
	int GetHandle(std::string key);

<<<<<<< HEAD
	std::vector<std::string> key;	// key name
	std::vector<int> gh;			// graphic handle
	int count;						// loaded file num
=======
	static bool is_sUpdate;
	std::vector<std::string> key;	// Key name
	std::vector<int> gh;			// Graphics handle
	int count;
>>>>>>> dev
};


#endif // !DEF_IMAGE_HPP
