#include <iostream>
#include <unistd.h> // Fork's library
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    pid_t pid; // general process type
    int rv;

    switch(pid = fork())
    {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            cout<<"Child: This is the child process"<<endl;
            cout<<"Child: My PID is "<<getpid()<<endl;
            cout<<"Child: My parent's PID is"<< getppid()<<endl;
            cout<<"Child: Enter my exit status:"<<endl;
            cin>>rv;
            cout<<"I am outta here"<<endl;
            exit(rv);
        default:
            cout<<"Parent: This is the parent process"<<endl;
            cout<<"Parent: My PID is "<<getpid()<<endl;
            cout<<"Parent: My child's PID is "<<pid<<endl;
            cout<<"Parent: I am now waiting for my child to exit()..."<<endl;
            wait(&rv);
            cout<<"Parent: My child's exit status is: "<<WEXITSTATUS(rv)<<endl;
            cout<<"Parent: I am outta here"<<endl;
    }
}