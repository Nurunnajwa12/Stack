//Nurunnajwa bt Zulkifli
//A21EC0121

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class nodeStack{
	public:
    char data;
    nodeStack* next; 
};


class stack{

    nodeStack* top;
    public :

	void createstack()
    { 
        
        top = NULL;
    
    }

    bool isEmpty()
    
    { 
        
        return top == NULL; 
    
    }

    void push(char Item)
	{
        nodeStack* newnode = new nodeStack;
        newnode->data = Item;
        newnode->next = top;
        top = newnode;
    }

    void pop()
	{
        if (!isEmpty())
        {
            nodeStack* del = top;
        	top = del->next;
        	delete del;
        }

    }
};

int main(){

    stack astack;
    astack.createstack();
    char ex[100], ch;
    cout << "Please enter an expression : ";
    cin >> ex;
    
    int i;

    for( i = 0 ; i < strlen(ex) ; i++){

        ch = ex[i];
        if( (ch == '(') || (ch == ')') )
		{
            if(ch == '(')
			{
                astack.push(ch);
            }
            else if (astack.isEmpty())
			{
                break;
            }
            else
			{
                astack.pop();
            }
        }
        
    }

    if( (astack.isEmpty()) && i == strlen(ex))
	{
        cout << "The expression is balanced." << endl;
    }
    else
	{
        cout << "The expression is not balanced." << endl;
    }


    system("pause");
    return 0;
}