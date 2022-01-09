#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <cctype>
#include <fstream>
using namespace std;


map<string,string>x;
map<string,string>::iterator it;
string q,a;
fstream bot("chat.txt");

void read(){
  fstream bot("chat.txt");
  if(bot.is_open()){
   while(getline(bot,q)){
     getline(bot,a);
     x[q]=a;
    }
    bot.close();
  }
  else{
    cout<<"helllo";
  }
}

string cheak(string q){
 int num=0;
 for(it=x.begin() ; it!=x.end() ; it++){
   int count=0;
   for(int i=0 ; i<(*it).first.size() ; i++){
     for(int k=0 ; k<q.size() ; k++){
       if((*it).first[i] == q[k]){
         count++;
       }
       if(count > num){
         num=count;
         a=(*it).first;
       }
      }
    }
  }
 return a;
}

string autocorrect(string q){
 for(int i=0 ; i<q.size() ; i++){
   q[i]=tolower(q[i]);
 }
 return q;
}

void see();

void add(){
  bot.open("chat.txt",ios::app);
  cout<<endl<<"Enter the question: ";
  scanf("\n");
  getline(cin,q);
  q=autocorrect(q);
  if(x[q]==""){
   cout<<"Enter the ansewr of the question: ";
   scanf("\n");
   getline(cin,a);
   a=autocorrect(a);
   bot<<q<<endl<<a<<endl;
   bot.close();
   x.clear();
   read();
   cout<<endl;
  }
  else{
    cout<<"This question maight be in the system please cheak the quetions in the system"<<endl;
    see();
  }
}

void see(){
  if(x.size() == 0){
    read();
    cout<<endl;
    cout<<"There is no question in the system please add a question"<<endl;
    add();
    read();
  }
  else{
    cout<<endl;
    for(it=x.begin() ; it!=x.end() ; it++){
      cout<<"Qustion: "<<(*it).first<<endl;
      cout<<endl;
    }
  }
}

void chat(){
  cout<<endl;
  cout<<"If you want to end the chat type 0"<<endl<<endl;
  cout<<"The chat is open you can start:"<<endl;
  cout<<"=============================="<<endl;
  again:
  scanf("\n");
  getline(cin,q);
  if(q != "0"){
    q=cheak(q);
    q=autocorrect(q);
    if(x[q]!=""){
     cout<<"\t\t\t"<<x[q]<<endl;
      goto again;
    }
    else{
      cout<<"The system don't find the ansewr of your question pleas add the qustion again and add the ansewr"<<endl;
     add();
     read();
     cout<<"The chat is open you can start again:"<<endl;
     goto again;
    }
 }
 else{
   cout<<"the chat is end"<<endl;
   cout<<"==============="<<endl;
    }
  cout<<endl;
}

int main(){
 fstream bot("chat.txt");
 read();
 cout<<endl<<"Welocom to chatbot programe\n\n";
 start:
 int ans;
 cout<<"1)Add question and ansewr"<<endl<<"2)See the questions"<<endl<<"3)Chat with the system"<<endl;
 cout<<"choice: ";
 cin>>ans;
 if(ans == 1){
   add();
 }
 else if(ans == 2){
   see();
 }
 else if(ans == 3){
   chat();
 }
 goto start;
}
