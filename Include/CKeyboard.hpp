//------------------------------------------------------------------------------
/// @file
/// @brief		Key inputs manegement function
/// @author		nitorionedan
///
/// @copyright  Copyright 2016 KITIC

//------------------------------------------------------------------------------

#ifndef DEF_KEYBOARD_HPP
#define DEF_KEYBOARD_HPP


// キーの入力状態を更新する
void Keyboard_Update();

// 引数のキーコードのキーの入力状態を返す
int Keyboard_Get(int KeyCode);


#endif
// EOF