#include "homework.hpp"
#include <stack>
#include <set>

string checkCountCharMultipleOfK(string regularExpression, char required, int k){
    
    if (k == 0){
        return "ERROR";
    }
    
    stack<set<int>> dividers;
    for(int i = 0; i < regularExpression.length(); i++){
        if (regularExpression[i] == '+'){
            if (dividers.empty()){
                return "ERROR";
            }
            set<int> reg1 = dividers.top();
            dividers.pop();
            if (dividers.empty()){
                return "ERROR";
            }
            set<int> reg2 = dividers.top();
            dividers.pop();
            for(set<int>::iterator i = reg1.begin(); i!=reg1.end(); i++){
                reg2.insert(*i);
            }
            dividers.push(reg2);
        } else {
            if (regularExpression[i] == '*'){
                if (dividers.empty()){
                    return "ERROR";
                }
                set<int> reg = dividers.top();
                dividers.pop();
                for(set<int>::iterator i = reg.begin(); i!=reg.end(); i++){
                    for(int g = 2; g <= k; g++){
                        reg.insert(((*i)*g) % k);
                    }
                }
                dividers.push(reg);
            } else {
                if (regularExpression[i] == '.'){
                    if (dividers.empty()){
                        return "ERROR";
                    }
                    set<int> reg1 = dividers.top();
                    dividers.pop();
                    if (dividers.empty()){
                        return "ERROR";
                    }
                    set<int> reg2 = dividers.top();
                    dividers.pop();
                    set<int> newReg;
                    for(set<int>::iterator i = reg1.begin(); i!=reg1.end(); i++){
                        for(set<int>::iterator g = reg2.begin(); g!=reg2.end(); g++){
                            newReg.insert( ((*i) + (*g)) % k);
                        }
                    }
                    dividers.push(newReg);
                } else {
                    if (regularExpression[i] == required){
                        set<int> reg;
                        reg.insert(1 % k);
                        dividers.push(reg);
                    } else {
                        set<int> reg;
                        reg.insert(0 % k);
                        dividers.push(reg);
                    }
                }
            }
        }
    }
    
    if (dividers.empty()){
        return "ERROR";
    }
    set<int> reg = dividers.top();
    dividers.pop();
    if (!dividers.empty()){
        return "ERROR";
    }
    if (reg.find(0) != reg.end()){
        return "YES";
    }
    return "NO";
}
