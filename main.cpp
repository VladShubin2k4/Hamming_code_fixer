#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>

short fastpow(short a, short n){
  if(n==0) return 1;
  if(n%2==1) return a*fastpow(a,n-1);
  short tmp=fastpow(a,n/2);
  return (tmp*tmp);
}

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

void out_res(int b,std::string& input,std::string& res){
    std::string info;
    for (int i = 0; i < 15; ++i){
        if (i+1 == b) b<<=1;
        else info += input[i];
    }
    std::cout<<info<<" ";
    res+=info;
}

void fix(short& mistake, std::string& input){
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
        for(int i=0; i<input.length(); i+=15){
            std::string tmp(input,i,15);
            parts[j++]=tmp;
            ++i;
        }
    }else{
        for(int i=15; i<input.length(); i+=16)  input.insert(i," ");
        for(int i=0; i<input.length(); i+=15){
            std::string tmp(input,i,15);
            parts[j++]=tmp;
            ++i;
        }
    }
}

void input_code(std::string& input){
    std::getline(std::cin,input);
}

int main(){
    std::ios::sync_with_stdio(false);
    SetConsoleCP(1251);SetConsoleOutputCP(1251);
    short mistake=0;
    std::string input,res;
    input_code(input);
    std::vector<std::string> parts(input.length()/15);
    prepare_code(parts,input);
    for(auto it=parts.begin();it<parts.end();++it){
        mistake = find_mistake(*it);
        if(check_the_digits(*it)){
            fix(mistake,*it);
            out_res(1,*it,res);
        }else std::cout<<"Invalid code";
    }
    std::cout<<"\nSplit in eights(8): y/n?\n";
    char c;std::cin>>c;
    if(c=='y'){
        for(int i=8; i<res.length();i+=9) res.insert(i," ");
        std::cout<<"Output the result in file: y/n?\n";
        char c;std::cin>>c;
        if(c=='y') freopen("res.txt","w",stdout);
    }
    std::cout<<"\n\n";
    for(int i=0;i<res.length();++i){
        short pow=7,code=0;
        while(res[i]!=' ' && i<res.length()) code+=fastpow(2,pow--)*static_cast<short>(res[i++]-48);
        std::cout<<static_cast<unsigned char>(code);
    }
    return 0;
}
