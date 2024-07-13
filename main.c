#include "window/mainloop.h"
#include <stdlib.h>
#include "conf/conf.h"
#include <unistd.h>

int main(){
    while (1)
    {
        sleep(WORK_TIME_IN_MIN);
        main_loop(BREAK_TIME_IN_MIN * 60) ;
    }
    
}