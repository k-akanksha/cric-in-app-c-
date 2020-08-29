class player
{
	public:
	string name;
	int id,runs_scored,bowls_faced,bowls_bowled,runs_given,wickets_taken;
	player(string s,int idd)
	{
		name=s;
		id=idd;
		runs_scored=0;
		bowls_faced=0;
		bowls_bowled=0;
		runs_given=0;
		wickets_taken=0;
	}
	void print()
	{
	    cout<<"Name: "<<name<<"\n";
	    cout<<"Id: "<<id<<"\n";
	    cout<<"Runs_scored: "<<runs_scored<<"\n";
	    cout<<"Bowls_faced: "<<bowls_faced<<"\n";
	    cout<<"Bowls_bowled: "<<bowls_bowled<<"\n";
	    cout<<"Runs_given: "<<runs_given<<"\n";
	    cout<<"Wickets_taken: "<<wickets_taken<<"\n\n";
	}
};
		
