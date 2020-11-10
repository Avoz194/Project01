#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include <queue>
#include "Graph.h"

class Agent;

enum TreeType {
    Cycle,
    MaxRank,
    Root
};

class Session {
public:
    Session(const std::string &path);

    void simulate();

    void addAgent(const Agent &agent);

    void setGraph(const Graph &graph);

    void enqueueInfected(int);

    int dequeueInfected();

    TreeType getTreeType() const;

    Graph &getGraph();
    const int getCycle() const;

    void createOutput();

    const bool isEndOfSess() const;

    //rule of 5
    virtual ~Session(); //destructor
    Session(const Session &other); //copy constructor
    Session(Session &&other); //move constructor
    Session& operator=(const Session &other); //copy assignment
    Session& operator=(Session &&other); //move assignment


private:
    Graph g;
    TreeType treeType;
    int cycle;

    std::vector<Agent *> agents;
    std::vector<Agent *> pendingAgents;
    std::queue<int> infectedQueue;

    void clear();
    void copy(const Graph& other_g, const TreeType& other_treeType, const int& other_cycle, const std::vector<Agent *>& other_agents,
    const std::vector<Agent *>& other_pendingAgents, const std::queue<int>& other_infectedQueue) ;
};

#endif
