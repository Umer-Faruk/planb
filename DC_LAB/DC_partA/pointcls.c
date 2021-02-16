#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int cluster[4][2] = {{75, 25}, {25, 25}, {25, 75}, {65, 65}};

int datapoints[5][2] = {{58, 78}, {45, 87}, {98, 87}, {99, 79}, {75, 1}};
 

double get_distance(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1, dy = y2 - y1;
    return ((double)sqrt(dx * dx + dy * dy));
}

void classify_points()
{
    long i;
    int j, cluster_index;
    double cur_dist = 0, min_dist = 999;
#pragma omp parallel for private(cluster_index, j, i, cur_dist, min_dist)
    for (i = 0; i < 5; i++)
    {

        cluster_index = -1;
        cur_dist = 0, min_dist = 999;
        for (j = 0; j < 4; j++)
        {
            cur_dist = get_distance(datapoints[i][0], datapoints[i][1], cluster[j][0], cluster[j][1]);
            if (cur_dist < min_dist)
            {
                min_dist = cur_dist;
                cluster_index = j;
            }
        }
        printf("%d %d belongs to %d %d == cluster %d \n", datapoints[i][0], datapoints[i][1], cluster[cluster_index][0], cluster[cluster_index][1], cluster_index);
        
    }
}

void main()
{

    
 
     classify_points();

    // double t1 = omp_get_wtime();
    // classify_points();
    // double t2 = omp_get_wtime();
    // printf("Time taken %lf\n", t2 - t1);
}