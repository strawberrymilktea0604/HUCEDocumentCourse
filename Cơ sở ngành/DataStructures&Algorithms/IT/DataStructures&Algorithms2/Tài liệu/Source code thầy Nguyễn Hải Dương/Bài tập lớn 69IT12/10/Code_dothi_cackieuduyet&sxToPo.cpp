#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#define N 100
using namespace std;
bool visited[N];
int indegree[N];
int n,m;
vector<int> arr[N];
bool Invalid(int a){
    return (a<0 || a>=n);
}
void Input(bool directed){
    int a,b;
    cout<<"Nhap so dinh va so canh:";cin>>n>>m;
    for(int i=0;i<m;i++){
        do{
          cout<<"Canh "<<i+1<<":";  
          cin>>a>>b;
        } while(Invalid(a) || Invalid(b));
        arr[a].push_back(b);
        if(directed==false)
           {arr[b].push_back(a);}
        indegree[b]++;            
    }
}
void DFS(int start){
    if(Invalid(start)){
        cout<<"out of graph";
        return;
    }
    stack<int> st;
    st.push(start);
    cout<<"DFS:";
    while(!st.empty()){
        int u=st.top();
        st.pop();
        if(!visited[u]){
            visited[u]=true;
            cout<<u<<' ';
            for(int i=arr[u].size()-1;i>=0;i--){
                int v=arr[u][i];
                if(!visited[v]){
                  st.push(v);}
            }
        }
    }
}
void BFS(int start){
    if(Invalid(start)){
        cout<<"out of graph";
        return;
    }
    queue<int> q;
    visited[start]=true;
    q.push(start);
    cout<<"BFS:";
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int i=0;i<arr[u].size();i++){
                int v=arr[u][i]; 
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
    }
}
void Topo(int n){
    queue<int> q;
    vector<int> var;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        var.push_back(u);
        for(int i=0;i<arr[u].size();i++){
            int v=arr[u][i];
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
            
        }
    }
    if(var.size()<n){
        cout<<"cycle error";
    }
    else{
        cout<<"Topo:";
        for(int i=0;i<n;i++){
            cout<<var[i]<<' ';
        }
    }
    
}
void Output(){
    for(int i=0;i<n;i++){
      cout<<"Dinh "<<i<<":";
      for(int j=0;j<arr[i].size();j++){
          cout<<arr[i][j]<<' ';
      }
      cout<<endl;
    }
}
void ResetVisited(){
    for(int i=0;i<n;i++) visited[i]=false;
}
void Delete(int n){
    for(int i=0;i<n;i++){
        arr[i].clear();
    }
}
int main()
{
    int c;
    bool directed;
    do{
        cout<<endl;
        cout<<"1.input"<<endl;
        cout<<"2.DFS"<<endl;
        cout<<"3.BFS"<<endl;
        cout<<"4.Clear"<<endl;
        cout<<"5.Topo"<<endl;
        cout<<"6.List"<<endl;
        cout<<"0.end"<<endl;
        cout<<"pick:";cin>>c;
        switch(c){
            case 0:break;
            case 1:
              cout<<"Vo huong (0) / Co huong (1):";cin>>directed;
              Input(directed);
              break;
            case 2:
              ResetVisited();
              DFS(0);break;
            case 3:
              ResetVisited();
              BFS(0);break;
            case 4:Delete(n);break;
            case 5:
              if(directed){
                Topo(n);
              }
              else{
                  cout<<"Do thi vo huong";
              }
              break;
            case 6:Output();break;
        }
    }while(c);

    return 0;
}