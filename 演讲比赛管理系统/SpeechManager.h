#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<map>
#include<functional>
#include<numeric>
#include<fstream>
#include<algorithm>
using namespace std;

class speecher
{
public:
	
	string name;
	double score[2];
};

class SpeechManager
{
public:
	SpeechManager();

	void InitSpeech();
	void CreatSpeecher();
	void Menu();
	void SpeechDraw();
	void SpeechContest();
	void ShowScore();
	void SpeechStart();
	void SaveSpeech();

	void LordRecord();
	map<int, vector<string>> Recordmap;
	bool isEmpty;


	void Showspeech();

	void ClearRecord();


	void ExitSpeech();

	~SpeechManager();

	vector<int>v1;
	vector<int>v2;
	vector<int>vVctory;
	map<int, speecher> Speechmap;
	int index;

};