#include<bits/stdc++.h>
using namespace std;
class teamA
{
    public:
    string team_name;
    int team_score,total_wickets_lost,total_bowls_bowled;
    vector<string>player;
    teamA()
    {
        team_name="India";
        team_score=0;
	    total_bowls_bowled=0;
	    total_wickets_lost=0;
        player.push_back("Dhoni");
        player.push_back("Rohit");
        player.push_back("Kohli");
	    player.push_back("Dhawan");
	    player.push_back("Iyer");
	    player.push_back("Rahul");
	    player.push_back("Bumrah");
	    player.push_back("Tendulkar");
	    player.push_back("Sehwag");
	    player.push_back("Ghambir");
	    player.push_back("Raina");
    }
    void print()
    {
        cout<<"Team Name:  "<<team_name<<"\n";
	    cout<<"Players:\n";
	    for(int i=0;i<player.size();i++)
        cout<<i+1<<". "<<player[i]<<"\n";
    }
    void result()
    {
        cout<<"Team name :"<<team_name<<"\n";
        cout<<"Team_score :"<<team_score<<"\n";
        cout<<"Total_wickets_lost :"<<total_wickets_lost<<"\n";
        cout<<"Total_bowls_bowled :"<<total_bowls_bowled<<"\n\n";
    }
};

class teamB
{
    public:
    string team_name;
    int team_score,total_wickets_lost,total_bowls_bowled;
    vector<string>player;
    teamB()
    {
        team_name="Australia";
        team_score=0;
        total_bowls_bowled=0;
	    total_wickets_lost=0;
        player.push_back("Watson");
        player.push_back("Warner");
        player.push_back("Smith");
        player.push_back("Gilchrist");
	    player.push_back("Starc");
	    player.push_back("Henrique");
	    player.push_back("Ponting");
	    player.push_back("Michale");
	    player.push_back("warne");
	    player.push_back("Finch");
	    player.push_back("Cummins");
    }
    void print()
    {
        cout<<"Team Name:  "<<team_name<<"\n";
	    cout<<"Players:\n";
	    for(int i=0;i<player.size();i++)
        cout<<i+1<<". "<<player[i]<<"\n";
    }
    void result()
    {
        cout<<"Team name :"<<team_name<<"\n";
        cout<<"Team_score :"<<team_score<<"\n";
        cout<<"Total_wickets_lost :"<<total_wickets_lost<<"\n";
        cout<<"Total_bowls_bowled :"<<total_bowls_bowled<<"\n\n";
    }
};
teamA team_a;
teamB team_b;
