#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

int main() {

    int n=0;
    int ope=0;
    int x=0;

    while (scanf("%d", &n) == 1) {

        stack<int> stack;
        queue<int> queu;
        priority_queue<int> priorityQ;

        bool Stack = true;
        bool Queu = true;
        bool PriorityQueu = true;

        for (int i = 0; i < n; ++i) {

            cin>>ope>>x;

            if(ope == 1){

                if (Stack == true){
                    stack.push(x);
                }

                if (Queu == true){
                    queu.push(x);
                }

                if (PriorityQueu == true){
                    priorityQ.push(x);
                }

            }
            else{
                if (Stack == true)
                    if (stack.empty() or stack.top() != x){
                        Stack = false;
                    }
                    else{
                        stack.pop();
                    }
                if (Queu)
                    if (queu.empty() or queu.front() != x){
                        Queu = false;
                    }

                    else{
                        queu.pop();
                    }

                if (PriorityQueu == true){
                    if (priorityQ.empty() or priorityQ.top() != x)
                        PriorityQueu = false;
                    else priorityQ.pop();
                }
            }
        }

        if (Stack and not Queu and not PriorityQueu) {
            cout <<"stack"<< endl;
        }

        else if (not Stack and Queu and not PriorityQueu) {
            cout <<"queue"<< endl;
        }

        else if(not Stack and not Queu and PriorityQueu) {
            cout <<"priority queue"<< endl;
        }

        else if (not Stack and not Queu and not PriorityQueu){
            cout <<"impossible"<< endl;
        }

        else{
            cout <<"not sure"<< endl;
        }

    }

    return 0;
}

