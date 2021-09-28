#include <iostream>
using namespace std;

class signal
{
    char*self;
    const size_t size;
    //64 byte
public:
    //generate new signal
    void generate(const size_t divisor)
    {
        for(size_t y=0,i=0;y<size;y++,i++)//walk around bytes
        {
            self[y]=0;//clear byte from trash
            
            for(char x=0;x<8;x++)//walk around bits
                if(!(i%divisor))self[y]|=1<<x;//set bit to true
        }
    }

    //count - how many bytes // divisor - how many bits need to pass and -1
    signal(const size_t count,size_t divisor=0)    :size(count)
    {
        self=new char[size];//create new bytes array
        if(!divisor)return;//dont make div with 0! (but we can use it for make generation later)
        generate(divisor);//pull signal on it
    }
    ~signal()//if u want resize then delete and create new
    {delete[]self;}//care abaout remove array!

    void out()
    {
        for(size_t y=0;y<size;y++)//walk around bytes
        {
            for(char x=0;x<8;x++)//walk around bits
                cout<<bool(self[y]&1<<x);
            cout<<endl;
        }
    }

    //send these bytes to some controller
    const size_t send(const size_t how);

    const char*const raw()//just return bytes
    {return self;}

    //...
};

//demo
int main()
{
        cout<<"enter count of bytes:";
        size_t f;
        cin>>f;
    signal steps(f);

    while(true)
    {
            cout<<"enter signal divisor:";
            size_t i;
            cin>>i;
        steps.generate(i);
        steps.out();
    }

    steps.~signal();
    return 0;
}
