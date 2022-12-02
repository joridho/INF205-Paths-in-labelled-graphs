// Created by Martin Thomas Horsch, associate professor at intitute for data science, 
// faculty of science and technology, NMBU
// written with the following license: https://creativecommons.org/licenses/by-nc-sa/4.0/

// Some comments were added to the whole code, but nothing else were altered. 

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <set>
#include <string>


#include "query.h"

/*
 * Memory management rule for the classes below: 
 * It is the graph (Graph) object that has ownership over all its nodes and edges.
 * Nodes and edges just access non-owning pointers to each other; they never need to delete each other directly.
 */
namespace graph
{
   class Edge;  // needs to be declared before we can use it in class Node
   
   /*
   * Declaration of class Node which assaigns a string label to the node,
   * and makes two functions that creates incoming and outgoing edges. 
   * These combinations of nodes and edges are unique and can not be changed.
   */
   class Node
   {
   public:
      Node() {}  // default constructor

      // setting labels to the node-instance 
      Node(std::string in_label) { this->set_label(in_label); } 
      std::string get_label() const { return this->label; } 
      void set_label(std::string in_label) { this->label = in_label; }
      
      // get incoming and outgoing edges
      std::set<Edge*> get_incoming_edges() const { return this->incoming; }
      std::set<Edge*> get_outgoing_edges() const { return this->outgoing; }

      // The incoming edge is appended to the incoming set, and the same for outgoing 
      void append_incoming_edge(Edge* e) { this->incoming.insert(e); }  // using Edge class 
      void append_outgoing_edge(Edge* e) { this->outgoing.insert(e); }
      
      void detach_edge(Edge* e);  // remove an edge from the incidence list(s)  ( the incoming og outgoing set )
      
   private:
      std::string label = "";  // in this implementation, nodes have a string label taken to be their unique name
      std::set<Edge*> incoming = std::set<Edge*>();
      std::set<Edge*> outgoing = std::set<Edge*>();
   };
   

   /*
   * Declaration of class Edge, which decides which nodes that are
   * targets and sources. The class also prints the start and end nodes
   * for different paths in the terminal.
   */
   class Edge
   {
   public:
      Edge() {}  // default constructor

      // creating an Edge instance for the the Edge class. It is immidiatly given start and end nodes, in addition to a label
      Edge(Node* na, std::string in_label, Node* nb) {
         this->set_nodes(na, nb);
         this->set_label(in_label);
      }

      // A label variable is retrieved and then set 
      std::string get_label() const { return this->label; }
      void set_label(std::string in_label) { this->label = in_label; }
      
      // the source and target label for the edge is retrieved 
      std::string get_source_label() const { return this->source->get_label(); }
      std::string get_target_label() const { return this->target->get_label(); }

      // the source and target for the edge is retrieved, later used in get_source_label() and get_target_label()
      void set_nodes(Node* na, Node* nb) {
         this->source = na;
         this->target = nb;
      }

      // if there is a source or a target it is detached from the edge 
      void detach_from_nodes() {
         if(source) this->source->detach_edge(this);
         if(target) this->target->detach_edge(this);
      }
      
      // write to *target
      void out(std::ostream* target) const {
         *target << "<" << this->get_source_label() << ">\t"
                 << "<" << this->label << ">\t<" << this->get_target_label() << ">\n";
      }
      
      // querying DFS helper method. Takes in query, q_rel_it, source_label and out(what is going to be printed in terminal)
      void conditional_dfs(Query* q, std::vector<std::string>::iterator q_rel_it, std::string source_label, std::ostream* out);

   private:
      std::string label = "";  // the edge label is _not_ a unique identifier! (as opposed to node labels which are unique)
      Node* source = nullptr;  // edge connects *source to *target and vice versa
      Node* target = nullptr;  // if it was a directed graph, we might call them "source" and "target"
   };


   // The graph is what hold ownerships of all the nodes and edges 
   class Graph
   {
   public:
      Graph() {}
      
      // return pointer to the node with given label if it exists, nullptr otherwise
      // Creates an instance of node class using find_node with a given node label. 

      // nodes is a map, the first (key) is the given node label (string) and the second (value) is the pointer
      // which is found using nodes.find(node_label)

      //The pointer is returned. If it does not have a label a nullptr is returned 
      Node* find_node(std::string node_label) {
         auto iter = this->nodes.find(node_label);
         if(iter == this->nodes.end()) return nullptr;
         else return &(iter->second);
      }


      // an edge is created using source, edge and target labels 
      void create_edge(std::string source_label, std::string edge_label, std::string target_label);
      
      // create new node with given label, if non-existing
      void create_node(std::string node_label) {
         if(!this->find_node(node_label)) this->nodes[node_label] =  Node(node_label);
      }
      
      // erases any existing edges from node labelled source_label to node labelled target_label
      // returns true if such an edge existed, false otherwise
      bool erase_edge(std::string source_label, std::string target_label);
      
      // erases the node labelled source_label, if it exists
      // returns true if such a node existed, false otherwise
      bool erase_node(std::string node_label);
      
      // read from *source. istream is _input_ stream 
      void in(std::istream* source) {
         while(this->generate_edge_from(source)) {}  // read edge by edge, until generate_edge_from returns false
      }
      // write to *target. ostream is _output_ stream 
      // the for-loop reads everything from the beginning of the edge to the end of the edge and wrrites it out to the target
      void out(std::ostream* target) const {
         for(auto iter = this->edges.begin(); iter != this->edges.end(); iter++)
            (*iter)->out(target);  // output edge by edge
         *target << "<>\n";  // format: empty label for end of content
      }
      

      // destructor:
      // deallocate objects subject to manual memory management that are owned by this object
      ~Graph();
      
      // copy constructor:
      // needed for "deep copy" of owned properties subject to manual memory management
      Graph(const Graph& original);
      
      // overloaded copy assignment operator:
      // similar to the copy constructor, but used in case where this object is already constructed
      Graph& operator=(const Graph& right_hand_side);
      
      // move constructor:
      // "this" is getting constructed while at the same time "old" is deallocated
      Graph(Graph&& old);
      
      // overloaded move assignment operator:
      // used for an assignment where "this" already exists and "old" is a rhs term to be deallocated
      Graph& operator=(Graph&& old);
      
      // apply query, write to out
      void query(Query* q, std::ostream* out);
      
   private:
      // for this implementation, node labels are unique, and we identify nodes through their labels
      // hence it makes sense to use an STL map with the label as the key and the node (pointer) as the value
      std::map<std::string, Node> nodes = std::map<std::string, Node>();
      
      // one possible solution: edges on the heap, owned by the graph object, accessed through a set of pointers
      std::set<Edge*> edges = std::set<Edge*>();
      
      bool generate_edge_from(std::istream* source);  // create a single edge based on information from the stream
      void consistent_edge_deallocation(Edge* e);  // helper function for deallocating edges
   };
}

/*
 * I/O stream operator overloading for Graph
 */
std::istream& operator>>(std::istream& is, graph::Graph& g);
std::ostream& operator<<(std::ostream& os, const graph::Graph& g);

/*
 * I/O stream operator overloading for Edge
 */
std::ostream& operator<<(std::ostream& os, const graph::Edge& e);

#endif
