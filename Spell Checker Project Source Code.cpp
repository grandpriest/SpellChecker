//Spell Checker Project Source Code
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)


map <string,ll> map1;
set <string> v;
vector <string> words_suggested_for_given_word;

struct trie
{
	string  word_ending_here;
	struct trie * Next[26];
	trie()
	{
		word_ending_here="";
		ll k;
		for(k=0;k<26;k++)
			Next[k]=NULL;
	}
};
void add(struct trie * node,string word,ll pos)
{
	if(pos==word.size())
		node->word_ending_here=word;
	else
	{
		ll K=word[pos]-'a';
		if(node->Next[K]==NULL)
			node->Next[K]=new trie();
		add(node->Next[K],word,pos+1);
	}
}

bool find(struct trie * node,string word,ll pos)
{
	if(pos==word.size())
	{
		if(node->word_ending_here=="")
			return 0;
		else
			return 1;
	}
	else
	{
		ll K=word[pos]-'a';
		if(node->Next[K]==NULL)
			return 0;
		return find(node->Next[K],word,pos+1);
	}
}


void suggesting_words(struct trie * node)
{
	ll i,j;
	for(i=0;i<26;i++)
	{
		if(node->Next[i]!=NULL)
			suggesting_words(node->Next[i]);
	}
	if(node->word_ending_here!="")
		words_suggested_for_given_word.push_back(node->word_ending_here);
}


void suggestion(struct trie * node,string word,ll pos)
{
	if(pos==word.size())
		return suggesting_words(node);	
	ll K=word[pos]-'a';
	if(node->word_ending_here!="")
		words_suggested_for_given_word.push_back(node->word_ending_here);
	if(node->Next[K]==NULL)	//word mismatch
		return suggesting_words(node);	
	else if(node->Next[K]!=NULL)
		return suggestion(node->Next[K],word,pos+1);
}

int main()
{
ll i,j;

struct trie * root =new trie;
ifstream in("CompleteWordlist.txt");
	string word;
	while(in)
	{
        in>>word;
        map1[word]++;
        v.insert(word);
    }
    in.close();

for(set <string> ::iterator it=v.begin();it!=v.end();it++)
	add(root,*it,0LL);
in.close();

cout<<"SYSTEM READY FOR SPELL CHECK:";
cout<<endl<<endl;
while(1)
{
	cout<<"ENTER THE WORD:";

	string temp;
	cin>>temp;
	if(find(root,temp,0LL))
		cout<<"ENTERED WORD IS CORRECT:"<<temp<<endl;
	else
	{
		words_suggested_for_given_word.clear();
		suggestion(root,temp,0LL);
		string most_favourable_word="";
		ll freq=0;
		for(i=0;i<words_suggested_for_given_word.size();i++)
		{
			if(freq<map1[words_suggested_for_given_word[i]])
			{
				freq=map1[words_suggested_for_given_word[i]];
				most_favourable_word=words_suggested_for_given_word[i];
			}
		}
		cout<<endl<<"SUGGESTION::"<<most_favourable_word<<endl;
	}
	cout<<"Enter EXIT to exit or anything else to continue:";
	string ch;
	cin>>ch;
	if(ch=="EXIT" or ch=="exit")
		break;
}
return 0;
}

