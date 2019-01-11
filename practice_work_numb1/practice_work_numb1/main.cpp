#include <iostream>
#include "homework.hpp"

bool passedTests();

int main(int argc, const char * argv[]) {
    
    if (!passedTests()){
        return 1;
    }
    
    cout << "Введите регулярку в обратной польской нотации, символ и число K:" << endl;
    string reg;
    char sim;
    int cnt;
    cin >> reg >> sim >> cnt;
    cout << checkCountCharMultipleOfK(reg,sim, cnt);
    
    return 0;
}

bool passedTests(){
    if (checkCountCharMultipleOfK("ab+c.*",'a', 2) != "YES"){
        cout << "test 1 didnt passed" << endl;
        return false;
    }
    if (checkCountCharMultipleOfK("ab+c.aba.*.bac.+.+*",'a', 2) != "YES"){
        cout << "test 2 didnt passed" << endl;
        return false;
    }
    if (checkCountCharMultipleOfK("xx.*x.",'x', 2) != "NO"){
        cout << "test 3 didnt passed" << endl;
        return false;
    }
    if (checkCountCharMultipleOfK("ab+c.aba.*.bac.+.+*",'a', 2) != "YES"){
        cout << "test 4 didnt passed" << endl;
        return false;
    }
    if (checkCountCharMultipleOfK("acb..bab.c.*.ab.ba.+.+*a.",'a', 2) != "YES"){
        cout << "test 5 didnt passed" << endl;
        return false;
    }
    if (checkCountCharMultipleOfK("xx.x+",'x', 3) != "NO"){
        cout << "test 6 didnt passed" << endl;
        return false;
    }
    if (checkCountCharMultipleOfK("aa.a.xa.+",'a', 2) != "NO"){
        cout << "test 7 didnt passed" << endl;
        return false;
    }
    if (checkCountCharMultipleOfK("ab+.",'a', 9) != "ERROR"){
        cout << "test 8 didnt passed" << endl;
        return false;
    }
    if (checkCountCharMultipleOfK("aba.∗.a.∗ab1+..",'a', 0) != "ERROR"){
        cout << "test 9 didnt passed" << endl;
        return false;
    }
    if (checkCountCharMultipleOfK(".aba.∗.a.∗ab1+..",'a', 2) != "ERROR"){
        cout << "test 10 didnt passed" << endl;
        return false;
    }
    return true;
}

