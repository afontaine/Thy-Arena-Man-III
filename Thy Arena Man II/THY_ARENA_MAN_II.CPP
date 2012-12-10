#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
int end=0;
int ignition;
int answer;
int health[4];
int skill[4];
int weapon_speed;
int weapon_strength;
int opponent_weapon_speed;
int opponent_weapon_strength;
int strength[4];
int wound[4];
int w[4];
int fight_1=1;
int fight_2=1;
int hit=0;
int def=0;
int crit=0;
char grid[25];
char name[4][10];
int item[4][4];
int mega_answer[4];
int x;
int y;
int l;
int p;
int e;
int c;
int i[4];
int players;
int player[4];
int charge[4];
int pornmag[4][4];
int m[4];
int o;
int pg;
int move=1;
int weight[4];
int answer_stance[4];
int armour_protection[4];
int armour_skill[4];
int weapon[3][2];
int health_pack=0;
int dead_players=0;
int banish=25;
int locate=0;
int row[4];
int column[4];
int row_diff[4];
int column_diff[4];
int moves_away[4];
int arrows[4][4];
int row_health;
int column_health;
int row_target;
int column_target;
int row_locate;
int column_locate;
void arena();
void fight();
void endgame();
void items();
void ai_choose();
void ai_locate();
void ai_move();
void ai_moves_away();
int main()
{while(end!=1)
{srand((unsigned)time(NULL));
	for(p=0;p<4;p++)
	{	for(l=0;l<10;l++)
		{name[p][l]=' ';
		}
	charge[p]=0;
	}
weapon[0][0]=6;/*this defines what the accuracy and damage each weapon does*/
weapon[0][1]=2;
weapon[1][0]=5;
weapon[1][1]=4;
weapon[2][0]=4;
weapon[2][1]=6;
cout<<"Welcome to THY ARENA MAN!!!!!\n\n";
cout<<"The game in which thou wilt be pitted against thine most horrid friends and enemies,\nand given a chance to beat them into a bloody pulp\nwhich you cannot do in real life\n";
cout<<"Press 1 to start anew\nPress 2 to leave without even trying this masterpiece of a game.\n\n";
cin>>answer;
	if (answer==1)
	{cout<<"thou wilt not regret thine choice!!\n";
	cout<<"how many ARENAMEN wilt thou have, playing in this fine ARENA?\nKeep in mind that there is a limit of 2 ARENAMEN to 4 ARENAMEN";
	cin>>players;
	cout<<"\a";
		while(players>4 || players<2)
		{cout<<"didst thou not hear mine previous statement hookerfaggot!!!\nOnly 2 to 4 players!!!\nretype it...\n\n";
		cin>>players;
		}
		for(p=0;p<players;p++)/*this lets each player (defined by the forloop) decide their class, armour, and weapon*/
		{cout<<"now, player "<<p+1<<", please type in your name\n\n";
		cin>>name[p];
		cout<<"\n"<<name[p]<<"\npress 1 if you are a real person\npress 2 if you are a computer\n";
		cin>>player[p];
			if(player[p]==1)
			{cout<<"Ok, "<<name[p]<<" pick your player class.\npress 1 for the Rogue\nhe can attack twice every 5 moves\npress 2 for the Soldier\nif you stay still to attack an enemy, you get a stat boostpress 3 for the Berzerker\nevery 5 moves he can become MEGA AWESOME\n\n";
			cout<<"          Rogue  Soldier  Berzerker\n\n";
			cout<<"skill:     20      19        18    \n\n";
			cout<<"strength:   8       9        10    \n\n";
			cout<<"health:    20      20        20    \n\n";
			cin>>answer;
			}
			else
			{answer=rand()%3+1;}
			cout<<"\a";

			if(answer==1)/*these if statements define what the skills and strength of each player is.*/
			{cout<<name[p]<<" is a Rogue\n";
			skill[p]=20;
			strength[p]=8;
			health[p]=20;
			}
			if(answer==2)
			{cout<<name[p]<<" is a Soldier\n";
			skill[p]=19;
			strength[p]=9;
			health[p]=20;
			}
			if(answer==3)
			{cout<<name[p]<<" is a Berzerker\n";
			skill[p]=18;
			strength[p]=10;
			health[p]=20;
			}
			if(player[p]==1)
			{cout<<"now, "<<name[p]<<" pick your armour.\npress 1 for Leather armour\npress 2 for Chainmail armour\npress 3 for Platemail armour\npress 4 to go in naked and intimidate yer opponents\n\n";
			cout<<"                Leather  Chainmail  Platemail  Naked\n\n";
			cout<<"Protection:        1         3          5        0  \n\n";
			cout<<"skill modifier:    0        -1         -2       -2 (from the enemy)\n\n";
			cin>>answer;
			}
			else
			{answer=rand()%4+1;}
			cout<<"\a";

			if(answer==1)/*these if statements define what the skills and strength of each player's armour.*/
			{cout<<name[p]<<" has leather armour\n";
			armour_protection[p]=1;
			armour_skill[p]=0;
			}
			if(answer==2)
			{cout<<name[p]<<" has Chainmail armour\n";
			armour_protection[p]=3;
			armour_skill[p]=1;
			}
			if(answer==3)
			{cout<<name[p]<<" has Platemail armour\n";
			armour_protection[p]=5;
			armour_skill[p]=2;
			}
			if(answer==4)
			{cout<<name[p]<<"is going in naked...\n";
			armour_protection[p]=0;
			armour_skill[p]=0;
			}
			if(player[p]==1)
			{cout<<"now, "<<name[p]<<" pick your weapon.\npress 1 for the Rapier\npress 2 for the Broadsword\nprss 3 for the Battleaxe\n\n";
			cout<<"          Rapier  Broadsword  Battleaxe\n\n";
			cout<<"speed:       6         5           4   \n\n";
			cout<<"strength:    2         4           6   \n\n";
			cin>>answer;
			}
			else
			{answer=rand()%3+1;}
			cout<<"\a";
			
			if(answer==1)/*these if statements define what the skills and strength of each player's weapon is.*/
			{cout<<name[p]<<" has a Rapier\n";
			w[p]=0;
			}
			if(answer==2)
			{cout<<name[p]<<" has a Broadsword\n";
			w[p]=1;
			}
			if(answer==3)
			{cout<<name[p]<<" has a Battleaxe\n";
			w[p]=2;
			}
		items();
		}
	cout<<"Press 1 to begin thine Grand adventure!!!!\n";
	cin>>ignition;
	cout<<"\a";
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	arena();
		if(end==1)
		{return 0;}
	}
	if (answer==2 && end!=3)
	{cout<<"You silly Sod, this could have been the greatest moment of thine life.\n";
	cout<<"but now you it's all over, You will never experience this game.\n";
	cout<<"Go.... JUST GO!!!!! I'm obviously not good enough for you...";
	return 0;
	}
}
return 0;
}

void items()
{	if(player[p]==1)
	{cout<<name[p]<<"\npress 1 to choose cool shit\npress 2 for the computer to choose random ones for you\n\n";
	cin>>answer;
	}
cout<<"\a";
	if(answer==1 && player[p]==1)
	{	for(x=1;x<4;x++)
		{pornmag[p][x]=0;
		cout<<"you have "<<4-x<<" items left to choose\n\npress 1 for steroids\nthey make you MEGA AWESOME for one turn\n(infulnerable, skill boost, strength boost)\n\npress 2 for a porn magazine\nyou drop it on the ground, and if an enemy steps on it\nhe loses a turn as he observes the scantily clad babes\n\npress 3 for a bow with 5 arrows\n\npress 4 for a teleporter\n\npress 5 for a spare medkit\n\npress 6 for a dead carcass to lug around\nthat intimidates yer opponents\n(lowers their skill)\n\n";
		cin>>item[p][x];
			if(item[p][x]==3)
			{arrows[p][x]=5;}
		}
	}
	if(answer==2 || player[p]==2)
	{	for(x=1;x<4;x++)	
		{item[p][x]=rand()%6+1;
			if(item[p][x]==3)
			{arrows[p][x]=5;}
		}
		
	}
return;
}

void endgame()
{cout<<"press 1 to play another game with these characters\npress 2 to make new characters\npress 3 to quit\n";
cin>>answer;
cout<<"\a";
	if(answer==1)
	{dead_players=0;
	banish=25;
		for(p=0;p<players;p++)
		{health[p]=20;
		if(player[p]==3)
		{player[p]=1;}
		if(player[p]==4)
		{player[p]=2;}
		i[p]=0;
		charge[p]=0;
			for(x=0;x<4;x++)
			{pornmag[p][x]=0;}
		items();
		}
	m[0]=rand()%25+1;
		while(m[1]==m[0] || m[1]==0 || m[1]>25)
		{m[1]=rand()%25+1;}
		while(m[2]==m[0] || m[2]==m[1] || m[2]==0 || m[2]>25)
		{m[2]=rand()%25+1;}
		while(m[3]==m[0] || m[3]==m[1] || m[3]==m[2] || m[3]==0 || m[3]>25)
		{m[3]=rand()%25+1;}
		while(health_pack==m[0] || health_pack==m[1] || health_pack==m[2] || health_pack==m[3] || health_pack==0)
		{health_pack=rand()%25+1;}
	p=0;
	end=2;
	}
	if(answer==2)
	{dead_players=0;
	banish=25;
		for(p=0;p<players;p++)
		{health[p]=20;
		if(player[p]==3)
		{player[p]=1;}
		if(player[p]==4)
		{player[p]=2;}
		i[p]=0;
		charge[p]=0;
			for(x=0;x<4;x++)
			{pornmag[p][x]=0;}
		}
	p=0;
	end=3;
	}
	if(answer==3)
	{cout<<"You silly Sod, this could have been the greatest moment of thine life.\n";
	cout<<"but now you it's all over, You will never experience this game.\n";
	cout<<"Go.... JUST GO!!!!! I'm obviously not good enough for you...";
	end=1;
	return;
	}
return;
}



void arena()
{m[0]=rand()%25+1;
	while(m[1]==m[0] || m[1]==0 || m[1]>25)
	{m[1]=rand()%25+1;}
	while(m[2]==m[0] || m[2]==m[1] || m[2]==0 || m[2]>25)
	{m[2]=rand()%25+1;}
	while(m[3]==m[0] || m[3]==m[1] || m[3]==m[2] || m[3]==0 || m[3]>25)
	{m[3]=rand()%25+1;}
	while(health_pack==m[0] || health_pack==m[1] || health_pack==m[2] || health_pack==m[3] || health_pack==0)
	{health_pack=rand()%25+1;}
	while(players>0)
	{//i=0;
		for(p=0;p<players;p++)
		{	for(x=0;x<26;x++)
			{grid[x]=' ';
			}
			for(pg=0;pg<players;pg++)
			{grid[m[pg]]=name[pg][0];
			}
			grid[health_pack]='+';
			if(health[p]>0)
			{cout<<"   ^   \n";
			cout<<"   8     "<<name[p]<<"\n";
			cout<<"         Class: ";
				if(strength[p]==8)
				{cout<<"Rogue\n";}
				if(strength[p]==9)
				{cout<<"Soldier\n";}
				if(strength[p]==10)
				{cout<<"Berzerker\n";}
			cout<<"<4 5 6>  Armour: ";
				if(armour_protection[p]==1)
				{cout<<"Leather\n";}
				if(armour_protection[p]==3)
				{cout<<"Chainmail\n";}
				if(armour_protection[p]==5)
				{cout<<"Platemail\n";}
				if(armour_protection[p]==0)
				{cout<<"Is Naked...\n";}
			cout<<"         Weapon: ";
				if(w[p]==0)
				{cout<<"Rapier\n";}
				if(w[p]==1)
				{cout<<"Broadsword\n";}
				if(w[p]==2)
				{cout<<"Battleaxe\n";}
			cout<<"   2     Health: "<<health[p]<<"\n";
			cout<<"   v   \n";
			cout<<" ___________________\n";
			cout<<"|                   |\n";
			cout<<"| "<<grid[1]<<"   "<<grid[2]<<"   "<<grid[3]<<"   "<<grid[4]<<"   "<<grid[5]<<" |     Items:\n";
			cout<<"|                   |\n";
			cout<<"|                   |\n";
			cout<<"| "<<grid[6]<<"   "<<grid[7]<<"   "<<grid[8]<<"   "<<grid[9]<<"   "<<grid[10]<<" | ";
				if(item[p][1]==1)
				{cout<<"   Steroids\n";}
				if(item[p][1]==2)
				{cout<<"1: porn magazine\n";}
				if(item[p][1]==3)
				{cout<<"1: bow ("<<arrows[p][1]<<" arrows)\n";}
				if(item[p][1]==4)
				{cout<<"1: teleporter\n";}
				if(item[p][1]==5)
				{cout<<"1: spare medkit\n";}
				if(item[p][1]==6)
				{cout<<"   Dead carcass\n";}
				if(item[p][1]==0)
				{cout<<"\n";}
			cout<<"|                   |\n";
			cout<<"|                   |\n";
			cout<<"| "<<grid[11]<<"   "<<grid[12]<<"   "<<grid[13]<<"   "<<grid[14]<<"   "<<grid[15]<<" | ";
				if(item[p][2]==1)
				{cout<<"   Steroids\n";}
				if(item[p][2]==2)
				{cout<<"3: porn magazine\n";}
				if(item[p][2]==3)
				{cout<<"3: bow ("<<arrows[p][2]<<" arrows)\n";}
				if(item[p][2]==4)
				{cout<<"3: teleporter\n";}
				if(item[p][2]==5)
				{cout<<"3: spare medkit\n";}
				if(item[p][2]==6)
				{cout<<"   Dead carcass\n";}
				if(item[p][2]==0)
				{cout<<"\n";}
			cout<<"|                   |\n";
			cout<<"|                   |\n";
			cout<<"| "<<grid[16]<<"   "<<grid[17]<<"   "<<grid[18]<<"   "<<grid[19]<<"   "<<grid[20]<<" | ";
				if(item[p][3]==1)
				{cout<<"   Steroids\n";}
				if(item[p][3]==2)
				{cout<<"7: porn magazine\n";}
				if(item[p][3]==3)
				{cout<<"7: bow ("<<arrows[p][3]<<" arrows)\n";}
				if(item[p][3]==4)
				{cout<<"7: teleporter\n";}
				if(item[p][3]==5)
				{cout<<"7: spare medkit\n";}
				if(item[p][3]==6)
				{cout<<"   Dead carcass\n";}
				if(item[p][3]==0)
				{cout<<"\n";}
			cout<<"|                   |\n";
			cout<<"|                   |\n";
			cout<<"| "<<grid[21]<<"   "<<grid[22]<<"   "<<grid[23]<<"   "<<grid[24]<<"   "<<grid[25]<<" |\n";
			cout<<"|___________________|\n";
				if(player[p]==1)
				{	while(move!=0)
					{cin>>move;
						while(move==9)
						{cout<<"sorry, but you can't move that way\n";
						cin>>move;
						}
						if(move==1)
						{i[p]=1;}//with i defined, now if statements are situated around the program checking if the item chosen (defined by i) is the item the if statement corresponds to
						if(move==3)
						{i[p]=2;}
						if(move==7)
						{i[p]=3;}
						
						if(item[p][i[p]]==2)
						{cout<<name[p]<<" just placed his porn mag on the ground\nnow any unsuspecting heterosexual will stop and stare at its scantily clad babes\a\n\n";
						pornmag[p][i[p]]=m[p];
						item[p][i[p]]=0;
						i[p]=0;
						}
						if(item[p][i[p]]==5)
						{health[p]=health[p]+5;
						cout<<name[p]<<" just used his spare medkit, his/her health is now "<<health[p]<<"\a\n";
						item[p][i[p]]=0;
						i[p]=0;
						}

						if(item[p][i[p]]==3)
						{cout<<"select the player you wish to shoot:\n";
							for(x=0;x<players;x++)
							{	if(x!=p)
								{	if(health[x]>0)
									{cout<<"press "<<x<<" to shoot "<<name[x]<<"\n";}
								}
							}
						cin>>o;
						ai_moves_away();
						crit=rand()%20+1;
							if(crit==1)
							{cout<<name[p]<<" sent a screaming arrow into "<<name[o]<<"'s eye socket\a\a\a\n\n";
							health[o]=0;
							}
							else
							{hit=rand()%(skill[p]-moves_away[o]);
							def=rand()%10;
								if(hit>=def)
								{wound[o]=rand()%(12-moves_away[o]);
								health[o]=health[o]-wound[o];
								cout<<name[p]<<" hits "<<name[o]<<" with his bow and wounds him "<<wound[o]<<" points\nhis health is now "<<health[o]<<"\a\n";
								}
								else
								{cout<<name[p]<<" missed "<<name[o]<<"\a\n";}
							}
							if (health[o]<1)
							{cout<<name[p]<<" hast defeated the lowly "<<name[o]<<"\a\n";
							cout<<"\a\a\a\a\a\a\a\a\a";
							dead_players=dead_players+1;
								if(dead_players==players-1)
								{cout<<"\n\n"<<name[p]<<" IS MOST TRIUMPHANT!!!!!!!\n\nHE IS NOW THE NEW ARENAMAN!!!!!!!!!!!!!!\n\n";
								cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
								endgame();
									if(end==1 || end==3)
									{return;}
								}
							}
							if(end==2)
							{end=0;
							break;
							break;
							}
							else
							{arrows[p][i[p]]=arrows[p][i[p]]-1;	
								if(arrows[p][i[p]]==0)
								{cout<<name[p]<<"'s bow is out of arrows\nhe casts away the useless bow\a\n\n";
								item[p][i[p]]=0;
								}
								else
								{cout<<name[p]<<" has "<<arrows[p][i[p]]<<" more arrows\a\n\n";}
							i[p]=0;
							}
						}

						if(item[p][i[p]]==4)
						{cout<<"you have chosen to use yer teleporter\ntype in the number that corresponds to the space you wish to go:\n 1  2  3  4  5\n 6  7  8  9 10\n11 12 13 14 15\n16 17 18 19 20\n21 22 23 24 25\n";
						cin>>m[p];
						cout<<name[p]<<" used his teleporter and teleported to grid number "<<m[p]<<"\a\n\n";
						item[p][i[p]]=0;
						break;
						}

						if(move==8)/*this moves up*/
						{m[p]=m[p]-5;
							if(m[p]<1)
							{cout<<"sorry, but you can't move that way\n";
							m[p]=m[p]+5;
							}
							else
							{break;}
						}
						if(move==2)/*this moves down*/
						{m[p]=m[p]+5;
							if(m[p]>25)
							{cout<<"sorry, but you can't move that way\n";
							m[p]=m[p]-5;
							}
							else
							{break;}
						}
						if(move==6)/*this moves right*/
						{m[p]=m[p]+1;
							if((m[p]==6)||(m[p]==11)||(m[p]==16)||(m[p]==21)||(m[p]>25))
							{cout<<"sorry, but you can't move that way\n";
							m[p]=m[p]-1;
							}
							else
							{break;}
						}
						if(move==4)/*this moves left*/
						{m[p]=m[p]-1;
							if((m[p]==5)||(m[p]==10)||(m[p]==15)||(m[p]==20)||(m[p]<1))
							{cout<<"sorry, but you can't move that way\n";
							m[p]=m[p]+1;
							}
							else
							{break;}
						}
						if(move==5)
						{break;}
					}
				}
				if(player[p]==2)
				{	for(x=1;x<4;x++)
					{	if(item[p][x]==5)
						{	for(o=0;o<players;o++)
							{	if(o!=p)
								{	if(health[o]>health[p] || health[p]<10)
									{health[p]=health[p]+5;
									cout<<name[p]<<" used his spare medkit, his health is now "<<health[p]<<"\a\n\n";
									item[p][x]=0;
									break;
									}
								}
							}
						}
						if(item[p][x]==4)
						{	for(o=0;o<players;o++)
							{	if(o!=p)
								{	if(health[o]>(health[p]+5) || health[p]<10)
									{m[p]=health_pack;
									cout<<name[p]<<" used his teleporter and teleported to grid number "<<m[p]<<"\a\n\n";
									item[p][x]=0;
									break;
									}
									if(m[o]>0 && m[o]<26)
									{	if(health[p]>(health[o]+5) && m[p]!=m[o] && health[0]>0)
										{m[p]=m[o];
										cout<<name[p]<<" used his teleporter and teleported to grid number "<<m[p]<<"\a\n\n";
										item[p][x]=0;
										break;
										}
									}
								}
							}
						}
						if(item[p][x]==3)
						{	for(o=0;o<players;o++)
							{ai_moves_away();
								for(e=0;e<players;e++)
								{	if((o!=e) && (o!=p) && (e!=p))
									{	if(moves_away[o]<moves_away[e])
										{weight[e]=weight[e]+1;}
									}
								}
							}
							for(o=0;o<players;o++)
							{	if(o!=p && weight[o]==0 && health[o]>(health[p]+5) && m[p]!=m[o])
								{crit=rand()%20+1;
									if(crit==1)
									{cout<<name[p]<<" sent a screaming arrow into "<<name[o]<<"'s eye socket\a\a\a\n\n";
									health[o]=0;
									}
									else
									{hit=rand()%(skill[p]-moves_away[o]);
									def=rand()%10;
										if(hit>=def)
										{wound[o]=rand()%(12-moves_away[o]);
										health[o]=health[o]-wound[o];
										cout<<name[p]<<" hits "<<name[o]<<" with his bow and wounds him "<<wound[o]<<" points\nhis health is now "<<health[o]<<"\a\n";
										}
										else
										{cout<<name[p]<<" missed "<<name[o]<<"\a\n";}
									}
									if (health[o]<1)
									{cout<<name[p]<<" hast defeated the lowly "<<name[o]<<"\a\n";
									cout<<"\a\a\a\a\a\a\a\a\a";
									dead_players=dead_players+1;
										if(dead_players==players-1)
										{cout<<"\n\n"<<name[p]<<" IS MOST TRIUMPHANT!!!!!!!\n\nHE IS NOW THE NEW ARENAMAN!!!!!!!!!!!!!!\n\n";
										cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
										endgame();
											if(end==1 || end==3)
											{return;}
										}
									}
									if(end==2)
									{end=0;
									break;
									}
									else
									{arrows[p][x]=arrows[p][x]-1;	
										if(arrows[p][x]==0)
										{cout<<name[p]<<"'s bow is out of arrows\nhe casts away the useless bow\a\n";
										item[p][x]=0;
										}
										else
										{cout<<name[p]<<" has "<<arrows[p][x]<<" more arrows\n\n";}
									}
								}
							}
						}
						if(item[p][x]==2)
						{answer=rand()%7+1;
							if(answer==1)
							{cout<<name[p]<<" just placed his porn mag on the ground\nnow any unsuspecting heterosexual will stop and stare at its scantily clad babes\a\n\n";
							pornmag[p][x]=m[p];
							item[p][x]=0;
							}
						}
					}
				ai_choose();
				}
			charge[p]=charge[p]+1;
			cout<<"\a";

				if(player[p]==3)
				{cout<<"still lookin at the fine babes...\n";
				player[p]=1;
				}
				if(player[p]==4)
				{cout<<"still lookin at the fine babes...\n";
				player[p]=2;
				}

				if(health_pack==m[p])
				{	if(player[p]==1)
					{cout<<name[p]<<"\npress 1 to use this medkit now\npress 2 to carry it round for a while\n\n";
					cin>>answer;
						if(answer==1)
						{health[p]=health[p]+5;
						cout<<name[p]<<" got 5 points of health!\nhis/her health is now "<<health[p]<<"\n";
						}
						if(answer==2)
						{	for(x=1;x<4;x++)
							{	if(item[p][x]==0)
								{cout<<"press "<<x<<" to place it in slot "<<x<<"\n";}
								if(item[p][x]==1)
								{cout<<"press "<<x<<" to replace yer steroids with it\n";}
								if(item[p][x]==2)
								{cout<<"press "<<x<<" to replace yer porn magazine with it\n";}
								if(item[p][x]==3)
								{cout<<"press "<<x<<" to replace yer bow ("<<arrows[p][x]<<" arrows) with it\n";}
								if(item[p][x]==4)
								{cout<<"press "<<x<<" to replace yer teleporter with it\n";}
								if(item[p][x]==5)
								{cout<<"press "<<x<<" to replace yer spare medkit with it\n";}
								if(item[p][x]==6)
								{cout<<"press "<<x<<" to replace yer dead carcass with it\n";}
							}
						cout<<"press 0 if you have reconsidered and wish to just take it now\n";
						cin>>y;
							if(y==0)
							{health[p]=health[p]+5;
							cout<<name[p]<<" got 5 points of health!\nhis/her health is now "<<health[p]<<"\n";
							}
							else
							{item[p][y]=5;}
						}
					}
					if(player[p]==2)
					{	for(x=1;x<4;x++)
						{	if(item[p][x]==0)
							{	if(health[p]>=20)
								{item[p][x]=5;}
								else
								{health[p]=health[p]+5;
								cout<<name[p]<<" got 5 points of health!\nhis/her health is now "<<health[p]<<"\n";
								}
							break;
							}
						}
						if(health[p]<20)
						{health[p]=health[p]+5;
						cout<<name[p]<<" got 5 points of health!\nhis/her health is now "<<health[p]<<"\n";
						}
					}
				health_pack=0;
					while(health_pack==m[0] || health_pack==m[1] || health_pack==m[2] || health_pack==m[3] || health_pack==0)
					{health_pack=rand()%25+1;}
				}
				for(o=0;o<players;o++)
				{	if(o!=p)
					{	for(x=0;x<4;x++)
						{	if(m[p]==pornmag[o][x])
							{cout<<name[p]<<" stepped on "<<name[o]<<"'s porn magazine\nhe loses a turn observing the scantily clad babes...\n\n";
							pornmag[o][x]=0;
								if(player[p]==1)
								{player[p]=3;}
								if(player[p]==2)
								{player[p]=4;}//means that the player defined by 'p' is not going this turn
							}
						}

						if(m[p]==m[o])/*this checks to see if any player has "hit" another player by occupying the same space. If it is, then it goes into the attack phase*/
						{	if(health[o]<1)
							{	if(player[p]==1)
								{cout<<name[p]<<"\n press 1 to loot "<<name[o]<<"'s corpse\npress 2 if not\n\n";
								cin>>answer;
									if(answer==1)
									{	while(answer==1)
										{	for(x=1;x<4;x++)
											{	if(item[o][x]==1)
												{cout<<"press "<<x<<" to take his steroids\n";}
												if(item[o][x]==2)
												{cout<<"press "<<x<<" to take his porn magazine\n";}
												if(item[o][x]==3)
												{cout<<"press "<<x<<" to take his bow ("<<arrows[o][x]<<" arrows)\n";}
												if(item[o][x]==4)
												{cout<<"press "<<x<<" to take his teleporter\n";}
												if(item[o][x]==5)
												{cout<<"press "<<x<<" to take his spare medkit\n";}
												if(item[o][x]==6)
												{cout<<"press "<<x<<" to take his dead carcass\n";}
											}
										cout<<"press 4 to rip off one of his limbs and carry it around\n";
										cout<<"press 0 if you do not wish to take anything\n";
										cin>>y;
											if(y!=0)
											{	for(x=1;x<4;x++)
												{	if(item[p][x]==0)
													{cout<<"press "<<x<<" to place it in slot "<<x<<"\n";}
													if(item[p][x]==1)
													{cout<<"press "<<x<<" to replace yer steroids with it\n";}
													if(item[p][x]==2)
													{cout<<"press "<<x<<" to replace yer porn magazine with it\n";}
													if(item[p][x]==3)
													{cout<<"press "<<x<<" to replace yer bow ("<<arrows[p][x]<<" arrows) with it\n";}
													if(item[p][x]==4)
													{cout<<"press "<<x<<" to replace yer teleporter with it\n";}
													if(item[p][x]==5)
													{cout<<"press "<<x<<" to replace yer spare medkit with it\n";}
													if(item[p][x]==6)
													{cout<<"press "<<x<<" to replace yer dead carcass with it\n";}
												}
											cout<<"press 0 if you have reconsidered and do not wish to replace any of yer crap\n";
											cin>>x;
												if(x!=0 && y!=4)
												{item[p][x]=item[o][y];
												item[o][y]=0;
													if(item[p][x]==3)
													{arrows[p][x]=arrows[o][y];
													arrows[o][y]=0;
													}
												}
												if(y==4)
												{item[p][x]=6;}
											}
										cout<<"press 1 to loot more shit\npress 2 to leave\n\n";
										cin>>answer;
											if(answer==2)
											{break;}
										}
									}
								}
								if(player[p]==2)
								{	for(x=1;x<4;x++)
									{	if(item[p][x]==0)
										{	for(y=1;y<4;y++)
											{	if(item[o][y]!=0)
												{item[p][x]=item[o][y];}
											}
										}
									}
								}
							}
							else
							{weapon_speed=weapon[w[p]][0];
							weapon_strength=weapon[w[p]][1];
							opponent_weapon_speed=weapon[w[o]][0];
							opponent_weapon_strength=weapon[w[o]][1];
							fight();
								if(end==1 || end==3)
								{return;}
							}
						}
					}
				}
			}
		}
	}
return;
}

void ai_choose()
{	for(o=0;o<players;o++)
	{	if(health[o]>0)
		{weight[o]=0;
		ai_moves_away();
		}
	}
locate=health_pack;
ai_locate();
row_health=row_locate;
column_health=column_locate;
	for(o=0;o<players;o++)
	{	for(e=0;e<players;e++)
		{	if((o!=e) && (o!=p) && (e!=p) && health[o]>0 && health[e]>0)
			{	if(moves_away[o]<moves_away[e])
				{weight[e]=weight[e]+1;}
			}
		}
	}
	for(o=0;o<players;o++)
	{	if(o!=p && health[o]>0)
		{	if(weight[o]==0)
			{c=o;
			break;
			}//with c defined, now the computer knows which enemy is closest
		}
	}
	for(y=1;y<4;y++)
	{	if(item[p][y]==3)
		{break;}
	}
	if(item[p][y]!=3)
	{y=0;}
	for(x=1;x<4;x++)
	{	if(item[p][x]==1)
		{break;}
	}
	if(item[p][x]!=1)
	{x=0;}
	if(health[p]>=health[c] || (item[p][x]==1 && health[c]>(health[p]+5)) || (health[c]>(health[p]+5) && moves_away[c]>2 && item[p][y]==3))
	{row_target=row[c];
	column_target=column[c];
	ai_move();
	}
	else//if the enemy closest has higher health than the player, the player goes after the health pack
	{row_target=row_health;
	column_target=column_health;
	ai_move();
	}
return;
}

void ai_moves_away()
{locate=m[o];
ai_locate();
row[o]=row_locate;
column[o]=column_locate;
	if(p!=o && players>2)//this calculates how many moves away each player is
	{	if(row[p]>row[o])
		{row_diff[o]=row[p]-row[o];}
		if(row[o]>row[p])
		{row_diff[o]=row[o]-row[p];}
		
		if(column[p]>column[o])
		{column_diff[o]=column[p]-column[o];}
		if(column[o]>column[p])
		{column_diff[o]=column[o]-column[p];}
	moves_away[o]=row_diff[o]+column_diff[o];
	}	
return;
}

void ai_locate()
{	if(locate<=5)//this tells the computer which row each player/medkit is on
	{row_locate=1;}
	if((locate<=10) && (locate>=6))
	{row_locate=2;}
	if((locate<=15) && (locate>=11))
	{row_locate=3;}
	if((locate<=20) && (locate>=16))
	{row_locate=4;}
	if((locate<=25) && (locate>=21))
	{row_locate=5;}
	
	if(locate==1 || locate==6 || locate==11 || locate==16 || locate==21)//this tells the computer which column each player/medkit is on
	{column_locate=1;}
	if(locate==2 || locate==7 || locate==12 || locate==17 || locate==22)
	{column_locate=2;}
	if(locate==3 || locate==8 || locate==13 || locate==18 || locate==23)
	{column_locate=3;}
	if(locate==4 || locate==9 || locate==14 || locate==19 || locate==24)
	{column_locate=4;}
	if(locate==5 || locate==10 || locate==15 || locate==20 || locate==25)
	{column_locate=5;}
return;
}

void ai_move()//the computer starts by getting closer to its target in rows and then when they are in the same row, the computer gets closer by columns
{	if(row_target>row[p])
	{m[p]=m[p]+5;}
	if(row[p]>row_target)
	{m[p]=m[p]-5;}
	if(row[p]==row_target)
	{	if(column[p]>column_target)
		{m[p]=m[p]-1;}
		if(column_target>column[p])
		{m[p]=m[p]+1;}
	}
return;
}

void fight()
{	if(move==5 && skill[p]==19)
	{skill[p]=skill[p]+3;
	strength[p]=strength[p]+3;
	}
	for(x=1;x<4;x++)
	{	if(item[p][x]==1)
		{	if(player[p]==1)
			{cout<<name[p]<<"\npress "<<x<<" to use yer steroids this round of combat\npress 0 if not\n";
			cin>>i[p];
				if(item[p][i[p]]==1)
				{skill[p]=skill[p]+10;
				strength[p]=strength[p]+10;
				}
			}
			if(player[p]==2)
			{	if(health[o]>health[p] || (dead_players+2)==players)
				{i[p]=x;
				skill[p]=skill[p]+10;
				strength[p]=strength[p]+10;
				}
			}
			if(player[p]==3 || player[p]==4)
			{cout<<name[p]<<" is too busy looking at his porn mag to bother choosing whether or not to use his steroids\n";}
		break;
		}
	}
	for(x=1;x<4;x++)
	{	if(item[o][x]==1)
		{	if(player[o]==1)
			{cout<<name[o]<<"\npress "<<x<<" to use yer steroids this round of combat\npress 0 if not\n";
			cin>>i[o];
				if(item[o][i[o]]==1)
				{skill[o]=skill[o]+10;
				strength[o]=strength[o]+10;
				}
			}
			if(player[o]==2)
			{	if(health[p]>health[o] || (dead_players+2)==players)
				{i[o]=x;
				skill[o]=skill[o]+10;
				strength[o]=strength[o]+10;
				}
			}
			if(player[o]==3 || player[o]==4)
			{cout<<name[o]<<" is too busy looking at his porn mag to bother choosing whether or not to use his steroids\n";}
		break;
		}
	}
	if(strength[p]==10 && charge[p]>5)
	{	if(player[p]==1)
		{cout<<name[p]<<" press 1 to use yer berzerker power this turn\nand become MEGA AWESOME\n\n";
		cin>>mega_answer[p];
			if(mega_answer[p]==1)
			{skill[p]=skill[p]+10;
			strength[p]=strength[p]+10;
			charge[p]=charge[p]-5;
			}
		}
		if(player[p]==2)
		{	if(health[o]>health[p] || (dead_players+2)==players)
			{mega_answer[p]=1;
			skill[p]=skill[p]+10;
			strength[p]=strength[p]+10;
			charge[p]=charge[p]-5;
			}
		}
	}
	if(strength[o]==10 && charge[o]>5)
	{	if(player[o]==1)
		{cout<<name[o]<<" press 1 to use yer berzerker power this turn and become MEGA AWESOME\npress 2 if not\n\n";
		cin>>mega_answer[o];
			if(mega_answer[o]==1)
			{skill[o]=skill[o]+10;
			strength[o]=strength[o]+10;
			charge[o]=charge[o]-5;
			}
		}
		if(player[o]==2)
		{	if(health[p]>health[o] || (dead_players+2)==players)
			{mega_answer[o]=1;
			skill[o]=skill[o]+10;
			strength[o]=strength[o]+10;
			charge[o]=charge[o]-5;
			}
		}
	}
	if(skill[p]==20 && charge[p]>5)
	{	if(player[p]==1)
		{cout<<name[p]<<"\n press 2 to use yer Rogue power this turn and attack twice\npress 1 if not\n\n";
		cin>>fight_1;
		}
		if(player[p]==2)
		{	if(health[o]>health[p])
			{fight_1=2;}
		}
	charge[p]=charge[p]-5;
	}
	if(skill[o]==20 && charge[o]>5)
	{	if(player[o]==1)
		{cout<<name[o]<<"\n press 2 to use yer Rogue power this turn and attack twice\npress 1 if not\n\n";
		cin>>fight_2;
		}
		if(player[o]==2)
		{	if(health[p]>health[o])
			{fight_2=2;}
		}
	charge[o]=charge[o]-5;
	}
	if(armour_protection[o]==0)
	{skill[p]=skill[p]-2;}
	if(armour_protection[p]==0)
	{skill[o]=skill[o]-2;}
	for(x=1;x<4;x++)
	{	if(item[p][x]==6)
		{skill[o]=skill[o]-3;}
		if(item[o][x]==6)
		{skill[p]=skill[p]-3;}
	}
	if(player[p]==1 || player[p]==3)
	{cout<<name[p]<<"\n press 1 to take an offensive stance\npress 2 to take a defensive stance\npress 3 to take a neutral stance\n\n";
	cin>>answer_stance[p];
	}
	else
	{	if(health[p]>(health[o]+5))
		{answer_stance[p]=1;}
		if((health[p]+5)<health[o])
		{answer_stance[p]=2;}
		if((health[p]>health[o] && health[p]<(health[o]+5)) || (health[o]>health[p] && health[o]<(health[p]+5)))
		{answer_stance[p]=3;}
	}
	if(player[o]==1 || player[o]==3)
	{cout<<name[o]<<" press 1 to take an offensive stance\npress 2 to take a defensive stance\npress 3 to take a neutral stance\n\n";
	cin>>answer_stance[o];
	}
	else
	{	if(health[o]>(health[p]+5))
		{answer_stance[o]=1;}
		if((health[o]+5)<health[p])
		{answer_stance[o]=2;}
		if((health[p]>health[o] && health[p]<(health[o]+5)) || (health[o]>health[p] && health[o]<(health[p]+5)))
		{answer_stance[o]=3;}
	}
	for(x=0;x<fight_1;x++)
	{cout<<name[p]<<" attacks "<<name[o]<<"\n";
		if(player[p]==1 || player[p]==3)
		{cout<<name[p]<<" press 1 to stab (accurate)\npress 2 to slash (strong)\n";
		cin>>answer;
		}
		if(player[p]==2 || player[p]==4)
		{answer=rand()%2+1;}
	
		if(answer==1)
		{cout<<name[p]<<" stabs\n\n";
		weapon_speed=weapon_speed+5;
		}
		if(answer==2)
		{cout<<name[p]<<" slashes\n\n";
		weapon_strength=weapon_strength+5;
		}
	hit=rand()%skill[p]+weapon_speed-armour_skill[p];
	crit=rand()%20+1;
	def=rand()%skill[o]+opponent_weapon_speed-armour_skill[o];
	if(answer_stance[p]==1)
	{hit=hit+6;}
	if(answer_stance[p]==3)
	{hit=hit+3;}
	if(answer_stance[o]==2)
	{def=def+6;}
	if(answer_stance[o]==3)
	{def=def+3;}
		if(crit==1)
		{cout<<name[p]<<" decapitated "<<name[o]<<"\n";
		cout<<"\a\a\a\a\a\a\a\a\a";
		health[o]=0;
		} 
		else
		{	if(hit>=def)
			{wound[o]=rand()%strength[p]+weapon_strength-armour_protection[o];
				if(item[o][i[o]]==1 || mega_answer[o]==1)
				{cout<<name[p]<<" hits "<<name[o]<<"\n but since he is using MEGA AWESOME this turn, the blow does no damage\n\n";}
				else
				{	if(wound[o]>0)
					{health[o]=health[o]-wound[o];
					cout<<name[p]<<" hits "<<name[o]<<"! and wounds him/her "<<wound[o]<<" points,\n"<<name[o]<<"'s health is now "<<health[o]<<"\n\n";
					}
					else
					{cout<<name[p]<<" hit "<<name[o]<<", but hit him so weakly that he did no damage\n\n";}
				}
			}
			else
			{cout<<name[p]<<" missed "<<name[o]<<"\n\n";}
		}
		if(health[o]<1)
		{cout<<name[p]<<" hast defeated the lowly "<<name[o]<<"\n";
		cout<<"\a\a\a\a\a\a\a\a\a";
		dead_players=dead_players+1;
			if(dead_players==(players-1))
			{cout<<"\n\n"<<name[p]<<" IS MOST TRIUMPHANT!!!!!!!\n\nHE IS NOW THE NEW ARENAMAN!!!!!!!!!!!!!!\n\n";
			cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
			endgame();
			}
		break;
		}
		if(answer==1)
		{weapon_speed=weapon_speed-5;}
		if(answer==2)
		{weapon_strength=weapon_strength-5;}
	}
	if(health[o]>0 && end==0)
	{	for(x=0;x<fight_2;x++)
		{	if(player[o]==1 || player[o]==3)
			{cout<<name[o]<<" press 1 to stab (accurate)\npress 2 to slash (strong)\n";
			cin>>answer;
			}
			if(player[o]==2 || player[o]==4)
			{answer=rand()%2+1;}
	
			if(answer==1)
			{cout<<name[o]<<" stabs\n\n";
			opponent_weapon_speed=opponent_weapon_speed+5;
			}
			if(answer==2)
			{cout<<name[o]<<" slashes\n\n";
			opponent_weapon_strength=opponent_weapon_strength+5;
			}
		hit=rand()%skill[o]+opponent_weapon_speed-armour_skill[o];
		crit=rand()%20+1;
		def=rand()%skill[p]+weapon_speed-armour_skill[p];
			if(answer_stance[o]==1)
			{hit=hit+6;}
			if(answer_stance[o]==3)
			{hit=hit+3;}
			if(answer_stance[p]==2)
			{def=def+6;}
			if(answer_stance[p]==3)
			{def=def+3;}
			if(crit==1)
			{cout<<name[o]<<" decapitated "<<name[p]<<"\n";
			cout<<"\a\a\a\a\a\a\a\a\a";
			health[p]=0;
			}
			else
			{	if (hit>=def)
				{wound[p]=rand()%strength[o]+opponent_weapon_strength-armour_protection[p];
					if(item[p][i[p]]==1||(mega_answer[p]==1 && strength[p]==20))
					{cout<<name[o]<<" hits "<<name[p]<<"\n but since he is using steroids this turn, the blow does no damage\n\n";}
					else
					{	if(wound[p]>1)
						{health[p]=health[p]-wound[p];
						cout<<name[o]<<" hits "<<name[p]<<"! and wounds him/her "<<wound[p]<<" points,\n"<<name[p]<<"'s health is now "<<health[p]<<"\n\n";
						}
						else
						{cout<<name[o]<<" hit "<<name[p]<<", but hit him so weakly that he did no damage\n\n";}
					}
				}
				else
				{cout<<name[o]<<" missed "<<name[p]<<"\n\n";}
			}
			if (health[p]<1)
			{cout<<name[p]<<" art dead, killed by a lowly "<<name[o]<<"\n";
			cout<<"\a\a\a\a\a\a\a\a\a";
			dead_players=dead_players+1;
				if(dead_players==(players-1))
				{cout<<"\n\n"<<name[o]<<" IS MOST TRIUMPHANT!!!!!!!\n\nHE IS NOW THE NEW ARENAMAN!!!!!!!!!!!!!!\n\n";
				cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
				endgame();
				}
			break;
			}
		}
	}
	if(fight_1>1)
	{fight_1=1;}
	if(fight_2>1)
	{fight_2=1;}
	if(item[p][i[p]]==1)
	{skill[p]=skill[p]-10;
	strength[p]=strength[p]-10;
	item[p][i[p]]=0;
	}
	if(item[o][i[o]]==1)
	{skill[o]=skill[o]-10;
	strength[o]=strength[o]-10;
	item[o][i[o]]=0;
	}
	for(x=1;x<4;x++)
	{	if(item[p][x]==6)
		{skill[o]=skill[o]+3;}
		if(item[o][x]==6)
		{skill[p]=skill[p]+3;}
	}
	if(mega_answer[p]==1)
	{skill[p]=skill[p]-10;
	strength[p]=strength[p]-10;
	mega_answer[p]=0;
	}
	if(mega_answer[o]==1)
	{skill[o]=skill[o]-10;
	strength[o]=strength[o]-10;
	mega_answer[o]=0;
	}
	if(armour_protection[o]==0)
	{skill[p]=skill[p]+2;}
	if(armour_protection[p]==0)
	{skill[o]=skill[o]+2;}
	if(move==5 && skill[p]==22)
	{skill[p]=skill[p]-3;
	strength[p]=strength[p]-3;
	}
	if(end==2)
	{end=0;}
return;
}