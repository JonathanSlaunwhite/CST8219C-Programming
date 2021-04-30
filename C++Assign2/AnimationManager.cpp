/*****************************************************************************************************************************
Filename					 AnimationManager.cpp
Version						 1
Author/Student number		 Jonathan slaunwhite #040939090
class:						 C+++ CST8219
Lab section					 300
Assignment Number			 2
Assignment Name				 Lab_Component_2
DueDate						 2020-03-15
Submission Date				 2020-003-12
prof name					 Surbhi Bahri
Purpose						 This class will assist in the creation of animation name, editing animation
							 deleting animation and reporting animations
*****************************************************************************************************************************/



using namespace std;

#include <crtdbg.h> 
#include <iostream> 
#include <string>

#include <vector>

#include <forward_list>

#include "Frame.h"

#include "Animation.h"

#include "AnimationManager.h"




/*****************************************************************************************************************************
Fuction name:			istream
Purpose:				Inset an animation
In Parameters			istream,AnimationManager
Out parameters
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
istream& operator>>(std::istream& istream , AnimationManager& animationManager) {


	cout << "Add an Animation to the Animation "<< animationManager.managerName<<endl;//request information for animation
	cout << "Please enter the Animation Name : ";

	string animationName;//used variable to hold animation name
	
	cin >> animationName;//get information for animation name

	Animation animation(animationName);//Make animation with Animation name

	animationManager.animations.push_back(animation);//push animation to back of animations

	cout << "Animation " << animationName << " added at the back of animation" << endl;

	return istream;
}


/*****************************************************************************************************************************
Fuction name:			ostream
Purpose:				Display the animations
In Parameters			ostream,AnimationManager
Out parameters			ostream
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
ostream& operator<<(std::ostream& ostream, AnimationManager& animationManager) {

	cout << "AnimationManager: " << animationManager.managerName << endl;//report animationManager name


	if (animationManager.animations.empty()) {//if there are no animations in the animations
		return ostream << "There are no Animations"<<endl;
	}

	else {//else there are animations

		int counter = 0;//counter varible

		while (counter != animationManager.animations.size()) {//display animations until counter reaches size of animations

			ostream << "Animation: " << counter << endl << animationManager.animations.at(counter) << endl;//display contents of animation

			counter++;//increment the counter variable

		}

		return ostream;

	}
}

/*****************************************************************************************************************************
Fuction name:			EditAnimation
Purpose:				Edit a Animation
In Parameters			None
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
void AnimationManager::EditAnimation() {

	if (animations.size() != 0) {//if animations is not empty proceed
		int number;
		
		do {//repeat until valid data is entered
			cout << "Which Animation do you wish to edit? ";
			cout<<"Please give the index (from 0 to " <<animations.size()-1 << "): ";//minus 1 for number of indexs not how many
		
			cin >> number;
		} while (number >animations.size()-1||number<0);//for index check within range or less then 0

		cout << "Editing Animation # " << number<<endl;



		int choice = 0;//choice for menu
	
		do {

			cout << "Menu" << endl;
			cout << " 1. Insert a Frame" << endl;
			cout << " 2. Delete a Frame" << endl;
			cout << " 3. Edit a Frame" << endl;
			cout << " 4. Quit" << endl;
			
			cin >> choice;

			switch (choice) {

			case 1:
				cin >> animations.at(number);//insert a frame
				break;
			case 2:
				animations.at(number).DeleteFrame();//delete a frame
				break;
			case 3:
				animations.at(number).EditFrame();//edit a frame
				break;

			case 4://finished with frame

				cout << "Animation #"<<number<<" edit complete"<<endl;//display exit with frame leavging from

				break;


				default://user puts in anything else

				cout << "Please enter a valid option"<<endl;
				break;
			}

		} while (choice!=4);//loop while choice is not 4

	}else {//no animations

		cout << "There are no frames in the animation" << endl;//if user tries to edit an animation when there is none display message
	
	}


}

/*****************************************************************************************************************************
Fuction name:			DeleteFrame
Purpose:				Delete a animation
In Parameters			None
Out parameters			none
version					1.0
Author					Jonathan Slaunwhite
*****************************************************************************************************************************/
void AnimationManager::DeleteAnimation() {

	if (animations.size() != 0) {//if animations is not empty proceed

		cout << "Delete an Animation from the Animation Manager" << endl;
		
		int number=0;

		do {//repoeat until desired information is entered

			cout << "Which Animation do you wish to delete? Please give the index in the range 0 to " << animations.size() - 1 << ": ";
			cin >> number;
		} while (number> animations.size()-1 || number < 0);//loop untill right number is put in range or if negative is put in

		animations.erase(animations.begin() + number);//erase animation at specified index


		cout << "Animation #" << number << " deleted" << endl;//display animation has been deleted
	
	}
	else {//if user tries to delete with there being no animations
		cout << "There are no frames in the animation" << endl;
	}

}