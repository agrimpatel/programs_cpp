#include<iostream>
using namespace std;
 int main(){
     string questions[] = {"1.Which is fastest language among the following?",
                        "2.Which DS follows the FIFO?",
                        "3.Which DS follows the FILO?",
                        "4.Which graph is circular?"};
                        
     string options[][4] = {{"A. C++","B. C#","C. Java","D. C"},
                          {"A. stack","B. queue","C. linkedlist","D. array"},
                          {"A. stack","B. queue","C. linkedlist","D. array"},
                          {"A. Linear","B. Bar","C. Pie","D. histogram"}};
                          
     char answerKey[] = {'D','B','A','C'};
     
     int size = sizeof(questions)/sizeof(questions[0]);
     //cout<<size<<endl;
     char guess;
     int score;
     
     for(int i=0;i<size;i++){
         cout<<"********************************\n";
         cout<<questions[i]<<'\n';
         cout<<"********************************\n";
         
         for(int j=0;j<sizeof(options[i])/sizeof(options[i][0]);j++){
             cout<<options[i][j]<<'\n';
         }
         
         cin>>guess;
         guess = toupper(guess);
         
         if(guess == answerKey[i]){
             cout<<"CORRECT\n";
             score++;
         } else {
             cout<<"WRONG\n";
             cout<<"Answer:"<<answerKey[i];
         }
         
     }
      cout<<"********************************\n";
      cout<<"         ---Results---              \n";
      cout<<"********************************\n";
      cout<<"CORRECT GUESS:"<< score <<'\n';
      cout<<"Number of QUESTIONS:"<< size<<'\n';
      double n = (score/(double)size)*100;
      cout<<"SCORE:"<<n<<"%";
           
     
     
    return 0;                      
 }