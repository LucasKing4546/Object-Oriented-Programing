//
// Created by Lucas on 5/3/2025.
//

#ifndef SIMULATIONGRID_H
#define SIMULATIONGRID_H

#include "Entity.h"

class SimulationGrid {
private:
    static const int MAX_COLUMNS = 100;
    static const int MAX_ROWS = 100;
    Entity* grid[MAX_ROWS][MAX_COLUMNS];
public:
    SimulationGrid();
    ~SimulationGrid();
    SimulationGrid(const SimulationGrid& other);
    SimulationGrid& operator=(const SimulationGrid& other);
    friend std::istream& operator>>(std::istream& is, const SimulationGrid& simulation_grid);
    friend std::ostream& operator<<(std::ostream& os, const SimulationGrid& simulation_grid);
};

#endif //SIMULATIONGRID_H
