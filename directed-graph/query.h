#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <vector>

namespace graph
{
   // read an IRI with bracket notation; return false if \0 or empty token was read
   bool IRI_input(std::string* token, std::istream* source);
   

   /*
   Struct that reads files(?), contains a vector of type 'string'.
   relations might be the place where rel is saved
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
