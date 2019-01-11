/*Assignment:1
  QuestionNumber:2
  Statement:To check whether a given string is accepted by a given NFA.
  @author:Adil Mahmood(510816073)
*/
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

bool result[MAX]={false};//Hash table to mark all the states reached after traversing all the possible paths in
                         //the graph using the given input string.


void checkNFA(vector<pair<int,int> >v[],int curr_state,string str, int pos)
{
    if(pos==str.length())//If the given string is fully traversed, we save the state we reached after the traversal
          result[curr_state]=true;

    for(int i=0;i<v[curr_state].size();i++)//For all edges from the current state, follow edges which matches the input symbol
    {
        if(v[curr_state][i].first==str[pos]-'a')
             (checkNFA(v,v[curr_state][i].second,str,++pos));//Traverse the graph with the next input symbol
    }


}

int main()
{
    int no_of_states;
    int no_of_symbols;
    int start_state;
    int no_of_final_states;
    int final_state[MAX];
    string str;

    cout<<"No of states:: ";
    cin>>no_of_states;
    cout<<"No of Symbols:: ";
    cin>>no_of_symbols;
    cout<<"Start State:: ";
    cin>>start_state;
    cout<<"No of final states:: ";
    cin>>no_of_final_states;
    cout<<"Final States are:: ";
    for(int i=0;i<no_of_final_states;i++)
        cin>>final_state[i];

    cout<<"Enter the string to be checked:: ";
    cin>>str;

    vector<pair<int,int> >v[no_of_states];
    cout<<"Enter the state transitions:: \n";
    for(int i=0;i<no_of_states;i++)//Creating a graph using vector of pairs
    {
        int num;
        cout<<"Enter the no of transitions from state"<<" Q"<<i<<":: ";
        cin>>num;
        while(num--)
        {
            char inp;
            int next_state;
            cout<<"Enter the input symbol and the next state:: ";
            cin>>inp>>next_state;
            v[i].push_back(make_pair(inp-'a',next_state));//First element of the pair corresponds to input symbol,
        }                                                 //Second element corresponds to the next state
    }

    for(int i=0;i<no_of_states;i++)
    {
        cout<<"Q"<<i<<":: ";
        for(int j=0;j<v[i].size();j++)
        {
            cout<<"("<<v[i][j].first<<" "<<v[i][j].second<<")";
        }
        cout<<endl;
    }
    checkNFA(v,start_state,str,0);
    int flag=0;
    for(int i=0;i<no_of_final_states;i++)
    {

        if(result[final_state[i]])
        {
            flag=1;
            break;
        }
    }
    if(flag)
        cout<<"Congratulations!!!!! The given string is accepted\n";
    else
        cout<<"The given string is not accepted\n";


}
