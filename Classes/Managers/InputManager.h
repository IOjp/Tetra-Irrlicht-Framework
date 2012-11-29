/*
	-----------------------------------------
	InputManager.h
	-----------------------------------------
*/

#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#include <irrlicht.h>

// Input Manager Class
class InputManager : public irr::IEventReceiver
{
private:

	// Keys
	bool _keyTrigger[irr::KEY_KEY_CODES_COUNT];

	// Key Timers
	float _keyTimer[irr::KEY_KEY_CODES_COUNT];

	// Key Delay
	float _delay;

	// Key Scroll Delay
    float _delayScroll;

	// Timer Storage
	float _storedTime;

	// Input String
	irr::core::stringw _inputString;
	bool _isInputString;

public:

	// Keys
	bool _keys[irr::KEY_KEY_CODES_COUNT];

	// Mouse
	bool _mMouseEvent;
	irr::EMOUSE_INPUT_EVENT _lMouseEvent;
	irr::EMOUSE_INPUT_EVENT _rMouseEvent;

	// Input String
	irr::core::stringw inputString(){return _inputString;}
	void setInputString(irr::core::stringw val){_inputString = val;}
	void resetString(){_inputString="";}
	void toggleInputString()
	{
		if(_isInputString)
			_isInputString = false;
		else 
			_isInputString = true;

		_inputString="";
	}

	// Constructor
	InputManager()
	{
		// Set Delays
		_delay = 100.0f;
		_delayScroll = 300.0f;
		_storedTime = 0.0f;
		_isInputString = false;

		// Loop Thro Key Feilds
		for(int i=0; i<irr::KEY_KEY_CODES_COUNT; i++) 
		{
			// Set Key Details To Default Values
			_keys[i] = false;
			_keyTrigger[i] = false;
			_keyTimer[i] = _delay;
		}
	}

	// Deconstructor
	~InputManager(){}

	// Check Key
	bool CheckKey(irr::EKEY_CODE keyCode, float timer)
	{
		// Check if Pressed
		if(_keys[keyCode])	
		{
			// Step Timer
			_keyTimer[keyCode] += timer - _storedTime;
			_storedTime = timer;

			// Check Button Seconds Elapsed
            if (_keyTimer[keyCode] > _delay)
			{
				// Check Trigger
				if (!_keyTrigger[keyCode])
                {
					// Set Timer
					_keyTimer[keyCode] = -_delayScroll;

					// Set Trigger
					_keyTrigger[keyCode] = true;
				}
				else
				{
					// Reset Timer
					_keyTimer[keyCode] = 0.0f;
				}

				// Reset Key
				_keys[keyCode] = false;

				// Return True
				return true;
			}
		}
		else if(_keyTrigger[keyCode])
        {
			// Update Timer
			_keyTimer[keyCode] = _delay;

			// Update Trigger
			_keyTrigger[keyCode] = false;
		}

		// Return False
		return false;
	}

	// On Event 
	bool OnEvent(const irr::SEvent& event)
	{
		// Mouse Movement
	   	if(event.MouseInput.Event == irr::EMIE_MOUSE_MOVED) 
			_mMouseEvent = true;	 
		else
			_mMouseEvent = false;	

	    // Left Mouse
	   	if(event.MouseInput.Event == irr::EMIE_LMOUSE_PRESSED_DOWN) 
			_lMouseEvent = irr::EMIE_LMOUSE_PRESSED_DOWN;	
		else if(event.MouseInput.Event == irr::EMIE_LMOUSE_LEFT_UP )
			_lMouseEvent = irr::EMIE_LMOUSE_LEFT_UP;

		// Right Mouse
	   	if(event.MouseInput.Event == irr::EMIE_RMOUSE_PRESSED_DOWN) 
			_rMouseEvent = irr::EMIE_RMOUSE_PRESSED_DOWN;	
		else if(event.MouseInput.Event == irr::EMIE_RMOUSE_LEFT_UP )
			_rMouseEvent = irr::EMIE_RMOUSE_LEFT_UP;	
		
		// Key Event
		if(event.EventType == irr::EET_KEY_INPUT_EVENT)
		{
			_keys[event.KeyInput.Key] = event.KeyInput.PressedDown;

			if(_inputString.size() < 80 && 
			   _isInputString &&
			   _keys[event.KeyInput.Key] &&
			   event.KeyInput.Key != irr::KEY_RETURN &&	// Note: Need to implement a list
			   event.KeyInput.Key != irr::KEY_DOWN &&	// of allowed keys to avoid unwanted
			   event.KeyInput.Key != irr::KEY_UP &&		// spaces in our input.
			   event.KeyInput.Key != irr::KEY_LEFT &&
			   event.KeyInput.Key != irr::KEY_RIGHT &&
			   event.KeyInput.Key != irr::KEY_CONTROL &&
			   event.KeyInput.Key != irr::KEY_LSHIFT &&
			   event.KeyInput.Key != irr::KEY_RSHIFT &&
			   event.KeyInput.Key != irr::KEY_BACK)
				_inputString.append(event.KeyInput.Char);
			else if(_inputString.size() > 0 && 
			   _isInputString &&
			   _keys[event.KeyInput.Key] &&
			   event.KeyInput.Key == irr::KEY_BACK)
				_inputString = _inputString.subString(0,_inputString.size()-1);
		}

		// Return
		return false;
	}
};

#endif
