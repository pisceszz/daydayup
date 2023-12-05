 #define _CRT_SECURE_NO_WARNINGS
#include"SpeechManager.h"

SpeechManager::SpeechManager()
{
	this-> InitSpeech();
	this-> CreatSpeecher();
}
void SpeechManager::InitSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVctory.clear();
	this->Speechmap.clear();
	this->isEmpty=false;
	this->index=1;
	this->Recordmap.clear();
}
void SpeechManager::CreatSpeecher()
{
	string nameseed = "ABCDEFJHLJKL";
		for (int i = 0; i < 12; i++)
		{
			speecher speecher;
			string name = "演讲者";
			name += nameseed[i];
			speecher.name = name;
			speecher.score[0] = speecher.score[1] = 0;
			this->v1.push_back(i + 10001);
			this->Speechmap.insert(make_pair(i + 10001, speecher));
		}
}
void SpeechManager::SpeechDraw()
{
	cout << "--------------第" << this->index << "轮比赛开始抽签---------------" << endl;
	vector<int> ret;
	ret = this->index == 1 ? v1 : v2;
	random_shuffle(ret.begin(), ret.end());
	cout << "------------------------------------------------------------------" << endl;
	cout << "第" << this->index << "轮比赛抽签结果：" << endl;
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	cout << "------------------------------------------------------------------" << endl;
	system("pause");
}

void SpeechManager::SpeechContest()
{
	vector<int> ret;
	multimap<double, int,greater<double>> retmap;
	int num = 0;
	ret = this->index == 1 ? v1 : v2;
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double tmp = (rand() % 401 + 600.0) / 10.0;
			d.push_back(tmp);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		double avg = accumulate(d.begin(), d.end(), 0.0) / d.size();
		this->Speechmap[*it].score[index - 1] = avg;
		retmap.insert(make_pair(avg, *it));
	    
		num++;
		if (num % 6 == 0)
		{
			cout << "----------第" << num / 6 << "组比赛结果如下：-----------" << endl;
			for (multimap<double, int, greater<double>>::iterator it = retmap.begin(); it != retmap.end(); it++)
			{
				cout << "编号：" << it->second << "\t姓名：" << this->Speechmap[it->second].name << "\t得分：" << it->first<< endl;
			}
			system("pause");
		
		int count = 3;
		for (multimap<double, int, greater<double>>::iterator it = retmap.begin(); it != retmap.end() && count; it++, count--)
		{
			if (this->index == 1)
			{
				v2.push_back(it->second);
			}
			else {
				vVctory.push_back(it->second);
			}
		}
		retmap.clear();
		}
	}
	cout << "---------------第" << this->index << "轮比赛结束----------------" << endl;
	cout << endl;
}


void SpeechManager::ShowScore()
{
	vector<int> ret;
	ret = this->index == 1 ? v2 : vVctory;
	cout << "----------第" << this->index << "轮比赛晋级选手编号-------------" << endl;
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << "编号：" << *it << "\t姓名：" << this->Speechmap[*it].name << "\t得分：" << this->Speechmap[*it].score[this->index-1] << endl;
	}
	system("pause");
}

void SpeechManager::SaveSpeech()
{
	ofstream ofs("speech.csv",ios::out|ios::app);
	for (vector<int>::iterator it = vVctory.begin(); it != vVctory.end(); it++)
	{
		ofs << *it << "," << this->Speechmap[*it].score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已保存" << endl;
	this->isEmpty = false;
	system("pause");
}


void SpeechManager::SpeechStart()
{
	this->SpeechDraw();
	this->SpeechContest();
	this->ShowScore();
	this->index++;
	this->SpeechDraw();
	this->SpeechContest();
	this->ShowScore();
	this->SaveSpeech();
	
}

void SpeechManager::LordRecord()
{
	ifstream ifs("speech.csv",ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->isEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->isEmpty = true;
		ifs.close();
		return;
	}

	ifs.putback(ch);
	this->isEmpty = false;
	string data;
	int Recordnum = 1;
	while (ifs>>data)
	{
		int start = 0;
		int pos = 0;
		vector<string> v;

		while ((pos = (int)data.find(",", start))!=-1)
		{
			string tmp = data.substr(start, pos - start);
			v.push_back(tmp);
			start = pos + 1;
		}
		this->Recordmap.insert(make_pair(Recordnum, v));
		Recordnum++;
	}
	ifs.close();

}

void SpeechManager::Showspeech()
{
	this->LordRecord();

	
		for (map<int, vector<string>>::iterator it = Recordmap.begin(); it != Recordmap.end(); it++)
		{
			cout << "-----第" << it->first << "届比赛成绩：------" << endl;
			cout << "冠军：" << "\t编号：" << it->second[0] << "  " << "成绩：" << it->second[1] << endl;
			cout << "亚军：" << "\t编号：" << it->second[2] << "  " << "成绩：" << it->second[3] << endl;
			cout << "季军：" << "\t编号：" << it->second[4] << "  " << "成绩：" << it->second[5] << endl;
			cout << endl;

		}
	
}
void SpeechManager::ClearRecord()
{
	cout << "确定清空历史数据吗？" << endl;
	cout << "1.确定清空" << endl;
	cout << "2.不清空" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		this->Recordmap.clear();
		this->isEmpty = true;
		cout << "清空成功" << endl;

	}
	else if(choice==2){
		return;
	}
	else {
		cout<<"输入错误，请重新输入" << endl;
	}
	



}





void SpeechManager::Menu()
{
	cout << "************ 欢迎使用演讲比赛管理系统 ************" << endl;
	cout << "*************** 1. 开始演讲比赛 ******************" << endl; 
	cout << "*************** 2. 查看往届记录 ******************" << endl;
	cout << "*************** 3. 清空比赛记录 ******************" << endl;
	cout << "*************** 0. 退出比赛程序 ******************" << endl;
	cout << "**************************************************" << endl;

}

void SpeechManager::ExitSpeech()
{
	cout << "欢迎下次使用" << endl;
	exit(0);
	system("pause");
}

SpeechManager::~SpeechManager() 
{

}