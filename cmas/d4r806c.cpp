#include <bits/stdc++.h>
#define endl '\n'
#define forn(i,n) for(int i=0;i<int(n);i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define fore(obj) for(const auto& element: obj)
//
#include <string>
//
using namespace std;
 
void solution(){
    //solution goes here
    int n;
    cin >> n;
    int cypher[n];
    forn(i,n) {
        cin >> cypher[i];
    }
    int op;
    int res;
    string mov;
    int m;
    int out;
    
    forn(i,n) {
        op = 0;
        res = 0;
        out = 0;
        cin >> m;
        getline(cin,mov);
        int res = 0;
        
        forr(i,0,m) {
            if(mov[i] == 'U') op--;
            else if(mov[i] == 'D') op++;
        }
        res = cypher[i] + op;
        if(res < 0) out = (res%10) + 10;
        else out = res%10;
        if(out == 10) out = 0;
        cout << out << ' ';
    }
    cout << endl;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	//T=1;
    cin>>T;
    
	while(T--){
		solution();
	}
	return 0;
}