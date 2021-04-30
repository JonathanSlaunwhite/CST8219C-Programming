/*****************************************************************************************************************************
Filename					 Frame.cpp
Version						 1
Author/Student number		 Jonathan slaunwhite #040939090
class:						 C+++ CST8219
Lab section					 300
Assignment Number			 2
Assignment Name				 Lab_Component_2
DueDate						 2020-03-15
Submission Date				 2020-003-12
prof name					 Surbhi Bahri
Purpose						 This class will assist in the creation of naming the frames, displaying the frames
							 deleting frames and deleting frames
*****************************************************************************************************************************/


#define _CRT_SECURE_NO_WARNINGS

#include <crtdbg.h> 
#include <iostream> 

#include <string>
#include <vector>
#include <forward_list>

#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"

using namespace std;



/*****************************************************************************************************************************
Fuction name:			Frame
Purpose:				Get name and duration
In Parameters			name, duration
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
Frame::Frame(char* nameTemp, double time) {

	frameName = new char[strlen(nameTemp) + 1];//allocate memory for frameName length of name plus 1
	strcpy(frameName, nameTemp);//copy contents of name to frameName
	duration = time;//set duration to this duration
}




/*****************************************************************************************************************************
Fuction name:			Frame
Purpose:				copy contents
In Parameters			Frame
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
Frame::Frame(const Frame& frame) {

	frameName = new char[strlen(frame.frameName) + 1];//allocate memeory from framename plus 1
	strcpy(frameName, frame.frameName);//copy contents to frameName
	duration = frame.duration;//set duration from frame duration

}




/*****************************************************************************************************************************
Fuction name:			Frame
Purpose:				Get duration
In Parameters			Frame
Out parameters			*this
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
Frame& Frame::operator=(const Frame& f) {
	
	delete frameName;//delete framename

	frameName = new char[strlen(f.frameName) + 1];//set framename allocate memory of frameName +1
	strcpy(frameName, f.frameName);//copy contents of frameName from f
	duration = f.duration;//set duration from f.duration

	return *this;//return object by refrence
}


/*****************************************************************************************************************************
Fuction name:			ostream
Purpose:				Display frame
In Parameters			ostream, frame
Out parameters			ostream
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
ostream& operator << (std::ostream& ostream, Frame& frame) {

	ostream << "frameName = " << frame.frameName;//display contents of framename
	ostream <<"; Duration = " << frame.duration;//display  contents of duration

	return ostream;//return the ostream
}

/*****************************************************************************************************************************
Fuction name:			~Frame
Purpose:				delete frame
In Parameters			none
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
Frame::~Frame() {
	delete frameName;//delete the frameName
}
