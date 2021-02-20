#include <string>
#include <iostream>

int find_mistake(int& len,std::string& input){
    int i, mistake = 0;
    for (i = 0; i < len; ++i)
        if (input[i] == '1')
            mistake ^= i + 1;
    return mistake;
}

bool check_the_digits(int& len,std::string& input){
    for (int i = 0; i < len; ++i)  if (input[i] != '0' && input[i] != '1') return false;
    return true;
}

void out_res(int& len, int& b,std::string& input){
    std::string info;
    std::cout<<"Fixed code: "<<input<<"\n";
    for (int i = 0; i < len; ++i)
        if (i+1 == b) b<<=1;
        else info += input[i];

    std::cout<<"Informational code: "<<info;
}

void fix(int& mistake, int& len, std::string& input){
    if (mistake){
        input[mistake - 1] ^= '0' ^ '1';
        mistake = find_mistake(len,input);
        if (mistake) std::cout<<"Invalid code";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int len, mistake=0, b=1;
    std::string input;

    std::cout<<"Enter code: ";
    std::cin >> input;
    len = static_cast<int>(input.size());
    mistake = find_mistake(len,input);

    if(check_the_digits(len,input)){
        fix(mistake,len,input);
        out_res(len,b,input);
    }else std::cout<<"Invalid code";
    return 0;
}
