//Name - SHEELAJ BABU
//Roll- 180101041
//BRANCH-->CSE
#include <iostream>
#include<vector>
using namespace std;
int main()
{
    long long int i,j,k,l,n,m=INT_MAX,mini,ma=0;
    string s[100],st,ch,sc="",result,fs,maxi,rs="";
    vector<string>ss;
    vector<string>sp;
    cout<<"Enter Number of productions :";
    cin>>n;
    cout<<"Enter the grammar productions\n";
    for(i=1;i<=n;i++)//Input the grammar productions
    {
        cin>>s[i];
    }
    for(i=1;i<=n;i++)//Store the right hand side of grammar in a temporary vector of string
    {
        st=s[i];
        sc="";

        for(j=0;j<st.length();j++)
        {
            if(i==1)
            {
                fs=st[0];
            }
            if(st[j]=='=')
            {
               l=j;
            }
        }

        if(i==1)
        {

        for(k=l+1;k<st.length();k++)
        {
            if(st[k]=='|')
            {
                ss.push_back(sc);
                sc="";
            }
            if(st[k]!='|')
            {
                ch=st[k];
                sc=sc+ch;
            }

        }
        ss.push_back(sc);
        }



    }

    for(k=0;k<ss.size();k++)//Find the production with minimum length
    {
        mini=ss[k].size();
        m=min(m,mini);
        maxi=ss[k];

    }
    for (int i=0; i<m; i++)//Match the common prefix in the left hand side of the productions.
    {

        char current = ss[0][i];

        for (int j=1 ; j<ss.size(); j++)
        {
            if (ss[j][i] != current)
            {
                   break;
            }
             result.push_back(current);//Store the common prefix into other vector of string
        }

    }

    for(j=0;j<ss.size();j++)//Store the uncommon string into other vector of string
    {
        maxi=ss[j];

    for(k=0;k<maxi.length();k++)
    {


        if(k>=result.length())
        {
            rs=rs+maxi[k];


        }

    }
            if(j!=ss.size()-1)
            {
                  rs=rs+'|';
            }
    }
    cout<<"..........................................................................................................\n";
    cout<<fs<<"="<<result<<fs<<"'"<<endl;          
	 //print the final productions with removed left factoring.
    cout<<fs<<"'"<<"="<<rs<<endl;

    for(i=2;i<=n;i++)
    {
        cout<<s[i]<<endl;
    }
    cout<<"..........................................................................................................\n";
    return 0;
}
