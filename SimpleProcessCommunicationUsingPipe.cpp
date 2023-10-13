#include <iostream>
#include <unistd.h>
using namespace std;
int main(void)
{
    int pfds[2];
    char buf[30];

    pipe(pfds);

    if (!fork())
    {
        cout<<"CHILD: writing to the pipe"<<endl;
        write(pfds[1], "test", 5);
        cout<<"CHILD: exiting"<<endl;
        exit(0);
    }
    else
    {
        cout<<"PARENT: reading from pipe"<<endl;
        read(pfds[0], buf, 5);
        cout<<"PARENT: read "<<buf<<endl;
        wait(NULL);
    }
}