#include <bits/stdc++.h>

using namespace std;

class Vertex
{
public:
    int id;
    vector<int> adjList;
    vector<double> adjWeights;
};

double shortestPath(vector<Vertex> &vertices, int src,int destination)
{
    int N = vertices.size() - 1;

    vector<double> distTo(N + 1,1e9);
    vector<double> edgeTo(N + 1,1e9);

    for (int i = 1; i <= N; i++)
    {
        distTo[i] = 1e9;
    }

    distTo[src] = 0.0;
    edgeTo[src] = 1e9;

    priority_queue<pair<double, int>,vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push(make_pair(0.0, src));

    while (!pq.empty())
    {
        pair<double, int> top = pq.top();
        pq.pop();
        int closest = top.second;

        for (int i = 0;
             i < vertices[closest].adjList.size(); i++)
        {
            int neighbor = vertices[closest].adjList[i];
            double weight = vertices[closest].adjWeights[i];
            if (weight < edgeTo[closest] && distTo[closest] + weight < distTo[neighbor])
            {
                edgeTo[neighbor] = weight;
                distTo[neighbor] = distTo[closest] + weight;
                pq.push(
                    make_pair(distTo[neighbor], neighbor));
            }
        }
    }

    double firstPass = distTo[destination];


    for (int i = 1; i <= N; i++)
    {
        distTo[i] = numeric_limits<double>::max();
    }

    distTo[src] = 0.0;
    edgeTo[src] = 0.0;

    pq.push(make_pair(0.0, src));

    while (!pq.empty())
    {

        pair<double, int> top = pq.top();
        pq.pop();
        int closest = top.second;

        for (int i = 0;
             i < vertices[closest].adjList.size(); i++)
        {
            int neighbor = vertices[closest].adjList[i];
            double weight = vertices[closest].adjWeights[i];

   
            if (weight > edgeTo[closest] && distTo[closest] + weight < distTo[neighbor])
            {
                edgeTo[neighbor] = weight;
                distTo[neighbor] = distTo[closest] + weight;
                pq.push(
                    make_pair(distTo[neighbor], neighbor));
            }
        }
    }


    double secondPass = distTo[destination];

    if (firstPass == DBL_MAX && secondPass == DBL_MAX)
        return -1;

    return min(firstPass, secondPass);
}


int main()
{
    int N , M , src, target;
    cin >> N >> M >> src >> target;

    vector<Vertex> vertices(N + 1);

    for (int i = 1 ; i <= M ; i++){
        int a ,b; cin >> a >> b;
        double c ; cin >> c;
        vertices[a].id = a;
        vertices[a].adjList.push_back(b);
        vertices[a].adjWeights.push_back(c);
    }

    double shortest = shortestPath(vertices, src, target);

    cout << shortest << endl;

    return 0;
}
