#include <string>
#include <iostream>
#include <vector>
//#include <cstdlib>

int find_mistake(std::string& input){
    int i, mistake = 0;
    for (i = 0; i < 15; ++i)
        if (input[i] == '1')
            mistake ^= i + 1;
    return mistake;
}

bool check_the_digits(std::string& input){
    for (int i = 0; i < 15; ++i)  if (input[i] != '0' && input[i] != '1') return false;
    return true;
}

void out_res(int b,std::string& input){
    std::string info;
    for (int i = 0; i < 15; ++i){
        if (i+1 == b) b<<=1;
        else info += input[i];
    }
    std::cout<<info<<" ";
}

void fix(int& mistake, std::string& input){
    if (mistake){
        input[mistake - 1] ^= '0' ^ '1';
        mistake = find_mistake(input);
        if (mistake) std::cout<<"Invalid code";
    }
}

void prepare_code(std::vector<std::string>& parts, std::string& input){
    char cmd;
    int j=0;
    std::cout<<"Are there any separating spaces?\n";std::cin>>cmd;
    if(cmd=='y'){
        for(int i=0; i<input.size(); i+=15){
            std::string tmp(input,i,15);
            parts[j++]=tmp;
            ++i;
        }
    }else{
        for(int i=15; i<input.size(); i+=16)  input.insert(i," ");
        for(int i=0; i<input.size(); i+=15){
            std::string tmp(input,i,15);
            parts[j++]=tmp;
            ++i;
        }
    }
}

void input_code(std::string& input){
    std::cout<<"Enter code: ";
    std::getline(std::cin,input);
}

int main(){
    std::ios::sync_with_stdio(false);
    int mistake=0;
    std::string input;
    input_code(input);
    std::vector<std::string> parts(input.size()/15);
    prepare_code(parts,input);

    //freopen("res.txt","w",stdout);
    for(auto it=parts.begin();it<parts.end();++it){
        mistake = find_mistake(*it);
        if(check_the_digits(*it)){
            fix(mistake,*it);
            out_res(1,*it);
        }else std::cout<<"Invalid code";
    }
    return 0;
}
