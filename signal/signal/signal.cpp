#include <iostream>
using namespace std;
#include <bitset>

class signal
{
    char*self;
    const size_t size;
    //64 byte
public:
    //generate new signal
    void generate(const size_t divisor)
    {
         size_t i=0;
        for(size_t y=0;y<size;y++)//walk around bytes
        {
             self[y]=0;//clear byte from trash
            for(char x=0;x<8;x++)//walk around bits
            {
                if(i%divisor);else
                self[y]|=1<<x;//set bit to true
                i++;
            }
        }
    }

    //count - how many bytes // divisor - how many bits need to pass and -1
    signal(const size_t count,const size_t divisor)    :size(count)
    {
        if(!divisor)exit(1);//dont make div with 0!
        self=new char[count];//create new bytes massiv
        generate(divisor);//pull signal on it
    }
    ~signal()//if u want resize then delete and create new
    {delete[]self;}//care abaout remove massive!

    void out()
    {
        for(size_t y=0;y<size;y++)//walk around bytes
        {
            for(char x=0;x<8;x++)//walk around bits
                cout<<bool(self[y]&1<<x);
            cout<<endl;
        }
    }

    const char*const raw()//just return bytes
    {return self;}
};

//demo
int main()
{
    cout<<"enter count of bytes:";
    size_t f;
    cin>>f;

    while(true)
    {
        cout<<"enter signal divisor:";
        size_t i;
        cin>>i;
        signal steps(f,i);
        steps.out();
    }

    return 0;
}