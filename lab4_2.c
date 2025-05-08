#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void dfs(char** grid, int i, int j, int gridSize, int gridColSize) 
{
    if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize || grid[i][j] != '1')
        return;
    grid[i][j] = '0'; 
    dfs(grid, i + 1, j, gridSize, gridColSize);
    dfs(grid, i - 1, j, gridSize, gridColSize);
    dfs(grid, i, j + 1, gridSize, gridColSize);
    dfs(grid, i, j - 1, gridSize, gridColSize);
}


int numIslands(char** grid, int gridSize, int* gridColSize) 
{
    if (!grid || gridSize == 0) return 0;
    int count = 0;
    for (int i = 0; i < gridSize; ++i) 
    {
        for (int j = 0; j < gridColSize[i]; ++j) 
        {
            if (grid[i][j] == '1') 
            {
                count++;
                dfs(grid, i, j, gridSize, gridColSize[i]);
            }
        }
    }
    return count;
}


int main() 
{
    int gridSize = 4;
    int colSize = 5;
    int* gridColSize = malloc(sizeof(int) * gridSize);
    for (int i = 0; i < gridSize; ++i) gridColSize[i] = colSize;


    char** grid = malloc(sizeof(char*) * gridSize);
    grid[0] = malloc(colSize + 1); strcpy(grid[0], "11110");
    grid[1] = malloc(colSize + 1); strcpy(grid[1], "11010");
    grid[2] = malloc(colSize + 1); strcpy(grid[2], "11000");
    grid[3] = malloc(colSize + 1); strcpy(grid[3], "00000");

    int islands = numIslands(grid, gridSize, gridColSize);
    printf("Number of islands: %d\n", islands);

    for (int i = 0; i < gridSize; ++i) free(grid[i]);
    free(grid);
    free(gridColSize);

    return 0;
}
