#include <iostream>
#include "TaskRepository.h"
#include <cassert>

int main() {
    Duration d1 = Duration(76, 'm');
    Duration d2 = Duration();
    Duration d3 = Duration(1, 'h');

    assert(d1.getSeconds() == 76*60);
    assert(d1.get('h') == 1);

    assert(d2.getSeconds() == 0);

    Duration total_time = d3 + d1;
    assert(total_time.get('h') == 2);

    total_time = d1 - d3;
    assert(total_time.get('m') == 16);


    TaskRepository repo = TaskRepository(4);
    repo.add_Task(task(1, d1));
    assert(repo.time_needed().getSeconds() == d1.getSeconds());
    repo.print(';');
    repo.delete_all();
    assert(repo.time_needed().getSeconds() == 0);
    repo.add_Task(task(2, d3));
    repo.add_Task(task(1, d1));
    assert(repo.count_tasks_between(d2, d3) == 1);
    std::cout << "All tests passed!";

}