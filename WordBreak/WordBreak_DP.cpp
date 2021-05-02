#include <iostream>
#include<string>
#include<iterator>
#include<set>
#include<map>
using namespace std;

bool FindString(string word)
{	
    string dict[]={"ab","cd","ef"};
    int size = sizeof(dict)/sizeof(dict[0]);
    for (int i = 0; i < size; i++)
        if (dict[i].compare(word) == 0)
           return true;
    return false;
}

bool WB(string str){
	bool dp[str.length()+1];
	int size=str.size();
	for(int i=0 ; i<=str.length() ; i++)
		dp[i]=false;
	
	dp[0]=true;
	
	for (int i=1; i<=size; i++)
    {
        // if dp[i] is false, then check if current prefix can make it true.
        // Current prefix is "str.substr(0, i)"
        if (dp[i] == false && FindString( str.substr(0, i) ))
            dp[i] = true;
 
 
        // dp[i] is true, then check for all substrings starting from
        // (i+1)th character and store their results.
        if (dp[i] == true)
        {
            // If we reached the last prefix
            if (i == size)
                return true;
 
            for (int j = i+1; j <= size; j++)
            {
                // Update dp[j] if it is false and can be updated
                // Note the parameter passed to FindString() is
                // substring starting from index 'i' and length 'j-i'
                if (dp[j] == false && FindString( str.substr(i, j-i) ))
                    dp[j] = true;
 
                // If we reached the last character
                if (j == size && dp[j] == true)
                    return true;
            }
        }
    }
 
     for (int i = 1; i <= size; i++)
        cout << " " << dp[i]; 
        
    cout<<endl;
    
    // If we have tried all prefixes and none of them worked
    return false;
}

int main() 
{ 
    string a="abcdef";
    WB(a) ? cout<<"Yes\n" : cout<<"No\n";
    return 0; 
}
