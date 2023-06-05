#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	string s, temp; cin >> s >> temp;
	stack<char> st;
	for(int i=0; i<s.size(); i++) {
		st.push(s[i]);

		if(st.size()>=temp.size() && st.top() == temp[temp.size()-1]) {
			string ss="";
			for(char c : temp)
				ss += st.top(); st.pop();
			
			reverse(ss.begin(), ss.end());
			if(temp != ss)
				for(char c : ss)
					st.push(c);
		}
	}
	if(!st.size()) { cout << "FRULA"; return 0; }
	string v="";
	while(st.size()) {
		v += st.top(); st.pop();
	}

	for(int i=v.size()-1; i>=0; i--)
		cout << v[i];
}