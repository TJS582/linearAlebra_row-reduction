#include <iostream>

#ifndef NDEBUG //NDEBUG is active basically always undefined, so therefore debug is true. Elsewise, it is false.
    constexpr bool debugOn = true;
#else 
    constexpr bool debugOn = false;
#endif
//review since I forgot; 
//  int argc 
//      -- num of command line args, including program name
//      -- gave it the [[maybe_unused]] attribute, because I mean I don't have a use for it. Right now. I also don't want to be bothered by compiler warnings on it.
//  char* argv[] 
//      -- a c-style string containing the 
int main([[maybe_unused]] int argc, char* argv[]){
    if(debugOn){
        std::cout << "version: debug \n";
    }

    for(int i=0; argv[i]!=nullptr; i++){
        std::cout << argv[i] << '\n';
    }
    
    

    return 0;
}
