/******************************************************************************/
/*!
\file   WEInput.h
\author Matt Casanova
\par    Simple 2D Game Engine
\date   2012/11/26
Prototypes for input funtions
*/
/******************************************************************************/
#ifndef WE_INPUT_H
#define WE_INPUT_H
//Forward Declarations
struct WEVec2;
//! The WarpEngine interal set of keys/buttons that can be pressed.
enum WEKeyCode
{
  WE_0,
  WE_1,
  WE_2,
  WE_3,
  WE_4,
  WE_5,
  WE_6,
  WE_7,
  WE_8,
  WE_9,
  WE_A,
  WE_B,
  WE_C,
  WE_D,
  WE_E,
  WE_F,
  WE_G,
  WE_H,
  WE_I,
  WE_J,
  WE_K,
  WE_L,
  WE_M,
  WE_N,
  WE_O,
  WE_P,
  WE_Q,
  WE_R,
  WE_S,
  WE_T,
  WE_U,
  WE_V,
  WE_W,
  WE_X,
  WE_Y,
  WE_Z,
  WE_F1,
  WE_F2,
  WE_F3,
  WE_F4,
  WE_F5,
  WE_F6,
  WE_F7,
  WE_F8,
  WE_F9,
  WE_F10,
  WE_F11,
  WE_F12
};
namespace WEInput
{
 /*Check if a specific key is being held down*/
bool  IsPressed(WEKeyCode key);
/*Check if a specific key was first touched this frame*/
bool  IsTriggered(WEKeyCode key);
/*Check if key is touched this frame and last frame*/
bool  IsRepeating(WEKeyCode key);
/*Check if any key is being held down*/
bool  IsAnyPressed(void);
/*Check if any key was first touched this frame*/
bool  IsAnyTriggered(void);
bool  IsAnyRepeating(void);
void  GetMouse(WEVec2& pMouse);
void  GetLeftThumb(WEVec2& vec);
void  GetRightThumb(WEVec2& vec);
float GetLeftTrigger(void);
float GetRightTrigger(void);
bool  GamePadIsConnected(void);
}
#endif 