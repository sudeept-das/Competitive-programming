#include <bits/stdc++.h>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
int calculateMinimumSession(int numOfBankers, int numOfParticipants, vector<vector<int>> bankersPreferences, vector<vector<int>> participantsPreferences) {
    // Participant's code will go here
    map<int,int> mpb,mpp;
    int i,j,ta,k;
    for(i=0;i<numOfBankers;i++)
    {
        mpb[i+1]+=bankersPreferences[i].size();
        for(j=0;j<bankersPreferences[i].size();j++)
        {
            ta=0;
            for(k=0;k<participantsPreferences[(bankersPreferences[i][j])-1].size();k++)
            {    
                if(participantsPreferences[bankersPreferences[i][j]-1][k]==i+1)
                {
                    ta=1;
                    break;
                }
            }
            if(ta==0)
            {
                mpp[bankersPreferences[i][j]]++;
            }
        }
    }
    for(i=0;i<numOfParticipants;i++)
    {
        mpp[i+1]+=participantsPreferences[i].size();
        for(j=0;j<participantsPreferences[i].size();j++)
        {
            int ta=0;
            for(k=0;k<bankersPreferences[participantsPreferences[i][j]-1].size();k++)
            {    
                if(bankersPreferences[participantsPreferences[i][j]-1][k]==i+1)
                {
                    ta=1;
                    break;
                }
            }
            if(ta==0)
            {
                mpb[participantsPreferences[i][j]]++;
            }
        }
    }
    int ans = -1;
    map<int,int>::iterator it;
    for (it=mpb.begin();it!=mpb.end();it++)
    {
        ans=max(ans,it->second);
    }
    
    for (it=mpp.begin();it!=mpp.end();it++)
    {
        if(ans<it->second)
        {
            ans=it->second;
            
        }
    }
    return ans;
}
vector<string> split(const string& str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

vector<int> splitStringToInt(const string& str, char delim) {
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<int> vec) {
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

void printVector(vector<string> vec) {
    for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    int numOfBankers, numOfParticipants;
    vector<vector<int>> bankersPreferences, participantsPreferences;

    cin >> numOfBankers;

    string bankersPreferencesStr;
    cin >> bankersPreferencesStr;
    vector<string> bankersPreferencesVecByComma = split(bankersPreferencesStr, ',');

    for (vector<string>::const_iterator i = bankersPreferencesVecByComma.begin(); i != bankersPreferencesVecByComma.end(); ++i) {
        vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, '&');
        bankersPreferences.push_back(bankerPreferenceVecByAnd);
    }

    string participantsPreferencesStr;
    cin >> numOfParticipants;
    cin >> participantsPreferencesStr;
    vector<string> participantsPreferencesVecByComma = split(participantsPreferencesStr, ',');

    for (vector<string>::const_iterator i = participantsPreferencesVecByComma.begin(); i != participantsPreferencesVecByComma.end(); ++i) {
        vector<int> participantPreferenceVecByAnd = splitStringToInt(*i, '&');
        participantsPreferences.push_back(participantPreferenceVecByAnd);
    }
    int result = calculateMinimumSession(numOfBankers, numOfParticipants, bankersPreferences, participantsPreferences);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
