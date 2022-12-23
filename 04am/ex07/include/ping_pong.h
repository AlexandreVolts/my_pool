#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

typedef struct ping {
    int pong;
    struct ping_2 {
        struct pong_2 {
            char ping;
            char pong;
        } pong;
        char ping;
    } ping;
} ping_t;

#endif