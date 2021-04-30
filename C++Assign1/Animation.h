//Animation.h
#pragma once

class Animation
{
	char* animationName;
	Frame* frames;
public:
	Animation();
	~Animation();
	int Length();
	void InsertFrame();
	void EditFrame();
	void DeleteFrame();
	void ReportAnimation();
};
