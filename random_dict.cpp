#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<cctype>
#include<cstring>
using namespace std;

ifstream fin("msg.txt");
ofstream fout("random_dict.txt");
set<string> dict;
int globallongestrandom=0;

bool is_random(string p)
{
	int bucket[300];
	memset(bucket,0,sizeof(bucket));
	int longestrandom=0, cnt=0; bool last=0;
	for(int i=0;i<p.length();i++)
	{
		if(p[i]<0)continue;
		bucket[p[i]]++;
		if((p[i]=='r'||p[i]=='a'||p[i]=='n'||p[i]=='d'||p[i]=='o'||p[i]=='m'))
		{
			cnt++;
			last=1;
		}
		else if(last)
		{
			longestrandom=max(longestrandom,cnt);
			cnt=0;
		}
	}
	int aa=(bool)bucket['r']+(bool)bucket['a']+(bool)bucket['n']+(bool)bucket['d']+(bool)bucket['o']+(bool)bucket['m'];
	int a=bucket['r']+bucket['a']+bucket['n']+bucket['d']+bucket['o']+bucket['m'];
	if(aa>=5&&p.length()<=11)return true; else return false;
    //if(longestrandom>globallongestrandom)
	//{
	//	globallongestrandom=longestrandom;
	//	return true;
	//}else return false;
	return 0;
}

bool ispyy(string s){return s[0]=='f'&&s[1]=='0';}
bool islxh(string s){return s=="awa";}

inline bool isdelim(char c){return c==' '||c=='\r'||c=='\n'||c<=0||c=='\t'||c=='.'||c==','||c=='\''||c=='\"'||c=='!'||c=='?'||c>=128;}

string next_word()
{
    char c='=';
	string s="";
	while(!isdelim(c)&&!fin.eof())
	{
		fin.get(c);
		if(isalpha(c))c=tolower(c);
		s.push_back(c);
	}
	s.pop_back();
	return s;
}

int main()
{
	cout<<"welcome to random dictionary."<<endl;
	int j=0;
	while(!fin.eof())
	{
		string s=next_word();
		if(is_random(s)){cout<<s<<endl;j++;dict.insert(s);}
	}
	fout<<"Proudly Presents - the Random Dictionary of Tesserium!\n";
	int i=0;
	for(auto it:dict)
	{
		fout<<(i++)<<": "<<it<<endl;
	}
	cout<<"Out of total "<<j<<" words.\n";

	return 0;
}
