#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <err.h>
#include <netinet/in.h>
#include <sysexits.h>
#include <stdbool.h>

//  -v, -?, -f, -l, -n, -w, -W, -p, -r, -s, -T, --ttl, --ip-timestamp 

typedef struct s_opt
{
    bool version;
    bool help;
    bool v;
    bool f;
    bool l;
    bool n;
    bool w;
    bool W;
    bool p;
    bool r;
    bool s;
    bool T;
    bool ttl;
    bool timestamp;
}   t_opt;


t_opt optionDefault()
{
    t_opt p;
    p.version = false;
    p.help = false;
    p.v = false;
    p.f = false;
    p.l = false;
    p.n = false;
    p.w = false;
    p.W = false;
    p.p = false;
    p.r = false;
    p.s = false;
    p.T = false;
    p.ttl = false;
    p.timestamp = false;
    return p;
}

int Socket(int domain, int type, int protocol)
{
    int sockfd = socket(domain, type, protocol);
    if (sockfd == -1)
        err(EX_OSERR, "socket");
    return sockfd;
}


int main(int argc, char * argv[])
{
    static struct option long_options[] = 
    {
        {"version", no_argument, 0, 'V'},
        {"help", no_argument, 0, '?'},
        {"ttl", required_argument, 0, 't'},
        {"iptimestamp", required_argument, 0, 'i'},
        {0, 0, 0, 0},
    };

    t_opt options = optionDefault();

    int opt;
    opt = getopt_long(argc, argv, "Vv?fl:n:W:p:r:s:T:t:i:", long_options, NULL);
    if (opt == -1)
    {
        printf("failed\n");
        return 0;
    };


    options.v = true;
    
    printf("test : %d\n", options.v);
    printf("opt %c\n", opt);
    // int sockfd = Socket(AF_INET, SOCK_RAW,IPPROTO_ICMP);
    
    // printf("%d\n", sockfd);
    
    return 0;
}