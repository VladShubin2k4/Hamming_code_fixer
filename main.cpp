#include <cstring>
#include <iostream>

short find_mistake(short& len,char* input){
    short i, mistake = 0;
    for (i=0; i<len; ++i)
        if (input[i] == '1')
            mistake ^= i+1;
    return mistake;
}

bool check_the_digits(short& len,char* input){
    for (int i = 0; i < len; ++i)  if (input[i] != '0' && input[i] != '1') return false;
    return true;
}

void out_res(short& len, short& info_pos, short& b, char* input){
    char info[128]={};
    std::cout<<"Fixed code: "<<input<<"\n";
    for (int i = 0; i < len; ++i)
        if (i+1 == b) b<<=1;
        else info[info_pos++] = input[i];
    info[info_pos] = '\0';
    std::cout<<"Informational code: "<<info<<std::endl;
}

void fix(short& mistake, short& len, char* input){
    if (mistake){
        input[mistake - 1] ^= '0' ^ '1';
        mistake = find_mistake(len,input);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    short len, mistake=0,info_pos=0, b=1;
    char input[128]={};
    std::cout<<"Enter code: ";
    std::cin>>input;
    len=static_cast<short>(strlen(input));
    mistake = find_mistake(len,input);

    if(check_the_digits(len,input)){
        fix(mistake,len,input);
        out_res(len,info_pos,b,input);
    }else std::cout<<"Invalid code"<<std::endl;
    return 0;
}
