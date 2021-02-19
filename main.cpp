#include <cstring>
#include <iostream>

char input[1024];
int find_mistake(int& len){
    int i, mistake = 0;
    for (i = 0; i < len; i++)
        if (input[i] == '1')
            mistake ^= i + 1;
    return mistake;
}

bool check_the_digits(int& len){
    for (int i = 0; i < len; ++i)  if (input[i] != '0' && input[i] != '1') return false;
    return true;
}

void out_res(int& len, int& info_pos, int& b){
    char info[1024];
    std::cout<<"Fixed code: "<<input<<std::endl;
    for (int i = 0; i < len; ++i)
        if (i+1 == b) b<<=1;
        else info[info_pos++] = input[i];
    info[info_pos] = '\0';
    std::cout<<"Informational code: "<<info<<std::endl;
}

void fix(int& mistake, int& len){
    if (mistake){
        input[mistake - 1] ^= '0' ^ '1';
        mistake = find_mistake(len);
        if (mistake) std::cout<<"Invalid code"<<std::endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int len, mistake = 0,info_pos = 0, b = 1;

    std::cout<<"Enter code: ";
    std::cin >> input;
    len = static_cast<int>(strlen(input));
    mistake = find_mistake(len);

    if(check_the_digits(len)){
        fix(mistake,len);
        out_res(len,info_pos,b);
    }else std::cout<<"Invalid code"<<std::endl;
    return 0;
}
