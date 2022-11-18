#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <vector>

namespace graph
{
   // read an IRI with bracket notation; return false if \0 or empty token was read
   bool IRI_input(std::string* token, std::istream* source);
   

   /*
    * Struct that reads an input file and adds each element to 
    * the 'relations' vector until there are no more elements.
    */
   struct Query
   {
      // read from *source
      void in(std::istream* source) {
            std::string rel = "";
            while(graph::IRI_input(&rel, source)) {
               this->relations.push_back(rel);
               rel = "";
            }
      }
      
      std::vector<std::string> relations;
   };
}

std::istream& operator>>(std::istream& is, graph::Query& q);

#endif
