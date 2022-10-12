#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int n){
	if(st.empty()){
		st.push(n);
		return;
	}
	int var = st.top();
	st.pop();
	insertAtBottom(st, n);
	st.push(var);
}

void reverseRecurse(stack<int> &st){
	if(st.empty()){
		return ;
	}
	int var = st.top();
	st.pop();
	reverseRecurse(st);
	insertAtBottom(st, var);

}

void printStack(stack<int> st){
	// cout << "===================================>" << endl;
	// cout << "|" << " ";
	while(!st.empty()){
		cout << "|\t" << st.top() << "\t|" << endl;
		st.pop();
	}
	// cout << endl;
	cout << "_______" << endl << endl;
}

int main(){
	int n;cin >> n;
	stack<int> st;
	for(int i=n;i>0;i--){
		int x;cin >> x;
		st.push(x);
	}
	printStack(st);
	reverseRecurse(st);
	printStack(st);

}
