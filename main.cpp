#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<string> nameList;
  vector<string>::const_iterator iter;
  int selection;
  int changeSelection;
  int deleteSelection;
  int count;
  string name;
  string oldName;
  string newName;
  string deletedName;

  do
  {
    cout << "Make a selection:\n";
    cout << "1) Add a name\n";
    cout << "2) Change name\n";
    cout << "3) Delete name\n";
    cout << "4) Show names\n";
    cout << "5) Quit\n";
    cin >> selection;
    if(selection == 1)
    {
      cout << "Enter the name to add:\n";
      cin >> name;
      nameList.push_back(name);
      cout << name << " was added to the list\n\n";
    }
    else if(selection == 2)
    {
      if(nameList.empty())
      {
        cout << "The list is empty\n\n";
      }
      else
      {
        cout << "Select a name you want to change:\n";
        count = 1;
        for(iter = nameList.begin(); iter < nameList.end(); ++iter)
        {
          cout << count << ") " << *iter << endl;        
          ++count;
        }
        cin >> changeSelection;
        if(changeSelection < 1 || changeSelection > nameList.size())
        {
          cout << "Invalid option\n\n";
        }
        else
        {
          oldName = nameList[changeSelection -1];
          cout << "Enter the updated name:\n";
          cin >> newName;
          nameList[changeSelection - 1] = newName;
          cout << oldName << " has been updated to " << newName << "\n\n";
        }
      }
    }
    else if(selection == 3)
    {
      if(nameList.empty())
      {
        cout << "The list is empty\n\n";
      }
      else
      {
        cout << "Select a name to delete:\n";
        count = 1;
        for(iter = nameList.begin(); iter < nameList.end(); ++iter)
        {
          cout << count << ") " << *iter << endl;        
          ++count;
        }
        cin >> deleteSelection;

        if(deleteSelection < 1 || deleteSelection > nameList.size())
        {
          cout << "Invalid option\n\n";
        }
        else
        {
          deletedName = nameList[deleteSelection - 1];
          nameList.erase(nameList.begin() + (deleteSelection - 1));
          cout << deletedName << " has been deleted.\n\n";
        }

      }     
    }
    else if(selection == 4)
    {
      if(nameList.empty())
      {
        cout << "The list is empty\n\n";
      }
      else
      {
        for(iter = nameList.begin(); iter < nameList.end(); ++iter)
        {
          cout << *iter << endl;
        }
      }
      cout << "\n";
    }
    else if(selection == 5)
    {
      cout << "Thank you for playing!\n";
    }
    else
    {
      cout << "Invalid option.\n\n";
    }
  }while(selection != 5);
  return 0;
}