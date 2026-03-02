#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    set<string>st;
    string s;
    for (int i=0;i<n;i++){
        cin>>s;
        st.insert(s);
    }
    while(m--){
        cin>>s;
        bool ok=false;
        for (int i=0;i<s.size();i++){
            char old=s[i];
            for (char c='a';c<='c';c++) {
                if (c==old)continue;
                s[i]=c;
                if(st.count(s)){
                    ok=true;
                    break;
                }
            }
            s[i]=old;
            if(ok) break;
        }
        if (ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}