#include <iostream>
#include <windows.h>
using namespace std;
#define RAYHEADERSMAIN
#include <rayrand.h>

//char *cons="bcdfghjklmnpqrstvwxz";
char *cons="bcdfghjklmnprstvwx";
char *vowels="aeiouy";
RayRand64 rrand;

void GenName()
{
	char name[128];
	int num_cons=strlen(cons);
	int num_vowels=strlen(vowels);
	int slen = rrand.iRand64HQ()%6+3;
	int letter = rrand.iRand64HQ()%2;
	for(int i=0;i<slen;i++)
	{
		if(letter==0)
		{
			letter=1;
			name[i]=cons[rrand.iRand64HQ()%num_cons];
		}
		else
		{
			letter=0;
			name[i]=vowels[rrand.iRand64HQ()%num_vowels];
		}
	}
	name[slen]='\0';
	cout << name << "\n";
}

int main()
{
	while(1)
	{
		GenName();
		Sleep(1000);
	}
}
