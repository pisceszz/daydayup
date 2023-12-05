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
			string name = "�ݽ���";
			name += nameseed[i];
			speecher.name = name;
			speecher.score[0] = speecher.score[1] = 0;
			this->v1.push_back(i + 10001);
			this->Speechmap.insert(make_pair(i + 10001, speecher));
		}
}
void SpeechManager::SpeechDraw()
{
	cout << "--------------��" << this->index << "�ֱ�����ʼ��ǩ---------------" << endl;
	vector<int> ret;
	ret = this->index == 1 ? v1 : v2;
	random_shuffle(ret.begin(), ret.end());
	cout << "------------------------------------------------------------------" << endl;
	cout << "��" << this->index << "�ֱ�����ǩ�����" << endl;
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
			cout << "----------��" << num / 6 << "�����������£�-----------" << endl;
			for (multimap<double, int, greater<double>>::iterator it = retmap.begin(); it != retmap.end(); it++)
			{
				cout << "��ţ�" << it->second << "\t������" << this->Speechmap[it->second].name << "\t�÷֣�" << it->first<< endl;
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
	cout << "---------------��" << this->index << "�ֱ�������----------------" << endl;
	cout << endl;
}


void SpeechManager::ShowScore()
{
	vector<int> ret;
	ret = this->index == 1 ? v2 : vVctory;
	cout << "----------��" << this->index << "�ֱ�������ѡ�ֱ��-------------" << endl;
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << "��ţ�" << *it << "\t������" << this->Speechmap[*it].name << "\t�÷֣�" << this->Speechmap[*it].score[this->index-1] << endl;
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
	cout << "��¼�ѱ���" << endl;
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
		cout << "�ļ�������" << endl;
		this->isEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
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
			cout << "-----��" << it->first << "������ɼ���------" << endl;
			cout << "�ھ���" << "\t��ţ�" << it->second[0] << "  " << "�ɼ���" << it->second[1] << endl;
			cout << "�Ǿ���" << "\t��ţ�" << it->second[2] << "  " << "�ɼ���" << it->second[3] << endl;
			cout << "������" << "\t��ţ�" << it->second[4] << "  " << "�ɼ���" << it->second[5] << endl;
			cout << endl;

		}
	
}
void SpeechManager::ClearRecord()
{
	cout << "ȷ�������ʷ������" << endl;
	cout << "1.ȷ�����" << endl;
	cout << "2.�����" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		this->Recordmap.clear();
		this->isEmpty = true;
		cout << "��ճɹ�" << endl;

	}
	else if(choice==2){
		return;
	}
	else {
		cout<<"�����������������" << endl;
	}
	



}





void SpeechManager::Menu()
{
	cout << "************ ��ӭʹ���ݽ���������ϵͳ ************" << endl;
	cout << "*************** 1. ��ʼ�ݽ����� ******************" << endl; 
	cout << "*************** 2. �鿴�����¼ ******************" << endl;
	cout << "*************** 3. ��ձ�����¼ ******************" << endl;
	cout << "*************** 0. �˳��������� ******************" << endl;
	cout << "**************************************************" << endl;

}

void SpeechManager::ExitSpeech()
{
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
	system("pause");
}

SpeechManager::~SpeechManager() 
{

}