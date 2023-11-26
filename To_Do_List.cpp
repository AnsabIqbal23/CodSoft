#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int maxTasks = 10;

struct Task
{
    string description;
    bool completed;
};

class TodoList
{
private:
    Task tasks[maxTasks];
    int taskCount;

public:
    TodoList() : taskCount(0) {}

    void addTask(const string &description)
    {
        if (taskCount < maxTasks)
        {
            Task newTask;
            newTask.description = description;
            newTask.completed = false;
            tasks[taskCount++] = newTask;
            cout << "Task added successfully!\n";
        }
        else
        {
            cout << "Task list is full. Cannot add more tasks.\n";
        }
    }

    void viewTasks() const
    {
        cout << "Tasks:\n";
        cout << "ID   Description              Status\n";
        cout << "-------------------------------------\n";

        for (int i = 0; i < taskCount; ++i)
        {
            cout << i + 1 << "    ";
            cout << left << setw(25) << tasks[i].description;
            cout << (tasks[i].completed ? "Completed" : "Pending") << endl;
        }
    }

    void markTaskAsCompleted(int taskId)
    {
        if (taskId >= 1 && taskId <= taskCount)
        {
            tasks[taskId - 1].completed = true;
            cout << "Task marked as completed!\n";
        }
        else
        {
            cout << "Invalid task ID!\n";
        }
    }

    void removeTask(int taskId)
    {
        if (taskId >= 1 && taskId <= taskCount)
        {
            for (int i = taskId - 1; i < taskCount - 1; ++i)
            {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            cout << "Task removed successfully!\n";
        }
        else
        {
            cout << "Invalid task ID!\n";
        }
    }
};

int main()
{
    TodoList todoList;

    while (true)
    {
        cout << "\n===== Todo List Manager =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string description;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            todoList.addTask(description);
        }
        break;
        case 2:
            todoList.viewTasks();
            break;
        case 3:
        {
            int taskId;
            cout << "Enter task ID to mark as completed: ";
            cin >> taskId;
            todoList.markTaskAsCompleted(taskId);
        }
        break;
        case 4:
        {
            int taskId;
            cout << "Enter task ID to remove: ";
            cin >> taskId;
            todoList.removeTask(taskId);
        }
        break;
        case 5:
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}