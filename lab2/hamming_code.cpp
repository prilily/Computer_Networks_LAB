#include<bits/stdc++.h>
#include<string>
using namespace std;


int main()
{
    int n,p;
    vector<int> d1(4),d2(8);
    cout<<"-1.Enter data to be transmitted n=4\n";
    for(int i=0;i<4;i++)
    {
        cout<<"enter "<<i+1<<" bit";
        cin>>d1[i];
    }
    cout<<"2. Enter recieved data with len=7\n";
    for(int i=0;i<7;i++)
    {
        cout<<"enter "<<i+1<<" bit";
        cin>>d2[i];
    }

    //new char array with 
    vector<int> data(d2.size());
    data[0]=data[1]=data[3]=0;
    int iter=0;
    data[2]=d1[iter++];
    data[4]=d1[iter++];
    data[5]=d1[iter++];
    data[6]=d1[iter++];

    int count=0;
    //for p1 1,3,5,7
    for(int i=2;i<d2.size();i=i+2)
    {
        if(data[i]==1)
            count++;
    }
    if(count%2==0)
    {
        data[0]=0;
    }
    else
    {//no of 1s is odd
        data[0]=1;
    }

    count=0;
    //for p2 start 2,3,6,7 hard-code it for now
    for(int i=1;i<d2.size();i=i+4)
    {
        if(data[i]==1)
            count++;
        if(data[i+1]==1)
            count++;
    }
    if(count%2==0)
    {
        data[1]=0;
    }
    else
    {//no of 1s is odd
        data[1]=1;
    }

    //for p3 4,5,6,7
    count=0;
    for(int i=3;i<d2.size();i++)
    {
        if(data[i]==1)
            count++;
    }
    if(count%2==0)
    {
        data[3]=0;
    }
    else
    {//no of 1s is odd
        data[3]=1;
    }

    cout<<"transmitted data is:\n";
    for(int i=0;i<7;i++)
    {
        cout<<data[i];
    }
    cout<<endl;

    //now to find error in recieved bit; in d2 we have recieved data
    string c321="";
    count=0;
    //for c1 1,3,5,7
    for(int i=0;i<d2.size();i=i+2)
    {
        if(d2[i]==1)
            count++;
    }
    if(count%2==0)
    {
        c321.append("0");
    }
    else
    {//no of 1s is odd
        c321.append("1");
    }
    cout<<"\n c1 ="<<c321[0]<<endl;
    
    count=0;
    //for c2 start 2,3,6,7 hard-code it for now
    for(int i=1;i<d2.size();i=i+4)
    {
        if(d2[i]==1)
            count++;
        if(d2[i+1]==1)
            count++;
    }
    if(count%2==0)
    {
        c321.append("0");
    }
    else
    {//no of 1s is odd
        c321.append("1");
    }
     //for c3 4,5,6,7
    cout<<" c2= "<<c321[1]<<endl;
    count=0;
    for(int i=3;i<d2.size();i++)
    {
        if(d2[i]==1)
            count++;
    }
    if(count%2==0)
    {
        c321.append("0");
    }
    else
    {//no of 1s is odd
        c321.append("1");
    }
    cout<<" c3= "<<c321[2]<<endl;

    if(c321=="000")
    {
        cout<<"No error in recived code ";
        cout<<"\ncode is =";
        for(int i=0;i<d1.size();i++)
        {
            cout<<d1[i];
        }
        cout<<endl;
    }
    else
    {
        //convert c321 first reverse then to decimal then for that bit change position to 1 if 0 and vice-v
        //then change in d2 position, and cout, for 0,1,3 skip it
        reverse(c321.begin(),c321.end());
        //convert binary string to decimal]
        int index=stoull(c321,0,2)-1;
        cout<<"error at index ="<<index;
        if(d2[index]==0)
        {
            d2[index]=1;
        }
        else{
            d2[index]=0;
        }

        cout<<"actual data after correction is \n";
        for(int i=0;i<7;i++)
        {
            if(i==0||i==1||i==3)
                continue;

            cout<<d2[i];
        }
        cout<<endl;
    }

}
