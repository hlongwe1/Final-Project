//Harry Longwell
//12/06/2013
//Project3 Sets and other algorithms
//This project tests to see how well we can use all the knowedge that we gathered throughout Discrete this semester

#include <iostream>
#include <vector>

using namespace :: std;

class MySet
{
	std :: vector<int> set;//declaring a set

	public:
		MySet();
		void printSet();
		void SortedSet();
		bool searchSet(int find);
		void printSuperSet();
		void printPowerSet();
		void printSetPerm(int i);
		void SetMod();
};

//Pre Condition: Takes the empty set
//Post Condition: Adds elements to the set until the user end the terminating value
MySet :: MySet()
{
	int input;
	int count = 0;
	cout << "Enter a value ";
	cin >> input;

	while(input != -1)
	{
		count++;
		set.push_back(input);
		cout << "Enter another value(-1 to quit) ";
		cin >> input;
	}
	set.resize(count);//resets size of vector to the number of entered numbers
}

//Pre Condition: Takes in the set
//Post Condition: Prints out the elements of the set
void MySet ::  printSet()
{
	int count = 0;
        int a = set.size();
        cout <<"[";
        while(count != a)//goes through and prints the set
        {
        	if(count != 0)
                {
                	cout << ", ";
                }
                cout << set[count];
                count++;
        }
        cout << "]\n";
}

//Pre condition: Takes in the set
//Post Condition: Arranges the elements into numerical order
void MySet :: SortedSet()
{
	int tmp;
        int count = 1;
        int a = set.size();
        for(int i = 0; i < set.size(); i++)
        {
		for(int a = 0; a < set.size()-1; a++)
		{
	        	if(set[a] > set[a+1])//checks the value of the current element against the value of the next element
	                {
	                	tmp = set[a];
	                        set[a] = set[a+1];
	                        set[a+1] = tmp;
	                }
		}
	}
	printSet();
}

//Pre Condition: Takes the set and a value to search for
//Post Condition: Goes through the set, if the value is found returns true, if not returns false
bool MySet :: searchSet(int find)
{
        for(int i = 0; i != set.size(); i++)
        {
	        if(set[i] == find)
                {
                        return(true);//reutrns true if the value is found
                }
        }
        return(false);
}

//Pre Condition: Takes in the set
//Post Condition: prints out the different permutations of the set
void MySet :: printSetPerm(int i)
{
	int j;
	int tmp;
	int n = set.size();
	if(i == n)
	{
		printSet();
	}
	else
	{
		for(int j = i; j < n; j++)
		{
			tmp = set[i];//swaps elements of the set
			set[i] = set[j];
			set[j] = tmp;
			printSetPerm(i + 1);//recursively calls the function
			tmp = set[j];
                        set[j] = set[i];
                        set[i] = tmp;
		}

	}
}

//Pre Condition: Takes in the set
//Post Condition: Prints out the Super set of the original set
void MySet :: printSuperSet()
{
        int a;
        int b = 0;
        //declared a new vector to be the super set
        std :: vector<int> superset;
        //the loop will go through and add similar values to the super set that were in the original set
        for(int i = 0; i != set.size(); i++)
        {
                a = set[i];
                superset.push_back(a);
                b = b + a; //when the for loop end b will be the value of all the elements added together
        }
        superset.push_back(b+1);//adds b to the super set, making the super set one larger than the orignal set

        //borrowed the print algorithm from the printset method
        int count = 0;
        int c = superset.size();
        cout <<"[";
        while(count != c)
        {
                if(count != 0)
                {
                        cout << ", ";
                }
                cout << superset[count];
                count++;
        }
        cout << "]\n";
}

//Pre Condition: Takes in the set
//Post Condition: Prints out the power set of the original set
void MySet :: printPowerSet()
{
	int i=0;
	int j=0;
        long SetSize =set.size() * set.size();
        cout << "{ }";
	cout << "\n";
        for(i=1; i < SetSize; i++)
	{
        	cout << "{";
                for(j = 0; j < set.size(); j++)
		{
                        if( ( ( i>>j ) & 1 ) == 1)//checking the bitwise operation
			{
                                cout << " " << set[j];
                                if( i != (j - 2) )
				{
                                        cout<<",";
                                }
                        }
                }
                cout << "}\n";
	}
}

//Pre condition: Takes in the set
//Post Condition: finds the mod of the set and prints it
void MySet :: SetMod()
{
	int a;
	int b = 0;

	for(int i = 0; i != set.size(); i++)//find the sum of all the elements of the array
        {
                a = set[i];
                b = b + a;
        }

	int c = b % set.size();//takes the mod of the sum of the set with the number of elements in the set

	cout << "The mod of the set is " << c << "\n";
}

int main()
{
	int choice = 0;
	MySet setA;

	while(choice != -1)
	{
		cout << "|==========================|\n";
		cout << "|   Enter 1 to print set   |\n";
		cout << "|==========================|\n";
	        cout << "| Enter 2 for permutations |\n";
		cout << "|==========================|\n";
	        cout << "|   Enter 3 for super set  |\n";
		cout << "|==========================|\n";
	        cout << "|  Enter 4 for power set   |\n";
		cout << "|==========================|\n";
	        cout << "|  Enter 5 for sorted set  |\n";
		cout << "|==========================|\n";
	        cout << "|  Enter 6 to search set   |\n";
		cout << "|==========================|\n";
		cout << "|  Enter 7 for mod of set  |\n";
		cout << "|==========================|\n";
		cout << "|     Enter -1 to quit     |\n";
		cout << "|==========================|\n";
		cin >> choice;

		if(choice == 1)
		{
			setA.printSet();
		}
		else if(choice == 2)
		{
			setA.printSetPerm(0);
		}
		else if(choice == 3)
		{
			setA.printSuperSet();
		}
		else if(choice == 4)
		{
			setA.printPowerSet();
		}
		else if(choice == 5)
		{
			setA.SortedSet();
		}
		else if(choice == 6)
		{
			int find;
			cout << "What value would you like to search for?\n";
			cin >> find;

			bool test = setA.searchSet(find);

			if(test)
			{
				cout << "The number is in the set\n";
			}
			else
			{
				cout << "The number is not in the set\n";
			}
		}
		else if(choice == 7)
		{
			setA.SetMod();
		}
		else if(choice == -1)
		{
			cout << "Good bye\n";
		}
		else
		{
			cout << "Error Invalid Input\n";
		}
	}
}
