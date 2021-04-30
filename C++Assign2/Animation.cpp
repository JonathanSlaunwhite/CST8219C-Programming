/*****************************************************************************************************************************
Filename					 Animation.cpp
Version						 1
Author/Student number		 Jonathan slaunwhite #040939090
class:						 C+++ CST8219
Lab section					 300
Assignment Number			 2
Assignment Name				 Lab_Component_2
DueDate						 2020-03-15
Submission Date				 2020-003-12
prof name					 Surbhi Bahri
Purpose						 This class will assist in the creation of animation frame name, editing frame
							 deleting frame and reporting frame names
*****************************************************************************************************************************/



#include <forward_list>

#include <crtdbg.h> 
#include <iostream> 
#include <string>


using namespace std;

#include <vector>

#include <forward_list>

#include "Frame.h"

#include "Animation.h"

#include "AnimationManager.h"


/*****************************************************************************************************************************
Fuction name:			istream
Purpose:				Inset a frame name
In Parameters			istream, Animaiton
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
istream& operator>>(std::istream& istream, Animation& animation) {


	cout << "Insert a Frame in the Animation" << endl;//display information
	cout << "Please enter the frameName: ";

	char name[100];//char to match arguments in frame class will hold 100 characters
	cin >> name;

	cout << "\nPlease enter the Frame duration: ";//get duration varible
	double time;
	cin >> time;

	animation.frames.push_front(Frame(name, time));//add frame to the list

	cout << "Frame "<<name<<" added at the front of frames"<<endl;//display that the frame has been added


	return istream;
}

/*****************************************************************************************************************************
Fuction name:			ostream
Purpose:				Report animation and frames
In Parameters			ostream, Animaiton
Out parameters			ostream
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
ostream& operator<<(std::ostream& ostream, Animation& animation) {

	ostream << "	Animation name is " << animation.animationName << endl;//display animation name
	ostream << "	Report the animation" << endl;//report animation

	if (animation.frames.empty()==false) {//if not animation frames not empty display


		forward_list<Frame>::iterator i;//forward list 

		i = animation.frames.begin();//set i to frames.begin

		int counter = 0;
		while (i != animation.frames.end()) {//loop until end of frames is reached

			ostream << "	Frame " << counter << ": " << *i << endl;//display contents 

			counter++;//itterate varibles
			i++;

		}


	}
	else {//there are no frames in animation

		ostream << "	No Frame in the Animation";
	}
	return ostream;
}


/*****************************************************************************************************************************
Fuction name:			EditFrame
Purpose:				Edit a frame 
In Parameters			None
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
void Animation::EditFrame() {

	if (!frames.empty()) {//if the frames are not empty proceed

		int findLength = distance(frames.begin(), frames.end());


		int number = 0;
		do {

			cout << "There are " << findLength << " Frame(s) in the list. Please specify the index (<=" << findLength - 1 << ") to edit at : ";
			cin >> number;
		} while (number>findLength-1||number<0);//ensure number is not greater then index or less then 0


		int counter = 0;
		for (Frame& frame : frames) {

			if (number==counter) {//go through frames until desired frame is reached

				cout << "The name and duration of this Frame are frameName = "<<frame<<". What do you wish to replace them with?"<<endl;

				double time;
				char name[100];

				cin >> name;//get input of data
				cin >> time;

				Frame t = Frame(name, time);//input the name and time
				frame = t;//set frame equal to what values were changed by user

				cout << "Frame #"<<number<<" edit completed"<<endl;//display contents finished

				break;
			}
		
			counter++;

		}
		
	}
	else {
		cout << "There are no frames in the animaiton"<<endl;
	}

}

/*****************************************************************************************************************************
Fuction name:			DeleteFrame
Purpose:				Delete a frame
In Parameters			None
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
void Animation::DeleteFrame() {

	if (!frames.empty()) {//if frames are not empty
		
		frames.pop_front();//delete from front
		cout << "First Frame Deleted" << endl;
	}
	else {//user trying to delete from no frames 

		cout << "There are no Frames in the Animation" << endl;

	}

}