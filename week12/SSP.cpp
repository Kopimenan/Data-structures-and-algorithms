#include<iostream>
#include<stdio.h>
using namespace std;
#define INFINITY 1e9
#define max 6

void dijkstra(int Graph[max][max], int startnode);

int main(){
int Graph[max][max]={{ 0,10, 0, 0,15, 5},
                     {10, 0,10,30, 0, 0},
                     { 0,10, 0,12, 5, 0},
                     { 0,30,12, 0, 0,20},
                     {15, 0, 5, 0, 0, 0},
                     { 5, 0, 0,20, 0, 0}};
   
    int source=5;

    dijkstra(Graph,source);
    return 0;
}

void dijkstra(int Graph[max][max], int startnode)
{
    int cost[max][max], distance[max], pred[max];
    int visited[max], count, mindistance, nextnode, i, j;

    // Initialize the cost matrix and distance array
    for(i = 0; i < max; i++)
        for(j = 0; j < max; j++)
            if(Graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];

    for(i = 0; i < max; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while(count < max - 1)
    {
        mindistance = INFINITY;

        for(i = 0; i < max; i++)
            if(distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        for(i = 0; i < max; i++)
            if(!visited[i])
                if(mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }

        count++;
    }

    // Print the shortest distance and path to each node
    for(i = 0; i < max; i++)
        if(i != startnode)
        {
            cout << "Distance from node " << startnode << " to node " << i << " is: " << distance[i] << endl;

            cout << "Path: " << i;
            j = i;
            do
            {
                j = pred[j];
                cout << " <- " << j;
            } while(j != startnode);
            cout << endl;
        }
}
