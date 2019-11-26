#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template <typename T>
vector<T> dijkstra(Int s,vector<vector<pair<Int, T> > > & G,T INF){
  using P = pair<T, Int>;
  Int n=G.size();
  vector<T> d(n,INF);
  vector<Int> b(n,-1);
  priority_queue<P,vector<P>,greater<P> > q;
  d[s]=0;
  q.emplace(d[s],s);
  while(!q.empty()){
    P p=q.top();q.pop();
    Int v=p.second;
    if(d[v]<p.first) continue;
    for(auto& e:G[v]){
      Int u=e.first;
      T c=e.second;
      if(d[u]>d[v]+c){
	d[u]=d[v]+c;
	b[u]=v;
	q.emplace(d[u],u);
      }
    }
  }
  return d;
}
//INSERT ABOVE HERE
signed main(){
  Int n,m,s,t;
  cin>>n>>m>>s>>t;
  s--;t--;

  using P = pair<Int, Int>;
  vector<vector<P> > G(n),H(n);
  for(Int i=0;i<m;i++){
    Int x,y,a,b;
    cin>>x>>y>>a>>b;
    x--;y--;
    G[x].emplace_back(y,a);
    G[y].emplace_back(x,a);
    H[x].emplace_back(y,b);
    H[y].emplace_back(x,b);
  }

  const Int INF = 1e17;
  auto A=dijkstra(s,G,INF);
  auto B=dijkstra(t,H,INF);

  vector<Int> ans(n+1,INF);
  for(Int i=n-1;i>=0;i--)
    ans[i]=min(ans[i+1],A[i]+B[i]);

  Int tmp=1e15;
  for(Int i=0;i<n;i++) cout<<tmp-ans[i]<<endl;
  return 0;
}
