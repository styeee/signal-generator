#include <iostream>
using namespace std;

class signal
{
protected:
    char*self;
    const size_t size;
    //64 byte
public:
    //generate new signal
    void generate(const size_t divisor)
    {
        if(!divisor)exit(1);//dont make div with 0! (im serious now)

        //pay attention for i=0 !!!
        for(size_t y=0,i=0;y<size;y++)//walk around bytes
        {
            self[y]=0;//clear byte from trash

            //pay attention for i++ !!!
            for(char x=0;x<8;x++,i++)//walk around bits
                if(!(i%divisor))self[y]|=1<<x;//set bit to true
        }
    }

    //count - how many bytes // divisor - how many bits need to pass and -1
    signal(const size_t count,size_t divisor=0)//default divisor=0 its mean that the generate will be pased
        :self(new char[count]),size(count)//initialize array and size of array by contructor
    {
        if(divisor)//dont make div with 0! (but we can use it for make generation later)
            generate(divisor);//pull signal on it (if we dont passed it by make second param=0)
    }
    signal(const signal&parrent):signal(parrent.size)//copy from another signal (call previos constructor without generate)
    {for(size_t y=0,i=0;y<size;y++)self[y]=parrent.self[y];}//dont sleep there is another method on next row!
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
