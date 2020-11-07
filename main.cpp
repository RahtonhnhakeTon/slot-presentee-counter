#include <bits/stdc++.h>
using namespace std;

class timee{
    public:
    int HH,MM,SS;
    timee(){
        HH=0;
        MM=0;
        SS=0;
    }
    timee(string s){
        HH=(s[0]-48)*10+(s[1]-48);
        MM=(s[3]-48)*10+(s[4]-48);
        SS=(s[6]-48)*10+(s[7]-48);
    }
    bool operator >=(timee y){
        if(HH>y.HH)
            return true;
        else if(HH==y.HH && MM>y.MM)
            return true;
        else if(MM==y.MM && SS>y.SS)
            return true;
        else return false;
    }
    bool operator <=(timee y){
        if(HH<y.HH)
            return true;
        else if(HH==y.HH && MM<y.MM)
            return true;
        else if(MM==y.MM && SS<y.SS)
            return true;
        else return false;
    }
};
class employee:public timee{
    public:
    timee in,out;
    employee(){
        timee in,out;
    }
};

int main()
{
    int N,c1,c2,count=0;
    string line;
    cin>>N;
    timee SlotIN,SlotOUT;
    employee x[N];
    cin>>ws;
    for(int i=0;i<N;i++){
        getline(cin,line);
        c1=line.find_first_of(',');
        c2=line.find_last_of(',');
        x[i].in = timee(line.substr(c1+1,8));
        x[i].out= timee(line.substr(c2+1));
    }
    getline(cin,line);
    SlotIN=timee(line);
    getline(cin,line);
    SlotOUT=timee(line);
    for(int i=0;i<N;i++){
        
        if(x[i].in>=SlotIN && x[i].out<=SlotOUT)
            count++;
    }
    cout<<count;
}
