#include <bits/stdc++.h>
#include "team.h"
#include "player.h"
using namespace std;
teamA * A_ptr;
teamB * B_ptr;
vector<player>A_players;
vector<player>B_players;
string batsman,bowler;
void line()
{
    cout<<"\n_____________________________________________________________________________________________________\n\n";
}
int getrandom(int limit) 
{ 
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> dis(0, limit); 
    return dis(gen); 
}
void greet()
{
    cout<<"\t\t\t\t\t\tWELCOME TO CRIC-IN GAME!!!";
    line();
    cout<<"Team Details:\n\n";
}
int val(vector<int>val)
{
    sort(val.begin(),val.end());
    if(val[0]<1 || val[3]>11)
    return 0;
    for(int i=1;i<val.size();i++)
    {
        if(val[i]==val[i-1])
        {
            return 0;
        }
    }
    return 1;
}
void selection1()
{
    cout<<"Select 4 players from "<<A_ptr->team_name<<":\nEnter 4 corresponding Players number\n\n";
    A_ptr->print();
    vector<int>vv(4);
    for(int i=0;i<4;i++)
    {
        cin>>vv[i];
    }
    if(val(vv))
    {
        for(int i=0;i<4;i++)
        {
            player pp(A_ptr->player[vv[i]-1],vv[i]);
            A_players.push_back(pp);
        }
        cout<<"4 selected players of "<<A_ptr->team_name<<" are :\n";
        for(int i=0;i<4;i++)
        {
            cout<<i+1<<' '<<A_players[i].name<<"\n";
        }
        line();
    }
    else
    {
        cout<<"Please give correct Input , Try again\n";
        selection1();
    }
}
void selection2()
{
    cout<<"Select 4 players from "<<B_ptr->team_name<<":\nEnter 4 corresponding Players number\n\n";
    B_ptr->print();
    vector<int>vv(4);
    for(int i=0;i<4;i++)
    {
        cin>>vv[i];
    }
    if(val(vv))
    {
        for(int i=0;i<4;i++)
        {
            player pp(B_ptr->player[vv[i]-1],11+vv[i]);
            B_players.push_back(pp);
        }
        cout<<"4 selected players of "<<B_ptr->team_name<<" are :\n";
        for(int i=0;i<4;i++)
        {
            cout<<i+1<<' '<<B_players[i].name<<"\n";
        }
        line();
    }
    else
    {
        cout<<"Please give correct Input , Try again\n";
        selection2();
    }
}
void play1()
{
    cout<<"India is Batting\n";
    int bt=0;
    batsman=A_players[bt].name;
    bowler=B_players[0].name;
    cout<<"Current Batsman:  "<<batsman<<"\n";
    cout<<"Current Bowler:  "<<bowler<<"\n";
    int runs;
    for(int i=1;i<=6;i++)
    {
        runs=getrandom(6);
        A_players[bt].bowls_faced++;
        A_players[bt].runs_scored+=runs;
        A_ptr->team_score+=runs;
        B_players[0].runs_given+=runs;
        B_ptr->total_bowls_bowled++;
        B_players[0].bowls_bowled++;
        if(runs==0)
        {
            cout<<A_players[bt].name<<" is out!!!\n";
            if(bt==3)
            {
                cout<<"ALL OUT!!!\n";
                break;
            }
            bt++;
            cout<<"Next Batsman :" << A_players[bt].name<<"\n";
            A_ptr->total_wickets_lost++;
            B_players[0].wickets_taken++;
        }
        cout<<"Bowl "<<i<<": "<<"Runs scored: "<<runs<<"\n\n";
    }
    cout<<"Total Runs: "<<A_ptr->team_score<<"\n";
    line();
}

void play2()
{
    cout<<"Australia is Batting\n";
    int bt=0;
    batsman=B_players[bt].name;
    bowler=A_players[0].name;
    cout<<"Current Batsman:  "<<batsman<<"\n";
    cout<<"Current Bowler:  "<<bowler<<"\n";
    int runs;
    for(int i=1;i<=6;i++)
    {
        runs=getrandom(6);
        B_players[bt].bowls_faced++;
        B_players[bt].runs_scored+=runs;
        B_ptr->team_score+=runs;
        A_players[0].runs_given+=runs;
        A_ptr->total_bowls_bowled++;
        A_players[0].bowls_bowled++;
        if(runs==0)
        {
            cout<<B_players[bt].name<<" is out!!!\n";
            if(bt==3)
            {
                cout<<"ALL OUT!!!\n";
                break;
            }
            bt++;
            cout<<"Next Batsman :" << B_players[bt].name<<"\n";
            B_ptr->total_wickets_lost++;
            A_players[0].wickets_taken++;
        }
        cout<<"Bowl "<<i<<": "<<"Runs scored: "<<runs<<"\n\n";
    }
    cout<<"Total Runs: "<<B_ptr->team_score<<"\n";
    line();
}
void winner()
{
    if(A_ptr->team_score==B_ptr->team_score)
    {
        cout<<"\t\t\tMATCH TIED!!!";
    }
    else
    {
        cout<<"\t\t\tWINNING TEAM IS:\n";
        if(A_ptr->team_score>B_ptr->team_score)
        {
            cout<<"\t\t\tINDIA !!!";
        }
        else
        {
            cout<<"\t\t\tAUSTRALIA !!!";
        }
    }
}
int main()
{
    A_ptr=&team_a;  
    B_ptr=&team_b;
    greet();
    selection1();
    selection2();
    int t=getrandom(1);
    if(t)
    {
        cout<<"\t\t\tIndia won the toss\n";
        int tt=getrandom(1);
        if(tt)
        {
            cout<<"\t\t\tIndia selected to Bat\n";
            line();
            play1();
            play2();
        }
        else
        {
            cout<<"\t\t\tIndia selected to Bowl\n";
            line();
            play2();
            play1();
        }
    }
    else
    {
        cout<<"\t\t\tAustralia won the toss\n";
        int tt=getrandom(1);
        if(tt)
        {
            cout<<"\t\t\tAustralia selected to Bat\n";
            line();
            play2();
            play1();
        }
        else
        {
            cout<<"\t\t\tAustralia selected to Bowl\n";
            line();
            play1();
            play2();
        }
    }
    winner();
    line();
    cout<<"\t\t\tMatch Summary\n";
    line();
    A_ptr->result();
    line();
    B_ptr->result();
    line();
    cout<<"\t\t\tTeam A summary\n\n";
    for(int i=0;i<4;i++)
    {
        A_players[i].print();
    }
    line();
    cout<<"\t\t\tTeam B summary\n";
    for(int i=0;i<4;i++)
    {
        B_players[i].print();
    }
    line();
	return 0;
}
