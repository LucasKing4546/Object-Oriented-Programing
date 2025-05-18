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
    std::cout << "Testing TaskRepository" << std::endl;
    std::cout << "Testing add_Task" << std::endl;
    repo.add_Task(task(1, d1));
    assert(repo.time_needed().getSeconds() == d1.getSeconds());
    std::cout << "Testing print" << std::endl;
    repo.print(';');
    std::cout << "Testing delete_all" << std::endl;
    repo.delete_all();
    std::cout << "Testing time_needed" << std::endl;
    assert(repo.time_needed().getSeconds() == 0);
    repo.add_Task(task(2, d3));
    repo.add_Task(task(3, d1));
    std::cout << "Testing count_tasks_between" << std::endl;
    assert(repo.count_tasks_between(d2, d3) == 1);
    std::cout << "All tests passed!";

}