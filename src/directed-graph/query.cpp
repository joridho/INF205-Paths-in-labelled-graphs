#include "query.h"

using namespace graph;

std::istream& operator>>(std::istream& is, Query& q) {
   q.in(&is);
   return is;
}

/*
 * This bool function reads the information from 'source', then
 * goes through all symbols. It then checks if there are any 
 * symbols that are not empty or contains the symbols '<' or '>'.
 * If there are any symbols that are not as the ones mentioned,
 * the function will return True, and the symbol will be assigned
 * to the pointer, '*token'.
 */
// read an IRI with bracket notation; return false if \0 or empty token was read
bool graph::IRI_input(std::string* token, std::istream* source)
{
   char single_symbol = '\0';
   while(single_symbol != '<')
   {
      source->get(single_symbol);
      if(single_symbol == '\0') return false;  // format: \0 means that we are done
   }
   for(source->get(single_symbol); single_symbol != '>'; source->get(single_symbol))
      *token += single_symbol;
   
   return (*token != "");  // format: empty token means that we are done
}
