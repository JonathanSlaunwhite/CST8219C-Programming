/*****************************************************************************************************************************
Filename					 Animation.cpp
Version						 1
Author/Student number		 Jonathan slaunwhite #040939090
class:						 C+++ CST8219
Lab section					 300
Assignment Number			 1
Assignment Name				 Ass1
DueDate						 2020-02-09
Submission Date				 2020-02-09
prof name					 Surbhi Bahri
Purpose						 This class will allow user to insert animation name, insert frames, edit any frame
							 delete last frame in list and delete all dynamically allocated memory when program ends
*****************************************************************************************************************************/






#include "Frame.h"
#include "Animation.h"
#include <iostream>
#pragma warning(disable:4996)




using namespace std;


/*****************************************************************************************************************************
Fuction name:			Animation
Purpose:				Get and set animation name
In Parameters			none
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
Animation::Animation() {

	frames = NULL;
	animationName = NULL;

	cout << "Please enter animation name ";

	char* temp = new char[255];//temp varible to hold input

	cin >> temp;

	int length = strlen(temp);//get the length of the temp varible

	animationName = new char[length + 1];//allocate proper memory for animationname

	strcpy(animationName, temp);//copy contents from temp varible to animationname

	delete[] temp;//delete temp varible
	temp = NULL;//make it null

}

/*****************************************************************************************************************************
Fuction name:			InsertFrame
Purpose:				To insert a frame name into the animation
In Parameters			none
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
void Animation::InsertFrame() {


	cout << "Insert a frame in the Animation" << endl;
	cout << "Please enter the Frame frameName : ";

	Frame* frameg = new Frame;

	char* temp = new char[255];//temp varible to hold frame name

	cin >> temp;

	int length1 = strlen(temp);//get length of temp varible

	frameg->GetFrameName() = new char[length1 + 1];//allocate memory for framename 

	strcpy(frameg->GetFrameName(), temp);//compy contents from temp varible to frame name

	delete[] temp;//delete temp varible
	temp = NULL;//make it point to null



	frameg->GetpNext() = frames;
	frames = frameg;


}

/*****************************************************************************************************************************
Fuction name:			EditFrame
Purpose:				To edit a specified frame by user and change framename within the animation
In Parameters			none
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
void Animation::EditFrame() {


	Frame* bob = frames;
	int counter = 0;

	while (bob) {/*count how many frames there are in the animation*/

		bob = bob->GetpNext();
		counter++;
	}
	/*display infomation*/
	cout << "There are " << counter << " Frame(s) in the list. Please specify the index (<=" << counter - 1 << ") to edit at: ";

	int choice = 0;

	cin >> choice;/*input frame to edit*/

	while (choice > counter - 1 || choice < 0) {/*if frame edit number is not valid loop until valid number is put in*/
		cout << "Please enter a valid range to edit from 0 to " << counter - 1 << " ";
		cin >> choice;
	}


	Frame* current = frames;
	while (choice != 0) {//itterate through frames untill desired frame is reached
		current = current->GetpNext();
		--choice;
	}
	cout << "The name of this Frame is " << current->GetFrameName() << ". What do you wish to replace it with? ";



	delete current->GetFrameName();//delete current frame name will get edited over anyways
	current->GetFrameName() = NULL;//make it point to null


	char* temp2 = new char[255];//temp varible to hold large data if needed

	cin >> temp2;

	int length3 = strlen(temp2);//inf length of temp varible

	current->GetFrameName() = new char[length3 + 1];//allocate memory accordlingy

	strcpy(current->GetFrameName(), temp2);//compy contents from temp varible to frame name

	delete[] temp2;//delete temp varible 
	temp2 = NULL;



}

/*****************************************************************************************************************************
Fuction name:			DeleteFrame
Purpose:				To delete the last frame in the animation and then free(delete) the memory in the program
In Parameters			none
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
void Animation::DeleteFrame() {

	Frame* bob = frames;

	if (bob == NULL) {//do not delete from no frames
		cout << "Can not delete from no frames" << endl;
	}
	else {

		if (bob->GetpNext() == NULL) {//do not delete from last frame either

			cout << "Do not delete from last frame" << endl;

		}

		else {

			while (bob->GetpNext()->GetpNext() != NULL) {//itterate to second last frame

				bob = bob->GetpNext();
			}

			delete(bob->GetpNext()->GetFrameName());//delete frame name
			delete(bob->GetpNext());//delete its cooresponding pointer
			bob->GetpNext() = NULL;//set next pointer to null

		}
	}
}

/*****************************************************************************************************************************
Fuction name:			ReportAnimation
Purpose:				To display the animation name and then each frame name within the animation
In Parameters			none
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
void Animation::ReportAnimation() {

	cout << "Animaiton name is " << animationName << endl;

	Frame* bob = frames;
	int counter = 0;

	while (bob) {//itterate though frames diplay contents

		cout << "Image " << counter << ", file name = " << bob->GetFrameName() << endl;
		bob = bob->GetpNext();
		counter++;
	}

}


int  Animation::Length() {
	 

	Frame* local = frames;//local pointer 
	int counter = 0;

	while (local) {//itterate though frames diplay contents



		local = local->GetpNext();
		counter++;
	}


	return 0;
}







/*****************************************************************************************************************************
Fuction name:			~Animation
Purpose:				deconstructor to free(delete) all the remaining frame names and the animation name in animation
In Parameters			none
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
Animation::~Animation() {


	Frame* frame = frames;
	Frame* next;

	while (frame != NULL) {//delete all frames in animiation

		next = frame->GetpNext();
		delete(frame->GetFrameName());
		delete(frame);
		frame = next;
	}


	delete animationName;//delete animation name and set its pointer to null
	animationName = nullptr;

}


