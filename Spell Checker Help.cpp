//Spell Checker Helper source codee
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)


void wordlist()
{
	ll Count=0;
	ll i,j;
	string str;
	getline(cin,str);
	string temp="";
	for(i=0;i<str.size();i++)
	{
		if(str[i]>='A' && str[i]<='Z')
			str[i]=str[i]+32;
		if(str[i]<'a'||str[i]>'z')
			str[i]=' ';
	}
	for(i=0;i<str.size();i++)
	{
		j=0;
		while(str[i+j]>='a' && str[i+j]<='z')
		{
			temp+=str[i+j];
			j++;
		}
		if(temp!="")
		{
			cout<<temp<<endl;
			Count++;
		}
		temp="";
		i+=j;
	}	
	cout<<"Total-"<<Count<<endl;
}

int main()
{
ll i,j;
freopen("LargeText.txt","r",stdin);
freopen("CompleteWordlist.txt","w",stdin);
wordlist();
return 0;
}

