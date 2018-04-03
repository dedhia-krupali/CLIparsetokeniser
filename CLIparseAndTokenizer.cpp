#include <iostream>
#include <string>

using namespace std;

int main()
{
    string userCommand;
    string splitCom;
    string splitOpt;
    string splitArg;
    int token = 0;
    
    string com1;
    string com2;
    string com3;
    
    cout << "\nEnter the command or QUIT to exit the program." << endl;
    cout << "<<";
    getline(cin,userCommand);
    
    while(userCommand != "QUIT") {
        int type=1;
        long fullstop = userCommand.find('.');
        long lessthan = userCommand.find('<');
        long greaterthan = userCommand.find('>');
        long dash = userCommand.find('-');
        
        int pipec = 0;
        
        for(int i = 0; i < userCommand.length(); i++) {
            if(userCommand.at(i) == '|') {
                pipec++;
            }
        }
        
        if(fullstop > -1 || dash > -1) {
            type = 1;
        }
        if(lessthan > -1 || greaterthan > -1) {
            type = 2;
        }
        
        if(pipec == 1) {
            type = 3;
        }
        
        if(lessthan > -1 && greaterthan > -1) {
            type = 4;
        }
        
        
        
        long commandSize = userCommand.length();
        long posOfLess2 = 0;
        
        
        switch(type)
        {
            case 1:
                token = 0;
                if(dash == -1 && fullstop == -1) {
                    splitCom = userCommand.substr(0, dash);
                    
                    cout << "Command: " << splitCom << "\n";
                    token ++;
                } else if(fullstop == -1){
                    
                    splitCom = userCommand.substr(0, dash);
                    
                    cout << "Command: " << splitCom << "\n";
                    token++;
                    
                    splitOpt = userCommand.substr(dash, fullstop - dash);
                    
                    cout << "Options: " << splitOpt << "\n";
                    token++;
                    
                } else {
                    splitCom = userCommand.substr(0, dash);
                    
                    cout << "Command: " << splitCom << "\n";
                    token++;
                    
                    splitOpt = userCommand.substr(dash, fullstop - dash);
                    
                    cout << "Options: " << splitOpt << "\n";
                    token++;
                    
                    splitArg = userCommand.substr(fullstop, commandSize - 1);
                    
                    cout <<"Arguments: " << splitArg << "\n";
                    token++;
                    
                }
                cout << "the number of tokens is " << token << ", the command name is " << splitCom << endl;;
                break;
                
            case 2:
                token = 0;
                
                if(greaterthan == -1) {
                    splitCom = userCommand.substr(0, lessthan);
                    
                    cout << "Command: " << splitCom << "\n";
                    token++;
                    
                    if(dash > -1) {
                        splitOpt = userCommand.substr(dash, lessthan - dash);
                        
                        cout << "Options: " << splitOpt << "\n";
                        token++;
                        
                    }
                    
                    cout<<"File Redirection: "<<userCommand.at(lessthan)<<endl;
                    token++;
                    
                    splitArg = userCommand.substr(lessthan+1, commandSize - 1);
                    
                    cout<<"FILE: " << splitArg << "\n";
                    token++;
                    
                    
                }
                
                if(lessthan == -1) {
                    splitCom = userCommand.substr(0, greaterthan);
                    
                    cout << "Command: " << splitCom << "\n";
                    token++;
                    
                    if(dash > -1) {
                        splitOpt = userCommand.substr(dash, greaterthan - dash);
                        
                        cout << "Options: " << splitOpt << "\n";
                        token++;
                        
                    }
                    
                    cout<<"File Redirection: "<<userCommand.at(greaterthan)<<endl;
                    token++;
                    
                    splitArg = userCommand.substr(greaterthan+1, commandSize - 1);
                    
                    cout<<"FILE: " << splitArg << "\n";
                    token++;
                    
                }
                cout << "the number of tokens is " << token << ", the command name is " << splitCom << endl;;
                break;
                
            case 3:
                token = 0;
                
                posOfLess2 = userCommand.find('|');
                
                
                if(dash > -1) {
                    
                    posOfLess2 = userCommand.find('|');
                    
                    com1 = userCommand.substr(0, dash);
                    
                    cout << "Command: " << com1 << "\n";
                    token++;
                    
                    splitOpt = userCommand.substr(dash, posOfLess2 - dash);
                    
                    cout << "Options: " << splitOpt << "\n";
                    token++;
                    
                }
                std::cout<<"Special Character: "<<userCommand.at(posOfLess2)<<endl;
                token++;
                
                if(lessthan > -1) {
                    cout<<"File Redirection: "<<userCommand.at(lessthan)<<endl;
                    token++;
                    
                    splitArg = userCommand.substr(lessthan+1, commandSize - 1);
                    
                    cout<<"FILE: " << splitArg << "\n";
                    token++;
                    
                }
                if(greaterthan > -1) {
                    cout<<"File Redirection: "<<userCommand.at(greaterthan)<<endl;
                    token++;
                    
                    
                    splitArg = userCommand.substr(greaterthan+1, commandSize - 1);
                    
                    cout<<"FILE: " << splitArg << "\n";
                    token++;
                    
                }
                cout << "the number of tokens is " << token << ", the command name is " << com1 << endl;;
                
                break;
                
            case 4:
                token = 0;
                
                posOfLess2 = userCommand.find('|');
                
                if(greaterthan > lessthan ) {
                    splitCom = userCommand.substr(0, lessthan);
                    
                    cout << "Command: " << splitCom << "\n";
                    token++;
                    
                }
                if(dash > -1) {
                    splitOpt = userCommand.substr(dash, lessthan - dash);
                    
                    cout << "Options: " << splitOpt << "\n";
                    token++;
                    
                }
                
                cout<<"File Redirection: "<<userCommand.at(lessthan)<<endl;
                token++;
                
                splitArg = userCommand.substr(lessthan+1, posOfLess2 - 1);
                
                cout<<"Special Character: "<<userCommand.at(posOfLess2)<<endl;
                token++;
                
                
                if(dash > -1) {
                    splitOpt = userCommand.substr(dash, greaterthan - dash);
                    
                    cout << "Options: " << splitOpt << "\n";
                    token++;
                    
                }
                if(greaterthan > -1) {
                    cout<<"File Redirection: "<<userCommand.at(greaterthan)<<endl;
                    token++;
                    
                    splitArg = userCommand.substr(greaterthan+1, commandSize - 1);
                    
                    cout<<"FILE: " << splitArg << "\n";
                    token++;
                    
                }
                cout << "the number of tokens is " << token << ", the command name is " << splitCom << endl;;
        }
        
        cout << "\nEnter the userCommand or QUIT to exit"<<endl;
        
        cout<<"<< ";
        
        getline(cin,userCommand);
        
    }
    
    //exit
    
    cout<<"Exiting!!"<<endl;
    
    return 0;
    
}
