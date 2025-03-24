//
// Created by Lucas on 3/24/2025.
//

#ifndef TASKREPOSITORY_H
#define TASKREPOSITORY_H

#endif //TASKREPOSITORY_H

#include "Duration.h"

struct task{
    int id{};
    Duration duration;
};

class TaskRepository{
private:
    int capacity;
    int length;
    task* array;

public:
    TaskRepository(int cap) {
        capacity = cap;
        length = 0;
        array = nullptr;
    }

    void add_Task(task Task);

    void print(char delimiter);

    Duration time_needed();

    void delete_all();

    int count_tasks_between(Duration min_duration, Duration max_duration);
};
