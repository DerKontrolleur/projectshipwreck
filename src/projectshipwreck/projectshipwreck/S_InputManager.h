#pragma once

/////////////////////////////////////////////////////////////////////////////////////////////
// This class handles all input events like mouse or keyboard input. It is a singleton...  //
/////////////////////////////////////////////////////////////////////////////////////////////

#include "S_ResourceManager.h"
#include "Vector2D.h"
using namespace ProjectShipwreckStructs;

namespace ProjectShipwreckHighClass
{
	class S_InputManager
	{
	private:
		bool RightMouseButton; // Guess what: it saves the right mouse button state!
		bool LeftMouseButton;
		bool MouseWheelUp;
		bool MouseWheelDown;

		bool Up;
		bool Down;
		bool Left;
		bool Right;

		Vector2D<int> MousePosition;


		S_InputManager(): RightMouseButton(false), LeftMouseButton(false), MouseWheelUp(false), MouseWheelDown(false), Up(false), Down(false), Left(false), Right(false), MousePosition(NULL) {}
		S_InputManager(const S_InputManager&) {}
		S_InputManager& operator=(const S_InputManager&) {}

		~S_InputManager() {}

	public:
		static S_InputManager* get_Instance()
		{
			static S_InputManager Instance;
			return &Instance;
		}

		bool GetRightMousePressed() const {return this->RightMouseButton;}
		bool GetLeftMousePressed() const {return this->LeftMouseButton;}
		bool GetMouseWheelDown() const {return this->MouseWheelDown;}
		bool GetMouseWheelUp() const {return this->MouseWheelUp;}

		const Vector2D<int>& GetMousePosition() const {return this->MousePosition;}

		void SetRightMousePressed(bool bRightMouse) {this->RightMouseButton = bRightMouse;}
		void SetLeftMousePressed(bool bLeftMouse) {this->LeftMouseButton = bLeftMouse;}
		void SetMouseWheelDown(bool bWheelDown) {this->MouseWheelDown = bWheelDown;}
		void SetMouseWheelUp(bool bWheelUp) {this->MouseWheelUp = bWheelUp;}

		void SetMousePosition(int mousePositionX, int mousePositionY) {this->MousePosition.Set(mousePositionX, mousePositionY);}


		void SetUp(bool up) {this->Up = up;}
		void SetDown(bool down) {this->Down = down;}
		void SetLeft(bool left) {this->Left = left;}
		void SetRight(bool right) {this->Right = right;}

		bool GetUp() const {return this->Up;}
		bool GetDown() const {return this->Down;}
		bool GetLeft() const {return this->Left;}
		bool GetRight() const {return this->Right;}

		void InputEvents(SDL_Event& Event);
	};
}