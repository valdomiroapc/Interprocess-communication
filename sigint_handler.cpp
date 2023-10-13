#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
using namespace std;
void sigint_handler(int sig)
{
    const char msg[] = "Ahhh!! SIGINT!\n";
    write(0, msg, sizeof(msg));
}

int main(void)
{
    char s[200];
    struct sigaction sa = {
        .sa_handler = sigint_handler,
        .sa_flags = 0, // or SA_RESTART
        .sa_mask = 0,
    };

    if (sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }

    cout<<"Enter a string"<<endl;

    if (fgets(s, sizeof(s), stdin) == NULL)
    {
        perror("fgets");
    }
    else{
        cout<<"You entered"<<s<<endl;
    }
    return 0;
}