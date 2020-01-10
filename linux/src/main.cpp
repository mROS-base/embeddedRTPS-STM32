# include <asoa/driver/os.h>
#include <asoa/driver/rtps.h>
#include <unistd.h>
#include <iostream>

// Callback on message from STM32 
void callback(const uint8_t* msg, const uint32_t len, void* arg){
    std::cout << "Received message from STM32 with len:" << std::to_string(len) << std::endl;

    for(uint32_t i = 0; i < len; i ++){
        std::cout << std::to_string(i) << " : " << std::to_string(msg[i]) << std::endl;
    }

    std::cout << std::endl;
}


// Create Subscriber to listen to messages form the STM32
int main(){
    
    rtps_init();
    std::cout << "Created subscriber on Topic: Test : Test" << std::endl;

    rtps_subscriber_t* sub = rtps_create_subscriber("TEST","TEST",nullptr,&callback);
    
    std::cout << "Looping main thread and waiting for message from STM32." << std::endl;
    
    while(true){
        usleep(1000);
    }
    
    return 0;
}

